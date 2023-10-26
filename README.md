# Minesweeper-Game
Recreating the Minesweeper Game (recreated by Andrew and Ferrand)

## Project Overview

This project is an implementation of the classic Minesweeper game. It includes the following features and specifications.

## Specifications

### Basics Implementation

#### Difficulty Levels
- The game offers three difficulty levels:
  - Beginner (9 × 9 grid, 10 mines)
  - Intermediate (16 × 16 grid, 40 mines)
  - Expert (16 × 30 grid, 99 mines)

#### Tiles
- There are two types of tiles:
  - Safe Tile: This tile can be either blank or contain a digit.
    - Blank tiles indicate no adjacent armed tiles.
    - Digits denote the number of adjacent armed tiles.
  - Armed Tile: This tile contains a mine.

#### Actions
- Players can perform two actions on tiles:
  - Reveal: This action uncovers the tile. If performed on a safe tile with no adjacent armed tiles, it reveals adjacent safe tiles recursively.
  - Flag: This action is used to flag a tile as potentially armed. Performing this action a second time on the same tile undoes the initial flagging.
- Revealing an armed tile results in the player losing the game.

### Extending the Game

#### Custom Grid Dimensions and Mines
- The game allows users to customize grid dimensions and the number of mines using command line options.
- For example, players can execute the game with custom settings:
./minesweeper -r 8 -c 10 -m 6
- `-r`: Number of rows
- `-c`: Number of columns
- `-m`: Number of mines

#### Leaderboard
- The game features a leaderboard that displays the best players based on their elapsed time for each predefined difficulty level.
- Players who use custom dimensions and mine settings will not be included on the leaderboard.
