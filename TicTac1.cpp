#include "TicTac.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

TicTac::TicTac() //create thse BigBoard with the 9 SmallBoards in it. Use template so that Board array can accept int inputs and Board inputs. Also starts Turn = 0; win = zeros[3,3];
{	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			SmallBoard_1[i][j] = ' ';
			SmallBoard_2[i][j] = ' ';
			SmallBoard_3[i][j] = ' ';
			SmallBoard_4[i][j] = ' ';
			SmallBoard_5[i][j] = ' ';
			SmallBoard_6[i][j] = ' ';
			SmallBoard_7[i][j] = ' ';
			SmallBoard_8[i][j] = ' ';
			SmallBoard_9[i][j] = ' ';
			BigBoard[i][j] = ' ';
			turn = 0; 
		}
	}
}
char TicTac::play(string ButtonName) 
{
	int n2, n1, row, col;
	n2 = ButtonName[8]+1;
	n1 = ButtonName[7]+1;
	//Need to prompt player which box to play in. Also need to allow player to zoom/ unzoom.

	//Now n1 selects which small board and n2 selects which square in the small board to play in. Will assume that player does not select an already taken square for now. 
	//First lets selects the rows and columns of small board.	
	if (n2 < 4)
		row = 0;
	if (n2 < 7 && n2 > 3 )
		row = 1;
	if (n2 < 10 && n2 > 6)
		row = 2;
	col = n2 - 3*row - 1;
	//Find correct small board and place X or O depending on the turn
	if (n1 == 1)                                        //*NOTE* Probably a way to convert strings to code in java but as far as I can google can't with c++. So could make this slimmer in java.
	{
		if (turn%2 == 0)
			SmallBoard_1[row][col] = 'X';
		else
			SmallBoard_1[row][col] = 'O';
	}
	if (n1 == 2)
	{
		if (turn%2 == 0)
			SmallBoard_2[row][col] = 'X';
		else
			SmallBoard_2[row][col] = 'O';
	}
	if (n1 == 3)
	{
		if (turn%2 == 0)
			SmallBoard_3[row][col] = 'X';
		else
			SmallBoard_3[row][col] = 'O';
	}
	if (n1 == 4)
	{
		if (turn%2 == 0)
			SmallBoard_4[row][col] = 'X';
		else
			SmallBoard_4[row][col] = 'O';
	}
	if (n1 == 5)
	{
		if (turn%2 == 0)
			SmallBoard_5[row][col] = 'X';
		else
			SmallBoard_5[row][col] = 'O';
	}
	if (n1 == 6)
	{
		if (turn%2 == 0)
			SmallBoard_6[row][col] = 'X';
		else
			SmallBoard_6[row][col] = 'O';
	}
	if (n1 == 7)
	{
		if (turn%2 == 0)
			SmallBoard_7[row][col] = 'X';
		else
			SmallBoard_7[row][col] = 'O';
	}
	if (n1 == 8)
	{
		if (turn%2 == 0)
			SmallBoard_8[row][col] = 'X';
		else
			SmallBoard_8[row][col] = 'O';
	}
	if (n1 == 9)
	{
		if (turn%2 == 0)
			SmallBoard_9[row][col] = 'X';
		else
			SmallBoard_9[row][col] = 'O';
	}
	if(SmallWin(n1))
	{
		//Play MUSIC
		if (n1 < 4)
			row = 0;
		if (n1 < 7 && n1 > 3 )
			row = 1;
		if (n1 < 10 && n1 > 6)
			row = 2;
		col = n1 - 3*row - 1;
		if (turn%2 == 0 && BigBoard[row][col] == ' ')
			BigBoard[row][col] = 'X';
		if (turn%2 == 1 && BigBoard[row][col] == ' ')
			BigBoard[row][col] = 'O';
		if(BigWin())
		{
			//PLAY MUCHO MUSIC
			turn++;
			if (turn%2 == 0)
				return 'x';
			return 'o';
		}
	}
	turn++;
	if (turn%2 == 0)
		return 'X';
	return 'O';
}
bool TicTac::isFull(int n1)
{
	int count = 0;
	if (n1 == 1)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_1[i][j] == 'X' || SmallBoard_1[i][j] == 'O')
					count++;
	if (n1 == 2)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_2[i][j] == 'X' || SmallBoard_2[i][j] == 'O')
					count++;
	if (n1 == 3)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_3[i][j] == 'X' || SmallBoard_3[i][j] == 'O')
					count++;
	if (n1 == 4)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_4[i][j] == 'X' || SmallBoard_4[i][j] == 'O')
					count++;
	if (n1 == 5)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_5[i][j] == 'X' || SmallBoard_5[i][j] == 'O')
					count++;
	if (n1 == 6)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_6[i][j] == 'X' || SmallBoard_6[i][j] == 'O')
					count++;
	if (n1 == 7)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_7[i][j] == 'X' || SmallBoard_7[i][j] == 'O')
					count++;
	if (n1 == 8)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_8[i][j] == 'X' || SmallBoard_8[i][j] == 'O')
					count++;
	if (n1 == 9)
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++)
				if (SmallBoard_9[i][j] == 'X' || SmallBoard_9[i][j] == 'O')
					count++;	
	if (count == 9)
		return true;
	return false;		
}
bool TicTac::BigWin()
{
	//Must be 3 in a row on BigBoard: [; 
	//all rows, cols, or diagnols are all X's or O's

	//Check rows and columns first
	int count;
	for (int i = 0; i < 3; i++)
	{
		count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (BigBoard[i][j] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (BigBoard[i][j] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (BigBoard[j][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (BigBoard[j][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
	}
	//check Diagnols 
	count = 0;
	for (int i = 0; i < 3; i ++)
	{
		if (BigBoard[i][i] == 'X')
			count++;
		if (count == 3)
			return true;
	}
	count = 0;
	for (int i = 0; i < 3; i ++)
	{
		if (BigBoard[i][i] == 'O')
			count++;
		if (count == 3)
			return true;
	}
	count = 0;
	for (int i = 0; i < 3; i ++)
	{
		if (BigBoard[2-i][i] == 'X')
			count++;
		if (count == 3)
			return true;
	}
	count = 0;
	for (int i = 0; i < 3; i ++)
	{
		if (BigBoard[2-i][i] == 'O')
			count++;
		if (count == 3)
			return true;
	}
	return false;
}
bool TicTac::SmallWin(int n1) //Again can make like much slimmer in java by augmenting a string SmallBoard_ with n1 then turning the string into code in java but not c++ as far as I know.
{
	int count;
	if (n1 == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_1[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_1[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_1[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_1[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_1[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_1[i][i] == 'O')
				count++;
			if (count == 3)
			return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_1[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_1[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_2[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_2[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_2[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_2[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_2[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_2[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_2[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_2[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_3[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_3[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_3[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_3[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_3[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_3[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_3[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_3[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 4)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_4[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_4[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_4[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_4[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_4[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_4[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_4[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_4[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 5)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_5[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_5[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_5[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_5[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_5[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_5[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_5[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_5[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 6)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_6[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_6[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_6[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_6[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_6[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_6[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_6[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_6[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 7)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_7[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_7[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_7[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_7[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_7[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_7[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_7[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_7[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 8)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_8[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_8[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_8[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_8[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_8[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_8[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_8[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_8[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	if (n1 == 9)
	{
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_9[i][j] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_9[i][j] == 'O')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_9[j][i] == 'X')
					count++;
				if (count == 3)
					return true;
			}
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (SmallBoard_9[j][i] == 'O')
					count++;
				if (count == 3)
					return true;
			}
		}
		//check Diagnols 
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_9[i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_9[i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_9[2-i][i] == 'X')
				count++;
			if (count == 3)
				return true;
		}
		count = 0;
		for (int i = 0; i < 3; i ++)
		{
			if (SmallBoard_9[2-i][i] == 'O')
				count++;
			if (count == 3)
				return true;
		}
		return false;
	}
	
}
void TicTac::SeeBig() 
{	
	
}
void TicTac::SeeWin()
{
	
}
void TicTac::SeeSmall(int n1) //Am not including borders for the smallBoards since it should be better in java. So it is hard to read atm
{
	
}