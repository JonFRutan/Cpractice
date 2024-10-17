//jfr
#ifndef STOPWATCH_H
#define STOPWATCH_H

#define TEST_TIME 1500000

#include <stdio.h>
#include <time.h>
#include <unistd.h> 

void start_watch(clock_t *start);
void stop_watch(clock_t *stop);
double get_cpu_time_elapsed();
void print_cpu_time(double cpu_time);

#endif