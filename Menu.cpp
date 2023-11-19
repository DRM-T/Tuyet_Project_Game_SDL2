#include <fstream>

#include "Menu.h"


void Menu::renderImage(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    sky1.render(sky1.x, sky1.y, gRenderer);
    effect1.render(effect1.x, effect1.y, gRenderer);
    cloud1.render(cloud1.x, cloud1.y, gRenderer);

    sky2.render(sky2.x, sky2.y, gRenderer);
    effect2.render(effect2.x, effect2.y, gRenderer);
    cloud2.render(cloud2.x, cloud2.y, gRenderer);

    sky3.render(sky3.x, sky3.y, gRenderer);
    effect3.render(effect3.x, effect3.y, gRenderer);
    cloud3.render(cloud3.x, cloud3.y, gRenderer);

    snow.render(snow.x, snow.y, gRenderer);

    nameOfGame.render(nameOfGame.x, nameOfGame.y, gRenderer);

    G1.render(G1.x, G1.y, gRenderer);
    G2.render(G2.x, G2.y, gRenderer);
    G3.render(G3.x, G3.y, gRenderer);

    SDL_RenderPresent( gRenderer );
}

Menu::~Menu()
{
}

Menu::Menu()
{
}


bool Menu::loadMedia(SDL_Renderer *gRenderer)
{
    bool success=true;
    // level1
    string fileSky1="art/background/level1/sky.png";
    sky1.x=0;
    sky1.y=0;
    if (!sky1.loadFromFile(fileSky1, gRenderer))
        success=false;

    string fileEffect1="art/background/level1/effect.png";
    effect1.x=0;
    effect1.y=0;
    if (!effect1.loadFromFile(fileEffect1, gRenderer))
        success=false;

    string fileCloud1="art/background/level1/cloud.png";
    cloud1.x=0;
    cloud1.y=0;
    if (!cloud1.loadFromFile(fileCloud1, gRenderer))
        success=false;
    // level2
    string fileSky2="art/background/level2/sky.png";
    sky2.x=320;
    sky2.y=0;
    if (!sky2.loadFromFile(fileSky2, gRenderer))
        success=false;

    string fileEffect2="art/background/level2/effect.png";
    effect2.x=320;
    effect2.y=0;
    if (!effect2.loadFromFile(fileEffect2, gRenderer))
        success=false;

    string fileCloud2="art/background/level2/cloud.png";
    cloud2.x=320;
    cloud2.y=0;
    if (!cloud2.loadFromFile(fileCloud2, gRenderer))
        success=false;
    // level3
    string fileSky3="art/background/level3/sky.png";
    sky3.x=640;
    sky3.y=0;
    if (!sky3.loadFromFile(fileSky3, gRenderer))
        success=false;

    string fileEffect3="art/background/level3/effect.png";
    effect3.x=640;
    effect3.y=0;
    if (!effect3.loadFromFile(fileEffect3, gRenderer))
        success=false;

    string fileCloud3="art/background/level3/cloud.png";
    cloud3.x=640;
    cloud3.y=0;
    if (!cloud3.loadFromFile(fileCloud3, gRenderer))
        success=false;

    string fileNameOfGame="art/menu/title.png";
    nameOfGame.x=91;
    nameOfGame.y=200;
    if (!nameOfGame.loadFromFile(fileNameOfGame, gRenderer))
        success=false;

    G1.y=G2.y=G3.y=400;

    string fileG1="art/menu/1.png";
    G1.x=132;
    if (!G1.loadFromFile(fileG1, gRenderer))
        success=false;

    string fileG2="art/menu/2.png";
    G2.x=449;
    if (!G2.loadFromFile(fileG2, gRenderer))
        success=false;

    string fileG3="art/menu/3.png";
    G3.x=768;
    if (!G3.loadFromFile(fileG3, gRenderer))
        success=false;

    string fileSnow="C:/tuyet/art/menu/menuS.png";
    snow.x=160;
    snow.y=0;
    //if (!snow.loadFromFile(fileSnow, gRenderer))
      //success=false;
    return success;
}
