#include <iostream>

//enumerator
enum sDirect { STOP = 0, LEFT, RIGHT, UP, DOWN };
sDirect dir;

//variables
bool gameOver; 
const int board_width = 30; 
const int board_length = 30;
char board[board_width][board_length];
int x, y, ball_Y, ball_X, score;
using namespace std;

void gameStart(){

	//set the start settings
	gameOver = false;
	dir = STOP;
	x = board_length/2;
	y = board_width/2; 
	ball_X = rand() % board_length;
	ball_Y = rand() % board_width;
	score = 0;

}

void draw(){

	system("clear");

	for(int i = 0; i < board_length; i++){

		for(int j = 0; j < board_width; j++){

			if (i == 0 || i == board_length - 1) {

			    board[i][j] = '0';

			}else if (j == 0 || j == board_width - 1){

				board[i][j] = '0'; 

			}else{

				board[i][j] = ' ';
			}

			std::cout << board[i][j];
		}

		std::cout << endl;
	}

}

int main(){

	std::cout << "Hello there!\n";
	draw();
	return 0;
}