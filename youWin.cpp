#include <fstream>

#include "YouWin.h"


void YouWin::renderImage(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    sky.render(sky.x, sky.y, gRenderer);
    effect.render(effect.x, effect.y, gRenderer);
    cloud.render(cloud.x, cloud.y, gRenderer);
    snow.render(snow.x, snow.y, gRenderer);
    again.render(again.x, again.y, gRenderer);
    yes.render(yes.x, yes.y, gRenderer);
    no.render(no.x, no.y, gRenderer);
    result.render(result.x, result.y, gRenderer);

    SDL_RenderPresent( gRenderer );
}

YouWin::~YouWin()
{
}

YouWin::YouWin()
{
}


bool YouWin::loadMedia(SDL_Renderer *gRenderer)
{
    bool success=true;
    string fileSky, fileCloud, fileEffect;
    if (GAME==1)
    {
        fileSky="art/background/level1/sky.png";
        fileEffect="art/background/level1/effect.png";
        fileCloud="art/background/level1/cloud.png";
    }
    else
        if (GAME==2)
        {
            fileSky="art/background/level2/sky.png";
            fileEffect="art/background/level2/effect.png";
            fileCloud="art/background/level2/cloud.png";
        }
        else
        {
            fileSky="art/background/level3/sky.png";
            fileEffect="art/background/level3/effect.png";
            fileCloud="art/background/level3/cloud.png";
        }

    string fileResult="art/WIN.png";
    result.x=319;
    result.y=200;
    if (!WIN)
    {
        fileResult="art/OVER.png";
        result.x=254;
    }
    if (!result.loadFromFile(fileResult, gRenderer))
        success=false;

    sky.x=0;
    sky.y=0;
    if (!sky.loadFromFile(fileSky, gRenderer))
        success=false;

    effect.x=0;
    effect.y=0;
    if (!effect.loadFromFile(fileEffect, gRenderer))
        success=false;

    cloud.x=0;
    cloud.y=0;
    if (!cloud.loadFromFile(fileCloud, gRenderer))
        success=false;

    string fileSnow="art/Hello.png";
    snow.x=0;
    snow.y=0;
    if (!snow.loadFromFile(fileSnow, gRenderer))
        success=false;

    string filePL="art/playAgain.png";
    again.x=370;
    again.y=350;
    if (!again.loadFromFile(filePL, gRenderer))
        success=false;

    string fileY="art/yes.png";
    yes.x=again.x;
    yes.y=again.y+80;
    if (!yes.loadFromFile(fileY, gRenderer))
        success=false;

    string fileN="art/no.png";
    no.x=again.x+219-55;
    no.y=again.y+80;
    if (!no.loadFromFile(fileN, gRenderer))
        success=false;

    return success;
}
