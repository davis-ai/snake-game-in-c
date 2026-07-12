#ifndef CONIO_H
#define CONIO_H

#include <termios.h>
#include <fcntl.h>

int setEchoMode ( bool enable )
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~ICANON;

	if ( enable )
		newt.c_lflag |= ECHO;
	else
		newt.c_lflag &= ~ ECHO; 

	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;

}

int getch()
{
	return setEchoMode(false);
}

int kbhit ()
{
	struct termios newt, oldt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);

	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	
	if ( ch != EOF )
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

#endif
