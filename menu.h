#ifndef MENU_H
#define MENU_H

#include "main.h"

extern void animation(LTexture img[], int x, int y, int scale, int delay, int maxframes);

void menu_input(SDL_Event e)
{
	if(UPPRESS) // key up
	{
		
	}
	if(DOWNPRESS) // key down
	{
					
	}
	if(MOUSEBUTTONUP)
	{
		if(MX(r))//r.x,r.y,   r.w,r.h))
			gamestate = level_1_1;
		if(MX(r2))//.x,r2.y, r2.w,r2.h))
			running = false; // quit
		cursorActive = false;
	}
	if(MOUSEBUTTONDOWN)
	{
					
	}
	if(MOUSEMOTION)
	{
		if(MX(r))//r.x,r.y, r.w,r.h))
			cursorActive = true;
		else if(MX(r2))//.x,r2.y, r2.w,r2.h))
			cursorActive = true;
		else
			cursorActive = false;
	}
}

void menu_draw()
{
	animation(image1,0,0,5,12,4);
	//animation(image3,0,0,6,12,2);
}

void menu_debug()
{
#if OUTLINES == 1
	drawOutlineRect( r.x,  r.y,  r.w, r.h, MAGENTA);
	drawOutlineRect(r2.x, r2.y, r2.w,r2.h, MAGENTA);
#endif
}

#endif // MENU_H
