#include <iostream>
#include <ncurses.h>

using namespace std; 

//enumerator
enum sDirect { STOP = 0, LEFT, RIGHT, UP, DOWN };
sDirect dir;

//variables
bool gameOver; 
const int board_width = 30; 
const int board_length = 20;
char board[board_width][board_length];
int x, y, ball_Y, ball_X, score;

using namespace std;

void gameStart(){

	// ncurses settings
	initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE); 
    nodelay(stdscr, TRUE); 

	//set the start settings
	gameOver = false;
	dir = STOP;
	x = board_length/2;
	y = board_width/2; 
	ball_X = rand() % board_length;
	ball_Y = rand() % board_width;
	score = 0;

}

void draw(WINDOW * win){

	box(win, 0, 0); 
	wrefresh(win);

	// mvwprintw(win, 0, 0, "Score: %i", score);

}

void userInput(){

	switch (getch()){

		case 'a':
			dir = LEFT;
			// printw("LEFT\n"); 
			break; 
		case 's':
			dir = DOWN;
			// printw("DOWN\n"); 
			break; 
		case 'd': 
			dir = RIGHT; 
			// printw("RIGHT\n");
			break; 
		case 'w':
			dir = UP;
			// printw("UP\n"); 
			break; 
		// testing
		case 'q':
			gameOver = true;
			break; 
	}
	// napms(200);
	// printw("Running\n");

}

int main(){

	gameStart(); 

	//main window
	WINDOW * win = newwin(board_length, board_width, 10, 10);
	refresh(); 

	while(!gameOver){
		draw(win);
		userInput(); 
	}

	int test = getch(); 

	endwin(); 
	return 0;
}