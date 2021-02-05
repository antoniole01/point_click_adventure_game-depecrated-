#ifndef LEVEL2_H
#define LEVEL2_H

#include "pch.h"

void level_2_input(SDL_Event e)
{
	if(UPPRESS) // key up
	{
		if(SPACE)
		{
			
		}
	}
	if(DOWNPRESS) // key down
	{
					
	}
	if(MOUSEBUTTONUP)
	{
		if(door1open)
		{
			if(MX(d1_close))
			{
				door1open = !door1open;
				if(!door1open)
				{
					//door1enter = true;
				}
			}
						
			if(MX(d1_open))
			{
				Mix_PlayChannel(-1,closedoor,0);
				door1open = !door1open;
			}
		}
		else // closed
		{
			
			if(MX(d1_close))
			{
				Mix_PlayChannel(-1,opendoor,0);
							
				door1open = !door1open;
				if(!door3open)
				{
					//door1enter = true;
				}
			}
		}
		
		if(door2open)
		{
			if(MX(d2_close))
			{
				door2open = !door2open;
				if(!door2open)
				{
					//door1enter = true;
				}
			}
						
			if(MX(d2_open))
			{
				Mix_PlayChannel(-1,closedoor,0);
				door2open = !door2open;
			}
		}
		else // closed
		{
			
			if(MX(d2_close))
			{
				Mix_PlayChannel(-1,opendoor,0);
							
				door2open = !door2open;
				if(!door2open)
				{
					//door2enter = true;
				}
			}
		}

		if(door3open)
		{
			if(MX(d3_close))
			{
				door3open = !door3open;
				if(!door3open)
					door1enter = true;
			}
						
			if(MX(d3_open))
			{
				Mix_PlayChannel(-1,closedoor,0);
				door3open = !door3open;
			}
		}
		else // closed
		{
			if(MX(d3_close))
			{
				Mix_PlayChannel(-1,opendoor,0);
							
				door3open = !door3open;
				if(!door3open)
					door3enter = true;
			}
		}

		if(door4open)
		{
			if(MX(d4_close))
			{
				door4open = !door4open;
				if(!door4open)
				{
					//door1enter = true;
				}
			}
						
			if(MX(d4_open))
			{
				Mix_PlayChannel(-1,closedoor,0);
				door4open = !door4open;
			}
		}
		else // closed
		{
			if(MX(d4_close))
			{
				Mix_PlayChannel(-1,opendoor,0);
							
				door4open = !door4open;
				if(!door4open)
				{
					//door4enter = true;
				}
			}
		}
		if(MX(secret1))
			secret = true;
	}
	if(MOUSEBUTTONDOWN)
	{
					
	}
	if(MOUSEMOTION)
	{
		
		if     (MX(d1_close)) { cursorActive = true;}
		else if(MX(d2_close)) { cursorActive = true;}
		else if(MX(d3_close)) { cursorActive = true;}
		else if(MX(d4_close)) { cursorActive = true;}
		
		else if(door1open && MX(d1_open)) { cursorActive = true;}
		else if(door2open && MX(d2_open)) { cursorActive = true;}
		else if(door3open && MX(d3_open)) { cursorActive = true;}
		else if(door4open && MX(d4_open)) { cursorActive = true;}

		else if(secret == false && MX(secret1)) { cursorActive = true;}
		
		else cursorActive = false;
		
	}
}

void level_2_draw()
{
	printf("%i %i %i %i\n",door1open,door2open,door3open,door4open);
	
	image3[0].render(0,0,5,5);	//background

	//                      close              g                                open
	if(secret)     image3[10].render(325,100,5,5);
	
	if(door1open == false){ image3[6].render(d1_close.x,d1_close.y,5,5);}else{ image3[2].render(d1_open.x,d1_open.y,5,5);}
	if(door2open == false){ image3[7].render(d2_close.x,d2_close.y,5,5);}else{ image3[3].render(d2_open.x,d2_open.y,5,5);}
	if(door3open == false){ image3[8].render(d3_close.x,d3_close.y,5,5);}else{ image3[4].render(d3_open.x,d3_open.y,5,5);}
	if(door4open == false){ image3[9].render(d4_close.x,d4_close.y,5,5);}else{ image3[5].render(d4_open.x,d4_open.y,5,5);}
	
	if(door1enter) gamestate = level_1_3;//enter
	
}

void level_2_debug()
{
#if OUTLINES == 1
	
	drawOutlineRect(bounds(d1_open),  MAGENTA);
	drawOutlineRect(bounds(d1_close), MAGENTA);
	drawOutlineRect(bounds(d2_open),  MAGENTA);
	drawOutlineRect(bounds(d2_close), MAGENTA);
	drawOutlineRect(bounds(d3_open),  MAGENTA);
	drawOutlineRect(bounds(d3_close), MAGENTA);
	drawOutlineRect(bounds(d4_open),  MAGENTA);
	drawOutlineRect(bounds(d4_close), MAGENTA);
	drawOutlineRect(bounds(secret1),  MAGENTA);
	
#endif
}

#endif // LEVEL2_H
