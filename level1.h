#ifndef LEVEL1_H
#define LEVEL1_H

#include "pch.h"

void level_1_input(SDL_Event e)
{
	Region w = {0,0,1440,900};
	if(MOUSEBUTTONDOWN)
		if(MX(w))
			gamestate = level_1_2;
}

void level_1_draw()
{
	image2_1.render(0,0,5,5);
}

void level_1_debug()
{
	
}
#endif // LEVEL1_H
