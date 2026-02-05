#include <stdio.h>

#define width  40
#define height 20

void draw( char ); 

void setup() {

	draw('+');	

	for (int i = 0; i < height; i++ )
		draw('-');

	draw('+');	
}


int main() {


	setup();

	 return 0;



 }


void draw(char ch) {

	for ( int i = 0; i < width; i++ )
	putchar( ch );
	printf("\n");



}
