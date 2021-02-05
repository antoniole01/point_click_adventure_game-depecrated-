#ifndef MAIN_H
#define MAIN_H

#include "pch.h"

#undef main

SDL_Window*		window = NULL;
SDL_Renderer*	renderer = NULL;
SDL_Event e;

SDL_Texture*	solidTexture;
SDL_Texture*	text;
SDL_Rect			solidRect;
TTF_Font*		gFont = NULL;

//The music that will be played
Mix_Music *gshortmus = NULL;
Mix_Chunk *closedoor     = NULL;
Mix_Chunk *opendoor     = NULL;

Mix_Music *gMusic    = NULL;

//The sound effects that will be used
Mix_Chunk *gScratch  = NULL;
Mix_Chunk *gHigh     = NULL;
Mix_Chunk *gMedium   = NULL;
Mix_Chunk *gLow      = NULL;

//53/29, 100/100, 240/180, 320/280, 640/480, 800/600, 1440/900
const int SCREEN_WIDTH	= 800;//480*2;
const int SCREEN_HEIGHT	= 600;//300*2;

bool running = true;

enum {
	menu_1_1,
	level_1_1, level_1_2, level_1_3, level_1_4, level_1_5, level_1_6, level_1_7, level_1_8, level_1_9,
	level_2_1, level_2_2,
};

int gamestate = level_1_2;
// still need to set menu, more_levels, and credits

LTexture image1[4];

LTexture image2_1;

LTexture image3[11];

LTexture image4_1;
LTexture image5_1;
LTexture image6_1;
LTexture image7_1;
LTexture image8_1;
LTexture image9_1;

LTexture cursor;
LTexture handup;
LTexture handdown;

bool     cursorActive = false;
bool     handisdown   = false;

int X,Y;
int frame = 0;
const int WALKING_ANIM_FRAMES = 4;
SDL_Rect spriteClips[WALKING_ANIM_FRAMES];
LTexture spriteSheetTexture;

static int testingx = 0;
static int testingy = 0;

struct Region
{
	int x, y, w, h;
};

Region r  = {313,221,209, 85};
Region r2 = {303,327,235, 95};

Region r3 = {525, 87, 41,254};
Region r4 = {474,105, 52,186};

Region d1_open  = {0,   0, 29*5,120*5};
Region d2_open  = {255,65,  8*5, 79*5};
Region d3_open  = {470,105,11*5, 37*5};
Region d4_open  = {540,50, 16*5, 73*5};

Region d1_close = {135,  5,18*5,119*5};
Region d2_close = {285,105, 7*5, 53*5};
Region d3_close = {525, 90, 8*5, 50*5};
Region d4_close = {620, 10,15*5, 99*5};

Region secret1   = {365,115,115,90};

Region img3_secret = {620, 10,15*5, 99*5};

bool door1open = false;
bool door2open = false;
bool door3open = false;
bool door4open = false;

bool door1enter = false;
bool door2enter = false;
bool door3enter = false;
bool door4enter = false;

bool secret = false;

void Close();

const int FULLSCREEN    = 1;
#define OUTLINES          0
#define LOG               0

#define bounds(a) a.x,a.y,a.w,a.h

#endif // MAIN_H

