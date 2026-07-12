#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "conio.h"

int _kbhit(void);

#define width 50
#define height 25

bool gameOver = false;

int x, y, foodx, foody;
int score;

enum eDirection {STOP=0, UP, DOWN, LEFT, RIGHT};
enum eDirection dir;

void draw( char ); 
void generate_food();
void setup()
{
	x = width/2;
	y = height/2;

	score = 0;

	generate_food();

}

void Input () {

	if (kbhit())
	{
		switch(getch()) 
		{
			case 'w':
				dir = UP;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 's':
				dir = DOWN;	
				break;
			case 'd':
				dir = RIGHT;	
				break;
			default:
				break;
		}
	}

}

void Logic () {
	
	switch (dir)
	{
		case UP:
			y--;
			break;
		case LEFT:
			x--;
			break;
		case DOWN:
			y++;	
			break;
		case RIGHT:	
			x++;
			break;
		default:
			break;
	}

	if ( foodx == x && foody == y )
	{
		generate_food(); 
		score += 1;
	}
}

void Draw() {

	system("clear");

	draw('+');	

	for (int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			if ( j == 0 || j == width-1 )
				putchar('+'); 
			else if ( i == y && j == x ) 
				putchar('o');
			else if ( i == foody && j == foodx )
				putchar('F');
			else 
				putchar('-');
			
		}	
		printf("\n");
	}

	draw('+');	
}


int main() {

	
	setup();

	while ( !gameOver )
	{
		Draw();
		Input();
		Logic();
		sleep(0.9);
	}

	 return 0;



 }

void generate_food()
{
	foodx = rand() % width;
	foody = rand() % height;

}

void draw(char ch) {

	for ( int i = 0; i < width; i++ )
	putchar( ch );
	printf("\n");



}
