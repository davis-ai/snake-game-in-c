#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define width  50
#define height 40

bool gameOver = false;

void draw( char ); 

void setup() {

	system("clear");

	draw('+');	

	for (int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			if ( j == 0 || j == width-1 )
			{
				putchar('+'); 
			} else {
				 putchar('-');
			}
		}	
		printf("\n");
	}

	draw('+');	
}


int main() {

	while ( !gameOver )
	{
		setup();
		sleep(40);
	}

	 return 0;



 }


void draw(char ch) {

	for ( int i = 0; i < width; i++ )
	putchar( ch );
	printf("\n");



}
