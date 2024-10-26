//jfr
#ifndef VENUS_H
#define VENUS_H

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#define WINDOW_WIDTH 128
#define WINDOW_HEIGHT 30
#define FIGURE "#"

typedef struct {
	int x_cor;
	int y_cor;
	int x_velocity;
	int y_velocity;
	char visual;
} Figure;


int main_loop(WINDOW *fixed_window);
int update_position(Figure *figure);



#endif
