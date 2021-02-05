#include "pch.h"

struct GenericDataTypes
{
	const char* name;
	int         amount;
} static const

item[] =
{
	{"silver",12},	{"copper",2},	{"gold",300},
},
inv[] =
{
	{"silver",12},	{"copper",2},	{"gold",300},
};

struct ItemHoldings
{
	int copper;
	int silver;
	int gold;
	int stick;
};

struct Player
{
	int x,y;
	int money;
	ItemHoldings item;
};

struct Chest
{
	int index;
	int x, y;
	bool open;
	bool death;
} static const
chest[] =
{
	{0,0,0,0,0},
	{1,0,1,0,0},
	{2,1,0,0,0},
	{3,1,1,0,0},
	{4,2,0,0,0},
	{5,2,0,0,0},
};

bool loadMedia()
{
	bool success = true;
	
	loading();
	
	return success;
}

void animation(LTexture img[], int x, int y, int scale, int delay, int maxframes)
{
	static int frame = 1;
	static int counter = -1;

	if(counter >= delay)
	{
		counter = -1;
		frame++;
	}
	if(frame > maxframes)
		frame = 1;
	
	counter++;
	
	for(int i = 0; i < maxframes; i++)
		if(frame == i+1)
			img[i].render(x,y,scale,scale);
}

void Cursor()
{
	SDL_ShowCursor(SDL_DISABLE); //hide cursor
	
	int mx, my;
	SDL_GetMouseState(&mx,&my);

	//drawFillRect(mx,my,20,20,RED);

	int x, y;
	x = 9;
	y = 8;
	if(cursorActive)
	{
		if(handisdown)
			handdown.render(mx-x,my-y,3,3);
		else
			handup.render(mx-x,my-y,3,3);
	}
	else
		cursor.render(mx,my,3,3);
}

int main(int argc, char* args[])
{
	init_Window(300,200,SCREEN_WIDTH,SCREEN_HEIGHT,FULLSCREEN); //960 600
	
	loadMedia();

	std::ofstream outpufile;
	std::ofstream inpufile;
	
	while(running)
	{
		while(POLLEVENT)
		{
			if(QUIT){ exit(0); }

			// GLOBAL
			if(UPPRESS) // key up
			{
				if(ESCAPE){running = false;     }
				if(LEFT  || D_KEY){ gamestate--;}
				if(RIGHT || F_KEY){ gamestate++;}
				if(UP    || W_KEY){}
				if(DOWN  || S_KEY){}
				
				if(P_KEY) {}
				
				// MUSIC
				if(ONE)  { Mix_PlayChannel(-1,gHigh,   0);}
				if(TWO)  { Mix_PlayChannel(-1,gMedium, 0);}
				if(THREE){ Mix_PlayChannel(-1,gLow,    0);}
				if(FOUR) { Mix_PlayChannel(-1,gScratch,0);}
				if(NINE)
				{
					if(Mix_PlayingMusic() == 0)
						Mix_PlayMusic(gMusic,-1);
					else
					{
						if(Mix_PausedMusic() == 1)
							Mix_ResumeMusic();
						else
							Mix_PauseMusic();
					}
				}
				if(ZERO) // Stop the music
				{
					Mix_HaltMusic();
				}
				// !MUSIC
			}
			if(DOWNPRESS) // key down
			{

#if OUTLINES == 1
				if(LEFT  || D_KEY) { testingx--;}
				if(RIGHT || F_KEY) { testingx++;}
				if(UP    || W_KEY) { testingy--;}
				if(DOWN  || S_KEY) { testingy++;}
#endif
			}
			
			if(MOUSEBUTTONDOWN){ handisdown = true;}
			if(MOUSEBUTTONUP)  { handisdown = false;}
			if(MOUSEMOTION){}//int x = e.motion.x; int y = e.motion.y; printf("%i %i\n", x,y);}
			
			if(gamestate ==  menu_1_1){ menu_input(e);    }
			if(gamestate == level_1_1){ level_1_input(e); }
			if(gamestate == level_1_2){ level_2_input(e); }

		}

///////////////////////////////////////////////////
		
		SDL_SetRenderDrawColor(renderer,BLACK);
		SDL_RenderClear(renderer);
		
#if OUTLINES == 1
		printf("%i\n",testingx);
		printf("%i\n",testingy);
#endif
		
		if(gamestate <=  menu_1_1){ gamestate = menu_1_1; } if(gamestate >= level_1_9){ gamestate = level_1_9;}

		if(gamestate ==  menu_1_1){ menu_draw();menu_debug();      }
		if(gamestate == level_1_1){ level_1_draw();level_1_debug();}
		if(gamestate == level_1_2){ level_2_draw();level_2_debug();}
		
		if(gamestate == level_1_3){ image4_1.render(0,0,6,6);}
		if(gamestate == level_1_4){ image5_1.render(0,0,6,6);}
		if(gamestate == level_1_5){ image6_1.render(0,0,6,6);}
		if(gamestate == level_1_6){ image7_1.render(0,0,6,6);}
		if(gamestate == level_1_7){ image8_1.render(0,0,6,6);}
		if(gamestate == level_1_8){ image9_1.render(0,0,3,3);}
		if(gamestate == level_1_9){ image9_1.render(0,0,3,3);}
			
		Cursor(); //draws cursor

		SDL_Delay(1000/33);
		SDL_RenderPresent(renderer);
	}
	
	Close();
	return(0);
}

void Close()
{
	//Free images
	image1[0].free();
	image1[1].free();
	image1[2].free();

	image2_1.free();
	
	image3[0].free();
	image3[1].free();
	
	image4_1.free();
	image5_1.free();
	image6_1.free();
	image7_1.free();
	image8_1.free();
	image9_1.free();

	//Free the sound effects
	Mix_FreeChunk( gScratch );
	Mix_FreeChunk( gHigh );
	Mix_FreeChunk( gMedium );
	Mix_FreeChunk( gLow );
	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;
	
	//Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;
	
	Mix_Quit();
	IMG_Quit();
	
	destroy_Window();
}
