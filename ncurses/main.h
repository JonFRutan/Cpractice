#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "../stopwatch/stopwatch.h"

#define RENDER_WIDTH 250
#define RENDER_HEIGHT 250

//void initialize_frame(char frame[RENDER_HEIGHT][RENDER_WIDTH]);
int screen_main_loop(unsigned int max_frames, double *x_times, double *y_times);
//double update_x(int *x, int *x_speed, int max);
//double update_y(int *y, int *y_speed, int max);
double update_position(int *position, int *pos_speed, int max);
int grab_screen();


#endif
