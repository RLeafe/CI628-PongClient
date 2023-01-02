#include "MyGame.h"

void MyGame::init(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("./images/stevenD.jpg");

    if (surface != nullptr) {
        std::cout << "Loaded" << std::endl;
    }
    else {
        std::cout << ("Not Loaded ", IMG_GetError()) << std::endl;
    }

    bat1 = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    if (cmd == "GAME_DATA") {
        // we should have exactly 4 arguments *for each moveable postion*
        if (args.size() == 4) {
            game_data.player1Y = stoi(args.at(0));
            game_data.player2Y = stoi(args.at(1));
            game_data.ballX = stoi(args.at(2));
            game_data.ballY = stoi(args.at(3));
        }
    } else {
        std::cout << "Received: " << cmd << std::endl;
    }

    if (cmd == "SCORES") {
        // we should have exactly 2 arguments *for each score*
        if (args.size() == 2) {
            scores.player1Score = stoi(args.at(0));
            scores.player2Score = stoi(args.at(1));
        }
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
        case SDLK_i:
            send(event.type == SDL_KEYDOWN ? "I_DOWN" : "I_UP");
            break;
        case SDLK_k:
            send(event.type == SDL_KEYDOWN ? "K_DOWN" : "K_UP");
            break;
    }
}

void MyGame::update() {
    player1.y = game_data.player1Y;
    player2.y = game_data.player2Y;

    ball.y = game_data.ballY;
    ball.x = game_data.ballX;
}

void MyGame::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, bat1, NULL, &player1);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &player1);
    SDL_RenderDrawRect(renderer, &player2);
    SDL_RenderDrawRect(renderer, &ball);

    //TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
    //SDL_Color White = { 255, 255, 255 };
    //SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);

    //SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    //SDL_Rect Message_rect; //create a rect
    //Message_rect.x = 800 /2;  //controls the rect's x coordinate 
    //Message_rect.y = 600/2; // controls the rect's y coordinte
    //Message_rect.w = 100; // controls the width of the rect
    //Message_rect.h = 100; // controls the height of the rect

    //SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    //SDL_FreeSurface(surfaceMessage);
    //SDL_DestroyTexture(Message);
}