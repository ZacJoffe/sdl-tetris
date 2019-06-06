# SDL-Tetris
Tetris made in C++ using SDL2.

## About
I've always loved Tetris and I thought re-creating it would be a great way to learn SDL2 and get more experience in C++. Even though there are still features I'd like to add (see the list below), I'm very happy with the results and think that it feels mostly authentic to normal Tetris.

## Build
Eventually, I'd like to use CMake to automate the build (see the future goals section below). For now, if you want to build the project yourself, you can use the following command (assuming you have `g++` and `SDL2` installed):
```
g++ ./src/*.cpp -w -lSDL2 -o main
```

To play it, simply run the binary:
```
./main
```

## Controls
- Left - Move tetromino left
- Right - Move tetromino right
- Down - Soft drop tetromino
- Up/Z - Rotate tetromino clockwise
- X - Rotate tetromino counter-clockwise
- Space - Hard drop tetromino
- Left Shift - Hold tetromino, or swap with currently held tetromino

## Future goals:
- [ ] CMake
- [X] Show proper piece colours after being set
- [ ] Display score
- [ ] Show next piece
- [ ] Piece queue (at least one of each piece every 7 drops)
- [ ] Dynamic drop rate
