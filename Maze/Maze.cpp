#include "Maze.h"

//maze c`tor
Maze::Maze(int& h, int& w) {

	this->row = h;
	this->col = w;
	this->theMaze = new char*[h];
	alloctionString2D(this->theMaze);

	for (int i = 0; i < this->row; i++)
	{
		this->theMaze[i] = new char[w];
		alloctionSring(this->theMaze[i]);
	}
}

//maze copy c`tor
Maze::Maze(const Maze & copy) {

	this->row = copy.row;
	this->col = copy.col;
	this->theMaze = new char*[this->row];
	alloctionString2D(this->theMaze);
	for (int i = 0; i < this->row; i++) {
		this->theMaze[i] = new char[col];
		alloctionSring(this->theMaze[i]);
		strcpy(this->theMaze[i], copy.theMaze[i]);
	}
}

//maze move c`tor
Maze::Maze(Maze && move)
{
	this->row = move.row;
	this->col = move.col;
	this->theMaze = new char*[this->row];
	alloctionString2D(this->theMaze);
	this->theMaze = move.theMaze;
	move.theMaze = nullptr;
	move.row = move.col = 0;
}

//d`ctor
Maze::~Maze()
{
	for (int i = 0; i < this->row; i++)
	{
		delete[] this->theMaze[i];
	}
	delete[] this->theMaze;
}

//function to init the maze by the instructions
void Maze::makeMazeWall() const {

	//loop to reset the maze
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
				this->theMaze[i][j] = '*';
			else
				if (i % 2 == 0)
					this->theMaze[i][j] = '*';

				else {
					if (j % 2 == 0)
						this->theMaze[i][j] = '*';
					else
						this->theMaze[i][j] = ' ';
				}
		}
	}
	cout << endl;
	this->theMaze[1][0] = ' ';
	this->theMaze[this->row - 2][this->col - 1] = ' ';
}

//the function build the maze by random decisions
void Maze::createRandoMaze() const {

	int i = 1, j = 1, random;

	this->makeMazeWall();         //reset maze walls
	Stack s;
	Point p(i, j), pNextStep;
	s.makeEmpty();               //reset stack
	s.push(p);

	//loops to make moves by random decision
	while (!s.isEmpty()) {
		this->theMaze[i][j] = '$';
		p = s.pop();
		random = getRandNumber(p);
		if (random != -1)          //there are validation moves to this point
		{
			pNextStep = makeTurn(p, random);
			s.push(p);
			s.push(pNextStep);
			i = pNextStep.getX();
			j = pNextStep.getY();
		}
	}
	this->removeAll$();         //delete all the $ shows
}

//the function removes all the $ shows from the maze
void Maze::removeAll$() const {

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			if (this->theMaze[i][j] == '$')
				this->theMaze[i][j] = ' ';
		}
	}
}

//the function make the move by the action parameter
Point Maze::makeTurn(const Point & p, int & action) const
{
	int x = p.getX(), y = p.getY();
	switch (action)
	{
	case UP: //move up
		this->theMaze[x - 1][y] = '$';
		this->theMaze[x - 2][y] = '$';
		return Point(x - 2, y);

	case DOWN: //move down
		this->theMaze[x + 1][y] = '$';
		this->theMaze[x + 2][y] = '$';
		return Point(x + 2, y);


	case LEFT: //move left
		this->theMaze[x][y - 1] = '$';
		this->theMaze[x][y - 2] = '$';
		return Point(x, y - 2);

	case RIGHT: //move right
		this->theMaze[x][y + 1] = '$';
		this->theMaze[x][y + 2] = '$';
		return Point(x, y + 2);

	default://this case wont append
		return p;
		break;
	}
}

//the function  rand one of the valid moves and return the choise
int Maze::getRandNumber(const Point & p) const {

	int randArr[MAX_SIZE_RANDOM_ARRAY], random;
	int limitRand = this->checkValidSteps(p, randArr);
	if (limitRand > 0)  //there are valid moves
	{

		random = rand() % limitRand;
		return randArr[random];
	}

	return -1;  //there are not valid moves to this point
}

//the function make an array of the validation moves
int Maze::checkValidSteps(const Point & p, int * randArr) const {

	int logSize = 0;
	int x = p.getX(), y = p.getY();

	if ((x - 2 > 0) && (this->theMaze[x - 2][y] == ' '))
		randArr[logSize++] = UP; //0=up

	if ((x + 2 < row - 1) && (this->theMaze[x + 2][y] == ' '))
		randArr[logSize++] = DOWN; //1=dowm

	if ((y - 2 > 0) && (this->theMaze[x][y - 2] == ' '))
		randArr[logSize++] = LEFT; //2=left

	if ((y + 2 < col - 1) && (this->theMaze[x][y + 2] == ' '))
		randArr[logSize++] = RIGHT; //3=right

	return logSize;
}

//function to check the user maze validation
bool Maze::checkMazeValidation() {

	//loop to check colms frame validation
	for (int i = 0; i < this->row; i++)
	{
		if (i != 1)//enter point
		{
			if (this->theMaze[i][0] != '*')
				return false;
		}
		else
			if (this->theMaze[i][0] != ' ')
				return false;

		if (i != row - 2)//exit point
		{
			if (this->theMaze[i][col - 1] != '*')
				return false;
		}
		else
			if (this->theMaze[i][col - 1] != ' ')
				return false;
	}

	//loop to check rows frame validation
	for (int j = 0; j < col; j++)
	{
		if (this->theMaze[0][j] != '*' || this->theMaze[row - 1][j] != '*')
			return false;
	}

	//loop to check the body maze validations
	for (int i = 1; i < row - 1; i++)
		for (int j = 1; j < col - 1; j++)
			if (this->theMaze[i][j] != '*' && this->theMaze[i][j] != ' ')
				return false;

	return true;
}

//alloction check char**
void Maze::alloctionString2D(char **string) {

	if (string == nullptr) {
		cout << "Alloction Eror\n";
		exit(2);
	}

}

//alloctaion check to char*
void Maze::alloctionSring(char *string) {

	if (string == nullptr) {
		cout << "Alloction Eror\n";
		exit(2);
	}
}

void Maze::showTest() const
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			cout << this->theMaze[i][j];
		}
		cout << "\n";
	}
}

//slove
void Maze::slove()
{
	int x = 1, y = 0;
	bool  flagSolution = false; //boolean parameter to find the exit
	Queue queue(this->row, this->col);
	Point point(x, y);
	queue.enQueue(point);

	//loop to maake the turns till we find the exit point
	while (!queue.isEmpty())
	{
		point = queue.deQueue();
		x = point.getX();
		y = point.getY();
		this->theMaze[x][y] = '$';

		if (x == this->row - 2 && y == this->col - 1)//we get to the exit point
		{
			flagSolution = true;
			break;
		}
		checkSloveValid(queue, point);  //make the turn
	}

	if (!flagSolution)//there is no exit from this maze
		cout << "No solution\n";
}

//the function make the moves by the order by the instructions
void Maze::checkSloveValid(Queue &queue, const Point &point) const {

	int x = point.getX(), y = point.getY();

	if (this->theMaze[x][y + 1] == ' ')//moveRight
		queue.enQueue(Point(x, y + 1));

	if (this->theMaze[x + 1][y] == ' ')
		queue.enQueue(Point(x + 1, y));//moveDown

	if (this->theMaze[x][y - 1] == ' ')
		queue.enQueue(Point(x, y - 1));//moveLeft

	if (this->theMaze[x - 1][y] == ' ')
		queue.enQueue(Point(x - 1, y));//moveUp
}


