#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "board.hpp"
#include "tetromino.hpp"
#include "colour.hpp"
#include "holdStack.hpp"
#include "queue.hpp"
#include "dashboard.hpp"

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
TTF_Font *font = nullptr;

// if any sdl call fails, returns false and logs error, otherwise return true for success
bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Window could be not created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, NULL); // enable hardware acceleration flag?
    if (renderer == NULL) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() != 0) {
        std::cout << "Font could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    std::string fontName = "assets/Roboto-Black.ttf";
    
    // font = TTF_OpenFont(fontName.c_str(), 12);
    font = TTF_OpenFont("assets/Roboto-Black.ttf", 24);
    if (font == NULL) {
        std::cout << "Font could not be loaded! SDL Error: " << SDL_GetError() << std::endl;
    }

    return true;
}

// destroy all instances of sdl and quit
void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    // initialize sdl
    if (!init()) {
        return 1;
    }

	// random seed
    srand(time(NULL));

    // create sdl event and quit loop flag
    SDL_Event e;
    bool quit = false;

    // instantiate queue object
    Queue q;
    q.print();

    // instantiate game objects
    // Tetromino t(static_cast<TetrominoType>(rand() % 7)); // displayed, piece that player interacts with
    Tetromino t(q.dequeue());
    Tetromino collisionTest; // used for testing collision upon input
    Board b; // game board object

    // time variables for auto-drop
    unsigned int lastTime = 0;
    unsigned int currentTime;

    // shift holding
    HoldStack held;
    bool swapped = false;

    // dashboard
    Dashboard d(q.getNextSet());
    
    // main game loop
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        // move tetromino left
                        collisionTest = t;
                        collisionTest.move(-1, 0);
                        if (!b.collision(collisionTest)) {
                            t.move(-1, 0);
                        }
                        break;
                    case SDLK_RIGHT:
                        // move tetromino right
                        collisionTest = t;
                        collisionTest.move(1, 0);
                        if (!b.collision(collisionTest)) {
                            t.move(1, 0);
                        }
                        break;
                    case SDLK_UP:
                        // rotate tetromino clockwise
                        collisionTest = t;
                        collisionTest.rotateCW();
                        if (!b.collision(collisionTest)) {
                            t.rotateCW();
                        } else {
                            // check if the piece is at a wall

                            // special case for I piece - move twice
                            if (t.getType() == I) {
                                // if piece is at the right wall
                                if (t.getXPos() > 5) {
                                    // move left twice, check for collision
                                    collisionTest = t;
                                    collisionTest.move(-1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(-1, 0);
                                        t.rotateCW();
                                    }
                                } else {
                                    // at left wall
                                    collisionTest = t;
                                    // move right twice, check for collision
                                    collisionTest.move(2, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(2, 0);
                                        t.rotateCW();
                                    }
                                }
                            } else {
                                // if piece is at right wall
                                if (t.getXPos() > 5) {
                                    // move left, check for collision
                                    collisionTest = t;
                                    collisionTest.move(-1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(-1, 0);
                                        t.rotateCW();
                                    }
                                } else {
                                    // piece at left wall
                                    // move right once, check for collision
                                    collisionTest = t;
                                    collisionTest.move(1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(1, 0);
                                        t.rotateCW();
                                    }
                                }
                            }
                        }
                        break;
                    case SDLK_z:
                        // rotate tetromino clockwise
                        collisionTest = t;
                        collisionTest.rotateCW();
                        if (!b.collision(collisionTest)) {
                            t.rotateCW();
                        } else {
                            // check if the piece is at a wall

                            // special case for I piece - move twice
                            if (t.getType() == I) {
                                // if piece is at the right wall
                                if (t.getXPos() > 5) {
                                    // move left twice, check for collision
                                    collisionTest = t;
                                    collisionTest.move(-1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(-1, 0);
                                        t.rotateCW();
                                    }
                                } else {
                                    // at left wall
                                    collisionTest = t;
                                    // move right twice, check for collision
                                    collisionTest.move(2, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(2, 0);
                                        t.rotateCW();
                                    }
                                }
                            } else {
                                // if piece is at right wall
                                if (t.getXPos() > 5) {
                                    // move left, check for collision
                                    collisionTest = t;
                                    collisionTest.move(-1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(-1, 0);
                                        t.rotateCW();
                                    }
                                } else {
                                    // piece at left wall
                                    // move right once, check for collision
                                    collisionTest = t;
                                    collisionTest.move(1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(1, 0);
                                        t.rotateCW();
                                    }
                                }
                            }
                        }
                        break;
                    case SDLK_x:
                        // rotate tetromino counter clockwise 
                        collisionTest = t;
                        collisionTest.rotateCCW();
                        if (!b.collision(collisionTest)) {
                            t.rotateCCW();
                        } else {
                            // check if the piece is at a wall

                            // special case for I piece - move twice
                            if (t.getType() == I) {
                                // if piece is at the right wall
                                if (t.getXPos() > 5) {
                                    // move left twice, check for collision
                                    collisionTest = t;
                                    collisionTest.move(-1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(-1, 0);
                                        t.rotateCCW();
                                    }
                                } else {
                                    // at left wall
                                    collisionTest = t;
                                    // move right twice, check for collision
                                    collisionTest.move(2, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(2, 0);
                                        t.rotateCCW();
                                    }
                                }
                            } else {
                                // if piece is at right wall
                                if (t.getXPos() > 5) {
                                    // move left, check for collision
                                    collisionTest = t;
                                    collisionTest.move(-1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(-1, 0);
                                        t.rotateCCW();
                                    }
                                } else {
                                    // piece at left wall
                                    // move right once, check for collision
                                    collisionTest = t;
                                    collisionTest.move(1, 0);
                                    if (!b.collision(collisionTest)) {
                                        t.move(1, 0);
                                        t.rotateCCW();
                                    }
                                }
                            }
                        }
                        break;
					case SDLK_DOWN:
                        // move tetromino down - soft drop
                        collisionTest = t;
                        collisionTest.move(0, 1);
                        if (b.atFloor(collisionTest)) {
                            b.setBlock(t);
                            b.clearPieces();
                            // t = Tetromino(static_cast<TetrominoType>(rand() % 7));
                            t = Tetromino(q.dequeue());
                            swapped = false;
                        } else {
                            t.move(0, 1);
                        }
                        break;
                    case SDLK_ESCAPE:
                        // restart the game
                        b.reset();
                        // t = Tetromino(static_cast<TetrominoType>(rand() % 7));
                        t = Tetromino(q.dequeue());
                        break;
					case SDLK_SPACE:
                        // hard drop
                        {
                            collisionTest = t;
                            int moveCount = 0;
                            while (!b.atFloor(collisionTest)) {
                                collisionTest.move(0, 1);
                                moveCount++;
                            }
                            t.move(0, moveCount - 1);
                            b.setBlock(t);
                            b.clearPieces();
                            // t = Tetromino(static_cast<TetrominoType>(rand() % 7));
                            t = Tetromino(q.dequeue());
							swapped = false;
                            // b.print();
                            // hard drop

                            q.print();

                            break;
						}
					case SDLK_LSHIFT:
                        // swap the current tetromino with a new one
						{
							if (held.isHeld()) {
								if (!swapped) {
									held.swap(t);
									swapped = true;
								}
							} else {
								held.push(t);
								// t = Tetromino(static_cast<TetrominoType>(rand() % 7));
                                t = Tetromino(q.dequeue());
								swapped = true;
							}
							break;
						}
                }
            }
        }

        // check if enough time has passed since last gravity auto-drop
        currentTime = SDL_GetTicks();

        // based off 5.10 - https://www.colinfahey.com/tetris/tetris.html
        if (currentTime > lastTime + (11 - b.getLevel()) * 50) {
            collisionTest = t;
            collisionTest = t;
            collisionTest.move(0, 1);
            if (b.atFloor(collisionTest)) {
                b.setBlock(t);
                b.clearPieces();
                // t = Tetromino(static_cast<TetrominoType>(rand() % 7));
                t = Tetromino(q.dequeue());
                swapped = false;
            } else {
                t.move(0, 1);
            }
            lastTime = currentTime;
        }

        // render everything
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        b.draw(renderer, t);
        d.update(q.getNextSet(), held.getHeld().getType(), b.getScore(), b.getLevel());
        d.draw(renderer, font);

        SDL_RenderPresent(renderer);

        // reset if game is over
        if (b.failureState()) {
            b.reset();
            q = Queue();
            q.print();
            d = Dashboard();
            SDL_Delay(1000);
        } 
    }

    // safely close sdl
    close();

    return 0;
}
