//jfr
#ifndef STOPWATCH_H
#define STOPWATCH_H

#define TEST_TIME 1500000

#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

void start_watch();
void stop_watch();
double get_cpu_time_elapsed();
void print_cpu_time(double cpu_time);

#endif
