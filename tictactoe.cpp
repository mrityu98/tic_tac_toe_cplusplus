#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // Initial board .
char current_marker;
int finished;
int error;
char c;
char ch;
int current_player;
void drawboard() //Displays the tic-tac-toe board.
{
	cout<<" "<<board[0][0]<<" |"<<" "<<board[0][1]<<" |"<<" "<<board[0][2]<<endl;
	cout<<"-----------\n";
	cout<<" "<<board[1][0]<<" |"<<" "<<board[1][1]<<" |"<<" "<<board[1][2]<<endl;
	cout<<"-----------\n";
	cout<<" "<<board[2][0]<<" |"<<" "<<board[2][1]<<" |"<<" "<<board[2][2]<<endl;
}
void place_marker(int slot) //This function is used to map the slot to the corresponding marker.
{
    
	int row_number,column_number;
	row_number= slot / 3;
	if(slot % 3 == 0)
	{
		row_number = row_number - 1;
		column_number = 2;
	}
	else
	{
	column_number = slot % 3 - 1;
   }
	if((current_marker == ch) && (board[row_number][column_number] == ch ))
	{
	cout<<"This slot has already been marked by you. Please retry "<<endl;
	error=1;
    }
	else if((current_marker == c) && (board[row_number][column_number] == ch))
	{
	cout<<"This slot has already been marked by the other player.Please retry "<<endl;
	error=1;
    }
    else if((current_marker == ch) && (board[row_number][column_number] == c ))
	{
	cout<<"This slot has already been marked by the other player.Please retry "<<endl;
	error=1;
    }
	else if((current_marker == c) && (board[row_number][column_number] == c))
	{
	cout<<"This slot has already been marked by you. Please retry "<<endl;
	error=1;
    }
	else
	board[row_number][column_number] = current_marker;
	 
}
int winner() //This function checks if the current state of the board leads to any winner or not.
{
	for(int k=0; k<3;k++)
	{
		if(board[k][0] == board[k][1] && board[k][1] == board[k][2])
		return current_player;
		if(board[0][k] == board[1][k] && board[1][k] == board[2][k])
		return current_player;
		
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
	return current_player;
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
	return current_player;
	return 0;
}
void game() //This is the place from where the game actually starts.
{
	//Both players choose their own markers.
	cout<<"Player 1 , enter your marker "<<endl; 
	cin>>c;
	cout<<"Player 2 , choose your marker "<<endl;
	cin>>ch;
	drawboard();
	//
	for(int i=0;i<9;i++)
	{
		if(i%2==0)
		{
		current_player=1;
		current_marker=c;
	    }
		else
		{
		current_player=2;
		current_marker=ch;
	    }
    	
		Loop:
	    cout<<"Player "<<current_player<<" enter your slot "<<endl;
		int s;
		cin>>s;
		place_marker(s);
		if(error==1)
		{
			error=0;
			goto Loop;
		}
		drawboard();
		switch(winner()) // Checks for a winner after every move.
		{
			case 1:cout<<"Player 1 has won!!!";
			       finished = 1;
			       break;
		    case 2:cout<<"Player 2 has won!!!";
		          finished = 1;
		          break;
		    
		}
		if(finished == 1) // A winner has been found!!
		break;
	}
	if(finished == 0)      //If no winner is possible , then display the below print statement.
	cout<<" This Match has no winner"<<endl;
}

int main() // The game starts from this main function.
{
game();
}
