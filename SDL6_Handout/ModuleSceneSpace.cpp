#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{
	
}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/lvl1_background.png");
	

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();

	App->render->camera.y = 0;
	App->player->position.x = (SCREEN_WIDTH / 2) - 16;
	App->player->position.y = SCREEN_HEIGHT - 100;


	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);


	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	App->render->camera.y += 1*SCREEN_SIZE;
	
	// Draw everything --------------------------------------
	App->render->Blit(background, 0, (-3266 + SCREEN_HEIGHT) , NULL);
	
	return UPDATE_CONTINUE;
}