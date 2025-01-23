#include<iostream>
#include <string>
#include<fstream>
#include<conio.h>
#include <ctime>
#include<cstdlib>
using namespace std;

#define SIZE 99


template <class T>
class Stack {
private:
	int item, i;
	T arr_stack[SIZE];
	int top;

public:

	Stack() {
		top = 0;

	}
	void push(char a) {
		if (top == SIZE)
			cout << "\nStack is Full!";
		else {
			cout << "\nPosition : " << top << ", Pushed Value  :" << a << endl;
			arr_stack[top++] = a;

		}
	}
	char movement()
	{

		cout<<"enter w,a,s,d to move:";
		char op;
		op = _getch();
		if (op == 'w' || op == 'd' || op == 'a' || op == 's')
		{
			cout << "pressed " << op << endl;
		}

		else
		{
			cout << "enter w a s d to continue" << endl;
		}
		return op;
	}
	void map(char** word, int row, int col, int sx, int sy)
	{
		while (true)
		{
		char op = movement();
					char temp;
			if (op == 'w')
			{
				if (sx == 0)
				{
					cout << "already at top" << endl;
					displayMap(word, row, col);
				}
				else if (word[sx - 1][sy] == '0')
				{
					temp = word[sx][sy];
					word[sx][sy] = word[sx - 1][sy];
					word[sx - 1][sy] = temp;
					sx -= 1;
					push(op);
					displayMap(word, row, col);
				}
				else if (word[sx - 1][sy] == 'D')
				{
					cout << "game ended! u were eaten by the devil"<<endl;
					displayMap(word, row, col);
					break;
				}
				else if (word[sx - 1][sy] == 'P')
				{
					int coin = 0;
					cout << "U entered a portal! flipping a coin." << endl;
					coin = (rand() % 2)
						cout << coin;
					if (coin==0)
					{
						cout << "you got a head entering next room" << endl;
						displayMap(word, row, col);
					}
					else if (coin==1)
					{
						cout << "you got a tail sending you back" << endl;
					}
					break;


					//portal function
				}
				else if (word[sx - 1][sy] == 'G')
				{
					cout << "U met a friendly ghost Gasper!He is teleporting u to the treasure room." << endl;
					displayMap(word, row, col);
					break;

				}
			}
			else if (op == 's')
			{
				if (sx == row)
				{
					cout << "already at bottom" << endl;
					displayMap(word, row, col);
				}
				else if (word[sx + 1][sy] == '0')
				{
					temp = word[sx][sy];
					word[sx][sy] = word[sx + 1][sy];
					word[sx + 1][sy] = temp;
					sx += 1;
					push(op);
					displayMap(word, row, col);
				}
				else if (word[sx + 1][sy] == 'D')
				{
					cout << "game ended! u were eaten by the devil" << endl;
					displayMap(word, row, col);
					break;

				}
				else if (word[sx + 1][sy] == 'P')
				{
					cout << "U entered a portal! flipping a coin." << endl;
					//portal function
					displayMap(word, row, col);	 
					break;

				}
				else if (word[sx + 1][sy] == 'G')
				{
					cout << "U met a friendly ghost Gasper!He is teleporting u to the treasure room." << endl;
					displayMap(word, row, col);
					break;

				}
			}
			else if (op == 'a')
			{
				if (sy == 0)
				{
					cout << "already at left" << endl;
					displayMap(word, row, col);
				}
				else if (word[sx][sy - 1] == '0')
				{
					temp = word[sx][sy];
					word[sx][sy] = word[sx][sy - 1];
					word[sx][sy - 1] = temp;
					sy -= 1;
					push(op);
					displayMap(word, row, col);
				}
				else if (word[sx][sy - 1] == 'D')
				{
					cout << "game ended! u were eaten by the devil" << endl;
					displayMap(word, row, col);
					break;

				}
				else if (word[sx][sy - 1] == 'P')
				{
					cout << "U entered a portal! flipping a coin." << endl;
					displayMap(word, row, col);
					break;

					//portal 
				}
				else if (word[sx][sy - 1] == 'G')
				{
					cout << "U met a friendly ghost Gasper!He is teleporting u to the treasure room." << endl;
					displayMap(word, row, col);
					break;

				}
			}
			else if (op == 'd')
			{
				if (sy == col)
				{
					cout << "already at right" << endl;
					displayMap(word, row, col);
				}
				else if (word[sx][sy + 1] == '0')
				{
					temp = word[sx][sy];
					word[sx][sy] = word[sx][sy + 1];
					word[sx][sy + 1] = temp;
					sy += 1;
					push(op);
					displayMap(word, row, col);
				}
				else if (word[sx][sy + 1] == 'D')
				{
					cout << "game ended! u were eaten by the devil" << endl;
					displayMap(word, row, col);
					break;

				}
				else if (word[sx][sy + 1] == 'X')
				{
					cout << "cant move there! there is a wall" << endl;
					displayMap(word, row, col);

				}
				else if (word[sx][sy + 1] == 'G')
				{
					cout << "U met a friendly ghost Gasper!He is teleporting u to the treasure room." << endl;
					displayMap(word, row, col);
					break;

				}
				else if (word[sx][sy + 1] == 'P')
				{
					cout << "U entered a portal! flipping a coin." << endl;
					displayMap(word, row, col);
					break;

					//portal function
				}
			}
			else
			{
				break;
			}
		}
	}
	void displayMap(char**word,int row,int col)
	{
		cout << endl;
		char** m = new char* [row + 2];
		for (int i = 0; i < row+2; i++)
		{
			m[i] = new char[col + 2];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				m[i + 1][j + 1] = word[i][j];
			}
		}
		for (int i = 0; i < row+2; i++)
		{
			m[i][0] = '#';
		}
		for (int i = 0; i < row+2; i++)
		{
			m[i][col+1] = '#';
		}
		for (int i = 0; i < col+2; i++)
		{
			m[0][i] = '#';
		}
		for (int i = 0; i < col+2; i++)
		{
			m[row+1][i] = '#';
		}
		
		for (int i = 0; i < row+2; i++)
		{
			for (int j = 0; j < col+2; j++)
			{
				cout << m[i][j]<<" ";
			}
			cout << endl;
		}
		for (int i = 0; i < row+2; i++)
		{
			for (int j = 0; j < col+2; j++)
			{
				//cout << word[i][j]<<" ";
				if (m[i][j]=='0')
				{
					cout << " ";
				}
				if (m[i][j]=='D')
				{
					cout << " ";
				}
				if (m[i][j]=='P')
				{
					cout << " ";
				}
				if (m[i][j]=='G')
				{
					cout << " ";
				}
				if (m[i][j]=='!')
				{
					cout << "!";
				}
				if (m[i][j]=='#')
				{
					cout << "#";
				}

				if (m[i][j] == 'X')
				{
					cout << "|" ;
				}
			}
			cout << endl;
		}
	}
	void display()
	{
		cout << "## Stack Size : " << top << endl;
		for (i = (top - 1); i >= 0; i--)
			cout << "## Position : " << i << ", Value  :" << arr_stack[i] << endl;
	}
	void hh()
	{
		ifstream hh("hauntedhouse.txt", ios::in);
		if (!hh) {
			cout << "Invalid file.\n";
		}
		else {
			string word;
			int rows = 0;
			string arr[10];

			while (hh >> word)
			{
				arr[rows] = word;
				rows++;
			}
			for (int i = 0; i < rows; i++)
			{
				cout << arr[i] << endl;
			}
		}
		char room = ' ';
		hh >> room;
		cout << room << endl << endl;
	}
	void r1()
	{
		ifstream r1("room1.txt", ios::in);
		int row, col;
		int sx, sy;
		char** word1;
		if (!r1.good()) {
			cout << "Invalid file.\n";
		}
		else
		{
			r1 >> row;
			r1 >> col;
			word1 = new char* [row];
			for (int i = 0; i < row; i++)
			{
				word1[i] = new char[col];
			}

			r1 >> sx;
			r1 >> sy;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					r1 >> word1[i][j];
				}
			}
			word1[sx][sy] = '!';
			displayMap(word1, row, col);
			map(word1, row, col, sx, sy);
		}
	}
	void r2()
	{
		ifstream r2("room2.txt", ios::in);
		int row, col;
		int sx, sy;
		char** word2;
		if (!r2.good()) {
			cout << "Invalid file.\n";
		}
		else
		{
			r2 >> row;
			r2 >> col;
			word2 = new char* [row];
			for (int i = 0; i < row; i++)
			{
				word2[i] = new char[col];
			}

			r2 >> sx;
			r2 >> sy;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					r2 >> word2[i][j];
				}
			}
			word2[sx][sy] = '!';
			displayMap(word2, row, col);
			map(word2, row, col, sx, sy);
		}
	}
	void r3()
	{
		ifstream r3("room3.txt", ios::in);
		int row, col;
		int sx, sy;
		char** word3;
		if (!r3.good()) {
			cout << "Invalid file.\n";
		}
		else
		{
			r3 >> row;
			r3 >> col;
			word3 = new char* [row];
			for (int i = 0; i < row; i++)
			{
				word3[i] = new char[col];
			}

			r3 >> sx;
			r3 >> sy;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					r3 >> word3[i][j];
				}
			}
			word3[sx][sy] = '!';
			displayMap(word3, row, col);
			map(word3, row, col, sx, sy);
		}
	}
	void r4()
	{
		ifstream r3("room4.txt", ios::in);
		int row, col;
		int sx, sy;
		char** word3;
		if (!r3.good()) {
			cout << "Invalid file.\n";
		}
		else
		{
			r3 >> row;
			r3 >> col;
			word3 = new char* [row];
			for (int i = 0; i < row; i++)
			{
				word3[i] = new char[col];
			}

			r3 >> sx;
			r3 >> sy;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					r3 >> word3[i][j];
				}
			}
			word3[sx][sy] = '!';
			displayMap(word3, row, col);
			map(word3, row, col, sx, sy);
		}
	}
	void r5()
	{
		ifstream r3("room5.txt", ios::in);
		int row, col;
		int sx, sy;
		char** word3;
		if (!r3.good()) {
			cout << "Invalid file.\n";
		}
		else
		{
			r3 >> row;
			r3 >> col;
			word3 = new char* [row];
			for (int i = 0; i < row; i++)
			{
				word3[i] = new char[col];
			}

			r3 >> sx;
			r3 >> sy;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					r3 >> word3[i][j];
				}
			}
			word3[sx][sy] = '!';
			displayMap(word3, row, col);
			map(word3, row, col, sx, sy);
		}
	}

	int randomRoom()
	{
		int random;
		random =  (rand() % 5)+1;
		cout << random<<endl;
		return random;
	}
	int randomRoom(int a )
	{
		int random;
		random =  (rand() % 5)+1;
		if (random != a)
		{
			cout << random << endl;
			return random;
		}
		else
		{
			randomRoom(a);
		}
	}
	int randomRoom(int a, int b)
	{
		int random;
		random =  (rand() % 5)+1;
		if (random != a && random != b)
		{
			cout << random << endl;
			return random;
		}
		else
		{
			randomRoom(a, b);
		}
	}
	int randomRoom(int a, int b,int c)
	{
		int random;
		random =  (rand() % 5)+1;
		if (random != a && random != b&&random!=c)
		{
			cout << random << endl;
			return random;
		}
		else
		{
			randomRoom(a, b,c);
		}
	}
	int randomRoom(int a, int b,int c ,int d)
	{
		int random;
		random =  (rand() % 5)+1;
		if (random != a && random != b && random!=c&& random!=d)
		{
			cout << random << endl;
			return random;
		}
		else
		{
			randomRoom(a, b,c,d);
		}
	}

	void callRoom(int d)
	{
		if (d==1)
		{
			r1();
		}
		else if (d==2)
		{
			r2();
		}
		if (d==3)
		{
			r3();
		}
		if (d==4)
		{
			r4();
		}
		if (d==5)
		{
			r5();
		}
	}
};


int main()
{
	srand(time(NULL));
	Stack<char> obj;
	obj.hh();

	int a, b,c,d,e;
	a=obj.randomRoom();
	b=obj.randomRoom(a);
	c=obj.randomRoom(a,b);
	d=obj.randomRoom(a,b,c);
	e=obj.randomRoom(a,b,c,d);
	obj.callRoom(a);
	obj.callRoom(b);
	obj.callRoom(c);
	obj.callRoom(d);
	obj.callRoom(e);
	return 0;
}