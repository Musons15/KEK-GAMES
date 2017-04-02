#ifndef __MODULEINTRO_H__
#define __MODULEINTRO_H__

#include "Module.h"

struct SDL_Texture;

class ModuleIntro : public Module
{
public:
	ModuleIntro();
	~ModuleIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_texture = nullptr;
	SDL_Rect background;
};

#endif // __MODULESCENESPACE_H__