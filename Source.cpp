#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;
const int ROW = 9, COL = 9;
int SCORE = 0;
int targetedScore = 1000;
int MOVES = 20;
int totalMoves = 20;

void Loading_Page(char[][COL]);
void Map_Load(char[][COL]);
void Rewrite(char[][COL]);
void move_cursor_to_xy(int, int);
void Insert_Steric(char[][COL]);
void swapping(char[][COL]);
void Save_Game(char[][COL]);
void Load_Game(char[][COL]);
void result();

void Candy_Generator(char arr[][COL])
{
	char candies[5] = { '#' ,'$' , '@' , '?' , '!' };
	srand(time(0));
	int r;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			r = (rand() % 5);
			arr[i][j] = candies[r];
		}
	}
	Loading_Page(arr);
}
void Loading_Page(char arr[][COL])
{
	int num;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << endl << "\t\t\t\t\t*WELCOME TO CANDY CRUSH 2.0* " << endl;
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\t\tLOADING\n\t\t\t\t\t";
	for (int i = 0; i < 36; i++)
	{
		Sleep(100);
		cout << ".";
	}
	SetConsoleTextAttribute(hConsole, 15);
	system("CLS");
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\n\n\n\n\t\t\t\t\t\t\t*GAME IS STARTING*\n\n\n";
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t\t\t\t1. New Game\n\n " << "\t\t\t\t\t\t2. Load Game\n\n " << "\t\t\t\t\t\t3. Exit\n ";
	SetConsoleTextAttribute(hConsole, 13);
	cout << "\n\n\t\t\t\t\t\tSelect any of these to continue : ";
	cin >> num;
	cout << endl;
	if (num == 1)
	{
		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n :) New game is starting...";
		Sleep(2000);
		system("CLS");
		Map_Load(arr);
	}
	else if (num == 2)
	{
		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n :) Load game is starting...";
		Sleep(2000);
		system("CLS");
		Load_Game(arr);
	}
	else if (num == 3)
	{
		SetConsoleTextAttribute(hConsole, 10);
		cout << " Game is ending please wait... ";
		Sleep(2000);
		system("CLS");
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 10);
		cout << "Invalid input\n";
	}
}
void Map_Load(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << " | ";
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == '#')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '$')
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '?')
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '@')
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '!')
			{
				SetConsoleTextAttribute(hConsole, 13);
				cout << arr[i][j];
			}
			SetConsoleTextAttribute(hConsole, 15);
			cout << " | ";

		}
		cout << endl;
	}
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "-";
	}
	cout << "+" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\n\n\nSCORE = " << SCORE << "\tREMAINING MOVES = " << MOVES << "\tTOTAL MOVES = " << totalMoves << "\n";
	Insert_Steric(arr);
}
void Insert_Steric(char arr[][COL])
{
	srand(time(0));
	int r;
	char candies[5] = { '#' ,'$' , '@' , '?' , '!' };
	bool flag = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			for (int k = 0; k < COL - 2; k++)
			{
				if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2] && candies[i] == arr[j][k + 3] && candies[i] == arr[j][k + 4]))
				{
					arr[j][k] = 'O';
					arr[j][k + 1] = '*';
					arr[j][k + 2] = '*';
					arr[j][k + 3] = '*';
					arr[j][k + 4] = '*';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2] && candies[i] == arr[j][k + 3]))
				{
					arr[j][k] = '%';
					arr[j][k + 1] = '*';
					arr[j][k + 2] = '*';
					arr[j][k + 3] = '*';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j + 1][k] && candies[i] == arr[j + 2][k]) && (candies[i] == arr[j + 2][k + 1] && candies[i] == arr[j + 2][k + 2]))
				{
					arr[j + 2][k + 2] = 'L';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j + 1][k] && candies[i] == arr[j + 2][k]) && (candies[i] == arr[j + 2][k - 1] && candies[i] == arr[j + 2][k - 2]))
				{
					arr[j + 2][k - 2] = 'L';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]) && (candies[i] == arr[j + 1][k + 2] && candies[i] == arr[j + 2][k + 2]))
				{
					arr[j + 2][k + 2] = 'L';
				}
				else if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]) && (candies[i] == arr[j + 1][k] && candies[i] == arr[j + 2][k]))
				{
					arr[j][k + 2] = 'L';
				}
				if (candies[i] == arr[j][k] && (candies[i] == arr[j][k + 1] && candies[i] == arr[j][k + 2]))
				{
					if (candies[i] == '#')
					{
						SCORE += 30;
					}
					else if (candies[i] == '@')
					{
						SCORE += 30;
					}
					else if (candies[i] == '$')
					{
						SCORE += 40;
					}
					else if (candies[i] == '?')
					{
						SCORE += 50;
					}
					else if (candies[i] == '!')
					{
						SCORE += 60;
					}
					arr[j][k] = '*';
					arr[j][k + 1] = '*';
					arr[j][k + 2] = '*';
				}

			}
		}
		for (int a = 0; a < ROW - 2; a++)
		{
			for (int b = 0; b < COL; b++)
			{
				if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b] && candies[i] == arr[a + 3][b] && candies[i] == arr[a + 4][b]))
				{
					arr[a + 4][b] = 'O';
					arr[a + 3][b] = '*';
					arr[a + 2][b] = '*';
					arr[a + 1][b] = '*';
					arr[a][b] = '*';
				}
				else if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b] && candies[i] == arr[a + 3][b]))
				{
					arr[a + 3][b] = '%';
					arr[a + 2][b] = '*';
					arr[a + 1][b] = '*';
					arr[a][b] = '*';
				}
				else if (candies[i] == arr[a][b] && (candies[i] == arr[a + 1][b] && candies[i] == arr[a + 2][b]))
				{
					if (candies[i] == '#')
					{
						SCORE += 30;
					}
					else if (candies[i] == '@')
					{
						SCORE += 30;
					}
					else if (candies[i] == '$')
					{
						SCORE += 40;
					}
					else if (candies[i] == '?')
					{
						SCORE += 50;
					}
					else if (candies[i] == '!')
					{
						SCORE += 60;
					}
					arr[a][b] = '*';
					arr[a + 1][b] = '*';
					arr[a + 2][b] = '*';
				}
			}
		}
		for (int x = 0; x < ROW; x++)
		{
			for (int y = 0; y < COL; y++)
			{
				if (arr[x][y] == '*')
				{
					while (x != 0)
					{
						arr[x][y] = arr[x - 1][y];
						x--;
					}
					r = (rand() % 5);
					arr[x][y] = candies[r];
					flag = false;
				}
			}
		}
		if (!flag)
		{
			i = -1;
		}
		flag = true;
	}
	if (MOVES > 0 && SCORE < targetedScore)
	{
		Rewrite(arr);
	}
	else
	{
		system("CLS");
		result();
	}
	cout << "\n\n";
}
void Rewrite(char arr[][COL])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Sleep(2000);
	system("CLS");
	SetConsoleTextAttribute(hConsole, 15);
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "-";
	}
	cout << "+" << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << " | ";
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == '#')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '$')
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '?')
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '@')
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << arr[i][j];
			}
			else if (arr[i][j] == '!')
			{
				SetConsoleTextAttribute(hConsole, 13);
				cout << arr[i][j];
			}
			else
			{
				cout << arr[i][j];
			}
			SetConsoleTextAttribute(hConsole, 15);
			cout << " | ";

		}
		cout << endl;
	}
	cout << " +";
	for (int i = 1; i <= 35; i++)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "-";
	}
	cout << "+" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\n\n\nSCORE = " << SCORE << "\tREMAINING MOVES = " << MOVES << "\tTOTAL MOVES = " << totalMoves << "\n";
	Save_Game(arr);
	swapping(arr);
}
void swapping(char arr[][COL])
{
	int x = 3;
	int y = 1;
	int a = x;
	move_cursor_to_xy(x, y);
	bool cond = true;
	while (cond)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			y += 1;
			if (y <= 9)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				y = 9;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			y -= 1;
			if (y >= 1)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				y = 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 4;
			a += 3;
			if (x <= 35)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				x = 35;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 4;
			a -= 3;
			if (x >= 3)
			{
				move_cursor_to_xy(x, y);
			}
			else
			{
				x = 3;
			}
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			cond = false;
		}
	}
	int column, row;
	column = x - a;
	row = y - 1;
	bool flag = true;
	int move;
	while (flag)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			MOVES--;
			move = 1;
			flag = false;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			MOVES--;
			move = 2;
			flag = false;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			MOVES--;
			move = 3;
			flag = false;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			MOVES--;
			move = 4;
			flag = false;
		}
	}
	char temp;
	if (move == 1)
	{
		temp = arr[row][column];
		arr[row][column] = arr[row + 1][column];
		arr[row + 1][column] = temp;
	}
	if (move == 2)
	{
		temp = arr[row][column];
		arr[row][column] = arr[row - 1][column];
		arr[row - 1][column] = temp;
	}
	if (move == 3)
	{
		temp = arr[row][column];
		arr[row][column] = arr[row][column - 1];
		arr[row][column - 1] = temp;
	}
	if (move == 4)
	{
		temp = arr[row][column];
		arr[row][column] = arr[row][column + 1];
		arr[row][column + 1] = temp;
	}
	Insert_Steric(arr);
}
void move_cursor_to_xy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
	{
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD cordinates;
	cordinates.X = x;
	cordinates.Y = y;
	SetConsoleCursorPosition(h, cordinates);
	Sleep(200);
}
void Save_Game(char arr[][COL])
{
	ofstream savingArray, savingData;
	savingArray.open("savedGame.txt");
	savingData.open("gameData.txt");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			savingArray << arr[i][j];
		}
		savingArray << endl;
	}
	savingData << MOVES << endl << SCORE << endl;
}
void Load_Game(char arr[][COL])
{
	ifstream loadArray, loadData;
	loadArray.open("savedGame.txt");
	loadData.open("gameData.txt");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			loadArray >> arr[i][j];
		}
	}
	loadData >> MOVES >> SCORE;
	Map_Load(arr);
}
void result()
{
	if (SCORE > targetedScore)
	{
		cout << "\n\n\n\n\t\t\t\t\tCONGRATULATIONS YOU WON :) ";
	}
	else if (SCORE < targetedScore)
	{
		cout << "\n\n\n\n\t\t\t\t\tYOU LOSE :( ";
	}
	else if (SCORE == targetedScore)
	{
		cout << "\n\n\n\n\t\t\t\t\tDRAW";
	}
	cout << "\n\n\t\t\t\t\tYOUR FINAL SCORE IS : " << SCORE << "\n\n\t\t\t\t\tYOUR TARGETED SCORE IS : " << targetedScore << "\n\n\t\t\t\t\tREMAINING MOVES ARE : " << MOVES << endl ;
}
int main()
{
	char arr[ROW][COL];
	Candy_Generator(arr);
	system("pause");
	return 0;
}