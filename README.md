# SDL-Tetris
Tetris made in C++ using SDL2.

![](assets/tetris.gif?raw=true)

## About
I've always loved Tetris and thought re-creating it would be a great way to learn SDL2 and get more experience with C++ and object oriented design.

## Build
If you're on Linux, you can use `CMake` to compile the project. Simply type:
```
cmake . && make
```
Run the executable with:
```
./tetris
```

You can also compile manually (assuming you have `g++`, `SDL2` and `SDL2_TTF`):
```
g++ ./src/*.cpp -w -lSDL2 -lSDL2_ttf -o tetris && ./tetris
```

## Controls
- Left - Move tetromino left
- Right - Move tetromino right
- Down - Soft drop tetromino
- Up/Z - Rotate tetromino clockwise
- X - Rotate tetromino counter-clockwise
- Space - Hard drop tetromino
- Left Shift - Hold tetromino, or swap with currently held tetromino

## Project goals:
- [X] CMake
  - [ ] Support Windows
- [X] Show proper piece colours after being set
- [X] Display score
- [X] Show next piece
  - [X] Show next 4 pieces in queue
- [X] Piece queue (at least one of each piece every 7 drops)
- [X] Dynamic drop rate
- [ ] Resolution config
- [X] Better piece rotation against walls
  - [ ] Fix I piece rotation against walls
