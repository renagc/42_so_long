# so_long

This project is a small 2D game that focuses on working with textures, sprites, and basic gameplay elements. It aims to improve skills in window management, event handling, colors, and textures using the MiniLibX graphical library. The project follows specific instructions and requirements outlined in the readme.

<img width="1343" alt="image" src="https://github.com/renagc/42_so_long/assets/113280253/8c29c8f1-8571-47f4-9b28-4e4af6f844f9">

## Objectives

The objectives of the project include creating a basic computer graphics project using the MiniLibX library. It mentions improving skills in window management, event handling, colors, and textures. The goals also include being rigorous, advancing in C programming, using basic algorithms, and conducting information research.

## Common Instructions

The functions should not quit unexpectedly, and proper memory management is required. A Makefile with specific rules and flags is expected.

## - Mandatory part

The mandatory part specifies the program name, the required files for submission, and the expected arguments. The description explains that the project involves creating a basic 2D game where a character collects items and escapes.

### Game
This subsection describes the gameplay elements. The player's goal is to collect all the items on the map and choose the shortest route to escape. The W, A, S, and D keys are used to move the main character. Movement is limited to up, down, left, and right directions. The player cannot move through walls, and the current number of movements must be displayed. The game should have a 2D view and doesn't have to be real-time. The theme and characters can be customized.

### Graphic management
This subsection covers the graphical aspects of the project. The program must display the game in a window, ensuring smooth window management. Closing the window with ESC or the cross button should quit the program cleanly. The use of MiniLibX images is mandatory.

### Map
The map construction is explained, consisting of walls, collectibles, and free space. The map should be composed of specific characters (0, 1, C, E, P) and must meet certain requirements. The map must be rectangular, closed/surrounded by walls, and have a valid path. The program should handle errors and provide appropriate error messages.
