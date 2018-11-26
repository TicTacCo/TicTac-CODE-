#ifndef TICTAC_H
#define TICTAC_H
#include <iostream>

class TicTac
{		
	public: 
		int turn;
		TicTac(); 
		int play(int n1);
		bool isFull(int n1);
		bool BigWin();
		bool SmallWin(int n1);
		void SeeBig();
		void SeeSmall(int n1);
	private: 
		char SmallBoard_1[3][3];
		char SmallBoard_2[3][3];
		char SmallBoard_3[3][3];
		char SmallBoard_4[3][3];
		char SmallBoard_5[3][3];
		char SmallBoard_6[3][3];
		char SmallBoard_7[3][3];
		char SmallBoard_8[3][3];
		char SmallBoard_9[3][3];
		char BigBoard[3][3];		 
};


#endif

//MIGHT NEED TO MAKE 2 SEPARATE FILES FOR TICTAC AND BOARD