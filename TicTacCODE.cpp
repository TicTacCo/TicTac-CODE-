#include <iostream>
#include "TicTac.h"


using namespace std;

int main()
{
	/*		To start the game, need to initialize the game with TicTac constructor. Will create 9 small boads 
	and 1 big board. SmallBoads will be called SmallBoard_1 - SmallBoard_9 and the big board will be called BigBoard.
	The constructor will also created the create the Turn counter to determine if it is Player1 (X) or Player 2 (O).
	The boards will simply be 3x3 char arrays that are initially empty but will be filled with X's and O's.  */

	TicTac game;

	/*		Need to play the game. To start the game need to use the ***play*** member function to select which small board 
	and what box in the small board. This requires 2 inputs. The first input refereces the square supposed to be played and 
	is situation specific. It will only	be used if its the first move, or if the small board that is supposed to be played
	on is full. This will be checked with the ***bool isFull*** member function which will use 1 input referencing the small board 
	supposed to be played. If *Turn* != 0 and *isFull* returns false, the player cannot select which small board only the box in
	the small board. The small board being played is simply the second input from the last *play* function call. The player will
	only be allowed to play in a square that has not already beeadfn taken. So the player will see the smallboard after it has been
	selected and will only be allowed to select an empty square. Once selects an open square, it will be filled with an X or an O 
	if Turn is even or odd. If even, it is X, if odd it is O. Turn will be incremented and then the ***bool SmallWin*** member function
	will be called to determine if the small board was won. If it is won, the BigBoard will be filled with an X or O in the small board 
	just played. Then the ***bool BigWin*** member function will be called if *SmallWin* was called to check if the player won on the
	big board. If BigWin returns true, Will output a Congratulations to the winner and end the game. If SmallWin is false or BigWin is 
	false, *play* function is called. So essentially loop *play* until BigWin returns true. Will use ***SeeSmall*** and ***SeeBig***
	member functions to zoom in and out of the boards. */
	int n2 = 1, n1; 
	while (game.BigWin() == 0) //or Turn != End OF Game
	{
		if (game.turn != 0 && game.isFull(n1) == 0 ) //if needed, can make turn private and use a getTurn member function instead
		{
			n1=n2;
			n2 = game.play(n1); //second input will be called in the play member function. 
		}
		if (game.turn == 0 || game.isFull(n1) ==1)
		{
			game.SeeBig(); //Print out entire board. Probably different in Android Studio
			//Prompt player to select which small board
			cout<<"Select Small Board (1-9)\n"; //Probably be much different in Android Studio. Like should just click on the square
			cin>>n1;
			n2 = game.play(n1);
		}
	}
}