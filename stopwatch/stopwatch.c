#include "stopwatch.h"

static clock_t start, stop;     //Start and stop are the elapsed number of ticks since the program began.
static double cpu_time_elapsed;

//grabs current tick since program began
void start_watch() {
    start = clock();
}

//grabs current tick since program began
void stop_watch() {
    stop = clock();
}

//Calculates the total CPU time taken up.
//If our program starts timing at tick 1000, and stops at tick 2000, we have (2000-1000) / The amount of clock cycles a second for our CPU.
double get_cpu_time_elapsed() {
    cpu_time_elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
    return cpu_time_elapsed;
}

//useless function
void print_cpu_time(double cpu_time) {
    printf("%f seconds of CPU usage.", cpu_time);
}

//main is for testing the stopwatch, calling with an argument will count based on the provided number.
//To compile and use main: gcc -DTEST stopwatch.c -o stopwatch.exe
#ifdef TEST
int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Not enough arguments- provide a MAX int for testing.\n");
        return 1;
    }
    unsigned int count_max = atoi(argv[1]);
    if (!count_max) {
        printf("Provide an int > 0\n");
        return 1;
    }
    printf("Running stopwatch test...\n");
    start_watch();
    unsigned int count = 0;
    for (int i=0;i<count_max;i++) {
        count++;
        printf("\r%d/%d", count, count_max);       //Prints current iteration out of our max
        fflush(stdout);                            //Flushes the programs output
    }
    printf("\n");
    stop_watch();
    print_cpu_time(get_cpu_time_elapsed());
    printf("\n");
    return 0;
}
#endif

