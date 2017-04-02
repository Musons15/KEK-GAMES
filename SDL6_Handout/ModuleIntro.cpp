#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"


ModuleIntro::ModuleIntro()
{
	background.x = 0;
	background.y = 0;
	background.h = SCREEN_HEIGHT;
	background.w = SCREEN_WIDTH;
}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading space scene");

	background_texture = App->textures->Load("rtype/intro.png");
	

	return true;
}

// UnLoad assets
bool ModuleIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background_texture);

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	// Move camera forward -----------------------------
	

	// Draw everything --------------------------------------
	App->render->Blit(background_texture, 0, 0, &background, NULL);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(this, App->scene_space, 0.8f);
		App->player->Enable();
	}

	return UPDATE_CONTINUE;
}