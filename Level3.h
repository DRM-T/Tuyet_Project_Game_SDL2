#ifndef LEVEL3_H_INCLUDED
#define LEVEL3_H_INCLUDED

#include <iostream>

#include "Ladder.h"
#include "Character.h"
#include "Background.h"
#include "Snake.h"
#include "Fire.h"
#include "Stone.h"
#include "Gate.h"
#include "Key.h"

class Level3
{
public:
    Level3();
    ~Level3();

    bool check();
    bool okDown();

    void findKey(SDL_Renderer *gRenderer);
    void findHeart(SDL_Renderer *gRenderer);

    bool loadMedia(SDL_Renderer *gRenderer);
    void renderImage(SDL_Renderer *gRenderer);

    void checkGate();
    void newGATE(SDL_Renderer *gRenderer);
    void newHeart(SDL_Renderer *gRenderer);

    void continueEffect(SDL_Renderer *gRenderer);
    void handleAction(SDL_Renderer *gRenderer, SDL_Event e);

    void fall(SDL_Renderer *gRenderer);

    void snakeWalk(Snake &snake, int col1, int col2, int &SNAKE, bool &snakeLeft, SDL_Renderer *gRenderer);
    void checkGateSnake1();
    void checkGateSnake3();

    void checkSnake(Snake &snake, int &SNAKE, bool &snakeLeft, SDL_Renderer *gRenderer);

    bool WIN=false;
    bool LOSE=false;

    void checkWin(SDL_Renderer *gRenderer);
    void checkLose(SDL_Renderer *gRenderer);

    void win(SDL_Renderer *gRenderer);
    void death(SDL_Renderer *gRenderer);

    void readMatrix();

protected:
    Stone matrixStone[14][20];
    Ladder matrixLadder[14][20];
    Key matrixKey[14][20], keyYellow, heart;
    Background sky, cloud, effect;
    Character soldier;
    Gate gate1, gate2, magic1, magic2;
    Snake snake1, snake2, snake3;

    //==========================================================
    int speedSnake=4;
    int numOfKey=0;

    char codeStone[14][20];
    char codeLadder[14][20];
    char codeKey[14][20];

    bool nowRight=false, nowLeft=false;
    bool snakeLeft1=false, snakeLeft2=true, snakeLeft3=false;
    bool snake1_Top=true, snake3_Top=false;

    int FIRE=0, GATE=0, MAGIC=0, SNAKE1=0, SNAKE2=0, SNAKE3=0, ok=0;
    int Right=0, Left=0, Up=0, Down=0, downOk=0;

    bool appearGATE=false;

};

#endif // LEVEL3_H_INCLUDED


