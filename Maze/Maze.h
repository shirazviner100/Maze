#ifndef __MAZE_H
#define __MAZE_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Stack.h"
#include "Queue.h"

const int MAX_STRING = 80;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
const int MAX_SIZE_RANDOM_ARRAY = 3;
class Maze
{
private:
	char ** theMaze;
	int row, col;

	void makeMazeWall() const;
	int getRandNumber(const Point & p) const;
	void removeAll$() const;
	int checkValidSteps(const Point & p, int * randArr) const;
	Point makeTurn(const Point & p, int & action) const;

public:
	//constractors
	Maze() = default;
	Maze(int & h, int & w);
	Maze(const Maze & copy);
	Maze(Maze && move);
	//distractor
	~Maze();

	char** getMaze() const { return this->theMaze; }
	int getH() const { return this->row; }
	int getW() const { return this->col; }
	//randomMaze
	void createRandoMaze() const;
	//inputMaze
	bool checkMazeValidation();
	//print
	void showTest() const;
	//alloction
	void alloctionString2D(char **string);
	void alloctionSring(char *string);
	//slove
	void slove();
	void checkSloveValid(Queue &queue, const Point &point)const;
};

#endif
