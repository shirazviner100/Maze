
#ifndef Play_h
#define Play_h

#include <stdio.h>
#include "Maze.h"

const int INPUT = 1, RANDOM = 2;
const int MAXROW = 25, MAXCOL = 80;

void playMaze();
int choiceValidition();
int getInt();
void rowAndColValidition(const int &choice, const int &row, const int &col);
void mazeReadUserInput(Maze &maze, const int &row, const int &col);
void erorMessege();
void allocationString(char * ptr);

#endif /* Play_h */
