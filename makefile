all:
	gcc *.c -o tetris -Iinclude/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11