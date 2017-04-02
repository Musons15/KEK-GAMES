#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"



ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 150;
	position.y = 3200;

	// idle animation (just the ship)
	idle.PushBack({259, 54, 82, 101});

	// move right
	right.PushBack({361, 52, 75, 102});
	right.PushBack({467, 52, 75, 102});
	right.loop = false;
	right.speed = 0.1f;

	// Move down
	left.PushBack({ 163, 52, 75, 102 });
	left.PushBack({70, 52, 75, 102});
	left.loop = false;
	left.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/space_ship.png");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 5;

	if(App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
	}

	if(App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
	}

	if(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if(current_animation != &left)
		{
			left.Reset();
			current_animation = &left;
		}
	}

	if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if(current_animation != &right)
		{
			right.Reset();
			current_animation = &right;
		}
	}

	// TODO 3: Shoot lasers when the player hits SPACE
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 15, position.y + 10);
		App->particles->AddParticle(App->particles->laser, position.x + 55, position.y + 10);
	}

	if(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
	   && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	// Draw everything --------------------------------------

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}