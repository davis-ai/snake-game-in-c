CC = gcc
OBJ = main
EXC = main.c

$(OBJ) : $(EXC)
	$(CC) -o $(OBJ) $(EXC)
