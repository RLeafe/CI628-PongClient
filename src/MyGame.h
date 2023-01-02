#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
} game_data;

static struct Scores {
    int player1Score = 0;
    int player2Score = 0;
} scores;

class MyGame {

    private:
        SDL_Rect player1 = { 800 / 4, (600 / 2) - 30, 20, 60 };
        SDL_Rect player2 = { 3 * 800 / 4 - 20, (600 / 2) - 30, 20, 60 };
        SDL_Rect ball = { 800 / 5, (600 / 5) - 30, 15, 15 };

    public:
        

        std::vector<std::string> messages;

        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
};

#endif