//Using SDL, SDL_image, standard math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "LTexture.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Menu.h"
#include "YouWin.h"
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

const int posX=200;
const int posY=50;


Level1 game1;
Level2 game2;
Level3 game3;
Menu menu;
//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

bool loadMedia();
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gMain = NULL;
Mix_Chunk *g1 = NULL;
Mix_Chunk *g2 = NULL;

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else if( !loadMedia() )
    {
        printf( "Failed to load media!\n" );
    }
    else
    {
        //Load media
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        menu.loadMedia(gRenderer);
        menu.renderImage(gRenderer);

        //While application is running
        while( !quit)
        {

            //menu.continueEffect(gRenderer);
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
                else if(e.type == SDL_MOUSEBUTTONDOWN)
                {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    if (x>=132 && x<=132+56 && y>=400 && y<=484)
                    {
                        // level1
                        Level1 game1;
                        game1.loadMedia(gRenderer);
                        game1.renderImage(gRenderer);

                        //While application is running
                        while( !quit && !game1.WIN && !game1.LOSE)
                        {

                            game1.continueEffect(gRenderer);
                            //Handle events on queue
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                //User requests quit
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }

                                game1.handleAction(gRenderer, e);

                            }
                        }
                        YouWin RES;
                        RES.GAME=1;
                        RES.WIN=game1.WIN;
                        game1.WIN=game1.LOSE=false;
                        game1.~Level1();

                        RES.loadMedia(gRenderer);
                        RES.renderImage(gRenderer);

                        int choose=0;
                        while (choose==0)
                        {
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                    choose=5;
                                }
                                else if(e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int x, y;
                                    SDL_GetMouseState(&x, &y);
                                    if (x>=370 && x<=370+62 && y>=430 && y<=43+430)
                                        choose=1;
                                    else if (x>=370+219-55 && x<=370+219 && y>=430 && y<=43+430)
                                        choose=-1;
                                }
                            }
                        }

                        if (choose==-1)
                        {
                            quit=true;
                        }
                        else
                        {

                            menu.loadMedia(gRenderer);
                            menu.renderImage(gRenderer);
                        }


                    }
                    else if (x>=449 && x<=449+62 && y>=400 && y<=484)
                    {
                        // level2
                        Level2 game2;
                        game2.loadMedia(gRenderer);
                        game2.renderImage(gRenderer);

                        //While application is running
                        while( !quit && !game2.WIN && !game2.LOSE)
                        {

                            game2.continueEffect(gRenderer);
                            //Handle events on queue
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                //User requests quit
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }

                                game2.handleAction(gRenderer, e);

                            }
                        }
                        YouWin RES;
                        RES.GAME=2;
                        RES.WIN=game1.WIN;
                        game2.WIN=game2.LOSE=false;
                        game2.~Level2();

                        RES.loadMedia(gRenderer);
                        RES.renderImage(gRenderer);

                        int choose=0;
                        while (choose==0)
                        {
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                    choose=5;
                                }
                                else if(e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int x, y;
                                    SDL_GetMouseState(&x, &y);
                                    if (x>=370 && x<=370+62 && y>=430 && y<=43+430)
                                        choose=1;
                                    else if (x>=370+219-55 && x<=370+219 && y>=430 && y<=43+430)
                                        choose=-1;
                                }
                            }
                        }

                        if (choose==-1)
                        {
                            quit=true;
                        }
                        else
                        {

                            menu.loadMedia(gRenderer);
                            menu.renderImage(gRenderer);
                        }

                    }
                    else if (x>=768 && x<=768+63 && y>=400 && y<=484)
                    {
                        // level 3
                        Level3 game3;
                        game3.loadMedia(gRenderer);
                        game3.renderImage(gRenderer);

                        //While application is running
                        while( !quit && !game3.WIN && !game3.LOSE)
                        {

                            game3.continueEffect(gRenderer);
                            //Handle events on queue
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                //User requests quit
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }

                                game3.handleAction(gRenderer, e);

                            }
                        }
                        YouWin RES;
                        RES.GAME=3;
                        RES.WIN=game3.WIN;
                        game3.WIN=game3.LOSE=false;
                        game3.~Level3();

                        RES.loadMedia(gRenderer);
                        RES.renderImage(gRenderer);

                        int choose=0;
                        while (choose==0)
                        {
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                    choose=5;
                                }
                                else if(e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int x, y;
                                    SDL_GetMouseState(&x, &y);
                                    if (x>=370 && x<=370+62 && y>=430 && y<=43+430)
                                        choose=1;
                                    else if (x>=370+219-55 && x<=370+219 && y>=430 && y<=43+430)
                                        choose=-1;
                                }
                            }
                        }

                        if (choose==-1)
                        {
                            quit=true;
                        }
                        else
                        {

                            menu.loadMedia(gRenderer);
                            menu.renderImage(gRenderer);
                        }

                    }
                }
            }
        }


    }

    //Free resources and close SDL
    close();

    return 0;
}


bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "Tuyet", posX, posY, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                //Initialize SDL_mixer
//                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
  //                  printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    //                success = false;
                }
            }
        }
    }

    return success;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit
//    SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;


    return success;
}

