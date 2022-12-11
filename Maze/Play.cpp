
#include "Play.h"

//make the maze by the user choise and make the moves
void playMaze()
{
	int choice, row, col;
	cout << "Maze: 1) From input 2) Random\n";
	choice = choiceValidition();
	row = getInt();
	col = getInt();
	rowAndColValidition(choice, row, col);
	Maze maze(row, col);

	if (choice == INPUT)//the user choosen to make his own maze
	{
		mazeReadUserInput(maze, row, col);
		maze.slove();
		maze.showTest();
	}
	else//making random maze
	{
		maze.createRandoMaze();
		maze.slove();
		maze.showTest();
	}
}

//the functio  check if the choise is valid(1 or 2)
int choiceValidition()
{
	int choice = getInt();
	while (choice != INPUT && choice != RANDOM)
	{
		cout << "Please enter '" << INPUT << "' or '" << RANDOM << "'\n";
		choice = getInt();
	}
	return choice;
}

//function to check if the input as the same tipe as int
int getInt()
{
	int input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a number\n";
		cin >> input;
	}
	return input;
}

//validation check
void rowAndColValidition(const int &choice, const int &row, const int &col) {

	if (row > MAXROW || row <= 0 || col <= 0 || col > MAXCOL)
		erorMessege();

	if (choice == RANDOM)//the case of making rand maze
		if (row % 2 == 0 || col % 2 == 0)//most to be odd
			erorMessege();
}

//the functionb read line by line from the user
void mazeReadUserInput(Maze &maze, const int &row, const int &col) {

	char * line, clean;

	clean = getchar();
	line = new char[MAXCOL + 1];
	allocationString(line);
	cout << "Please enter you maze input:\n";
	//loop to get the line
	for (int i = 0; i < row; i++)
	{
		cin.getline(line, MAXCOL + 1);
		while (strlen(line) != col)
		{
			cout << "Please enter lines in the size of - " << col << endl;
			cin.getline(line, MAXCOL + 1);
		}

		strcpy(maze.getMaze()[i], line);	//copy the line into the maze line

	}

	delete[] line;	//delete the line allocation 

	if (!maze.checkMazeValidation())
		erorMessege();
}


//function to print invalid input and exit the system
void erorMessege() {

	cout << "Invalid input\n";
	exit(1);
}

//allocation check to char *
void allocationString(char * ptr)
{
	if (ptr == nullptr)
	{
		cout << "Allocation failed\n";
		exit(1);
	}
}
