#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <iostream>

#include "Ladder.h"
#include "Character.h"
#include "Background.h"
#include "Snake.h"
#include "Fire.h"
#include "Stone.h"
#include "Gate.h"
#include "Key.h"

class Level1
{
public:
    Level1();
    ~Level1();

    bool loadMedia(SDL_Renderer *gRenderer);
    bool check();
    bool okDown();

    void win(SDL_Renderer *gRenderer);
    void checkGate();
    void findKey(SDL_Renderer *gRenderer);
    void checkLose(SDL_Renderer *gRenderer);
    void checkWin(SDL_Renderer *gRenderer);
    void renderImage(SDL_Renderer *gRenderer);
    void fall(SDL_Renderer *gRenderer);
    void continueEffect(SDL_Renderer *gRenderer);
    void handleAction(SDL_Renderer *gRenderer, SDL_Event e);
    void death(SDL_Renderer *gRenderer);

    bool WIN;
    bool LOSE;

protected:
    Stone matrixStone[14][20];
    Ladder matrixLadder[14][20];
    Key matrixKey[14][20];
    Background sky, cloud, effect;
    Character soldier;
    Fire fire;
    Gate gate1, gate2;
};

class Level2
{
public:
    Level2();
    ~Level2();

    bool loadMedia(SDL_Renderer *gRenderer);
    bool check();
    bool okDown();

    void win(SDL_Renderer *gRenderer);
    void checkGate();
    void findKey(SDL_Renderer *gRenderer);
    void checkLose(SDL_Renderer *gRenderer);
    void checkWin(SDL_Renderer *gRenderer);
    void renderImage(SDL_Renderer *gRenderer);
    void fall(SDL_Renderer *gRenderer);
    void continueEffect(SDL_Renderer *gRenderer);
    void handleAction(SDL_Renderer *gRenderer, SDL_Event e);
    void death(SDL_Renderer *gRenderer);

    bool WIN;
    bool LOSE;

protected:
    Stone matrixStone[14][20];
    Ladder matrixLadder[14][20];
    Key matrixKey[14][20];
    Background sky, cloud, effect;
    Character soldier;
    Fire fire;
    Gate gate1, gate2;
};

class Level3
{
public:
    Level3();
    ~Level3();

    bool loadMedia(SDL_Renderer *gRenderer);
    bool check();
    bool okDown();

    void win(SDL_Renderer *gRenderer);
    void checkGate();
    void findKey(SDL_Renderer *gRenderer);
    void checkLose(SDL_Renderer *gRenderer);
    void checkWin(SDL_Renderer *gRenderer);
    void renderImage(SDL_Renderer *gRenderer);
    void fall(SDL_Renderer *gRenderer);
    void continueEffect(SDL_Renderer *gRenderer);
    void handleAction(SDL_Renderer *gRenderer, SDL_Event e);
    void death(SDL_Renderer *gRenderer);

    bool WIN;
    bool LOSE;

protected:
    Stone matrixStone[14][20];
    Ladder matrixLadder[14][20];
    Key matrixKey[14][20];
    Background sky, cloud, effect;
    Character soldier;
    Fire fire;
    Gate gate1, gate2;
};

#endif // LEVEL_H_INCLUDED



