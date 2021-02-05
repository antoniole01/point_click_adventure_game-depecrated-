#ifndef LOADING_H
#define LOADING_H

extern LTexture image1[4];
extern LTexture image2_1;
extern LTexture image3[11];

extern LTexture image4_1;
extern LTexture image5_1;
extern LTexture image6_1;
extern LTexture image7_1;
extern LTexture image8_1;
extern LTexture image9_1;

extern LTexture cursor;
extern LTexture handup;
extern LTexture handdown;

extern Mix_Music *gshortmus;
extern Mix_Chunk *closedoor;
extern Mix_Chunk *opendoor;

extern Mix_Music *gMusic;
extern Mix_Chunk *gScratch;
extern Mix_Chunk *gHigh;
extern Mix_Chunk *gMedium;
extern Mix_Chunk *gLow;

bool loading()
{
	bool success = true;
	
	if( !image1[0].loadFromFile("../data/images/temp/img1.1.png")){printf("Failed!\n");success = false;}
	if( !image1[1].loadFromFile("../data/images/temp/img1.2.png")){printf("Failed!\n");success = false;}
	if( !image1[2].loadFromFile("../data/images/temp/img1.3.png")){printf("Failed!\n");success = false;}
	if( !image1[3].loadFromFile("../data/images/temp/img1.2.png")){printf("Failed!\n");success = false;}
	
	if( !image2_1.loadFromFile("../data/images/temp/img2.1.png")){printf("Failed!\n");success = false;}
	
	if( !image3[0].loadFromFile("../data/images/temp/img3.1.png")){printf("Failed!\n");success = false;}
	if( !image3[1].loadFromFile("../data/images/temp/img3.2.png")){printf("Failed!\n");success = false;}
	
	if( !image3[2].loadFromFile("../data/images/temp/img3.1_d1-open.png")){printf("Failed!\n");success = false;}
	if( !image3[3].loadFromFile("../data/images/temp/img3.1_d2-open.png")){printf("Failed!\n");success = false;}
	if( !image3[4].loadFromFile("../data/images/temp/img3.1_d3-open.png")){printf("Failed!\n");success = false;}
	if( !image3[5].loadFromFile("../data/images/temp/img3.1_d4-open.png")){printf("Failed!\n");success = false;}
	if( !image3[6].loadFromFile("../data/images/temp/img3.1_d1-close.png")){printf("Failed!\n");success = false;}
	if( !image3[7].loadFromFile("../data/images/temp/img3.1_d2-close.png")){printf("Failed!\n");success = false;}
	if( !image3[8].loadFromFile("../data/images/temp/img3.1_d3-close.png")){printf("Failed!\n");success = false;}
	if( !image3[9].loadFromFile("../data/images/temp/img3.1_d4-close.png")){printf("Failed!\n");success = false;}
	if( !image3[10].loadFromFile("../data/images/temp/img3.1_secret.png")){printf("Failed!\n");success = false;}
	
	if( !image4_1.loadFromFile("../data/images/temp/img4.1.png")){printf("Failed!\n");success = false;}
	if( !image5_1.loadFromFile("../data/images/temp/img5.1.png")){printf("Failed!\n");success = false;}
	if( !image6_1.loadFromFile("../data/images/temp/img6.1.png")){printf("Failed!\n");success = false;}
	if( !image7_1.loadFromFile("../data/images/temp/img7.1.png")){printf("Failed!\n");success = false;}
	if( !image8_1.loadFromFile("../data/images/temp/img8.1.png")){printf("Failed!\n");success = false;}
	if( !image9_1.loadFromFile("../data/images/temp/img9.1.png")){printf("Failed!\n");success = false;}
	
	if( !cursor.loadFromFile  ("../data/images/cursor.png"  )){printf("Failed!\n");success = false;}
	if( !handup.loadFromFile  ("../data/images/handup.png"  )){printf("Failed!\n");success = false;}
	if( !handdown.loadFromFile("../data/images/handdown.png")){printf("Failed!\n");success = false;}

	//Load music
	gMusic = Mix_LoadMUS("../data/sound/beat.wav");if(gMusic==NULL){printf("F%s\n",Mix_GetError());success=false;}

	gshortmus= Mix_LoadMUS("c:/z/lmms/test1.wav");if(gshortmus==NULL){printf("F%s\n",Mix_GetError());success=false;}
	closedoor= Mix_LoadWAV("../data/sound/close_door_1.wav");if(closedoor==NULL){printf("F%s\n",Mix_GetError());success=false;}
	opendoor= Mix_LoadWAV("../data/sound/open_creaky_door2.wav");if(opendoor==NULL){printf("F%s\n", Mix_GetError() );success = false;}
	
	//Load sound effects
	gScratch=Mix_LoadWAV("../data/sound/scratch.wav");if(gScratch==NULL){printf("F%s\n",Mix_GetError());success=false;}
	gHigh   =Mix_LoadWAV("../data/sound/high.wav"   );if(gHigh   ==NULL){printf("F%s\n",Mix_GetError());success=false;}
	gMedium =Mix_LoadWAV("../data/sound/medium.wav" );if(gMedium ==NULL){printf("F%s\n",Mix_GetError());success=false;}
	gLow    =Mix_LoadWAV("../data/sound/low.wav"    );if(gLow    ==NULL){printf("F%s\n",Mix_GetError());success=false;}

	return success;
}

#endif // LOADING_H

