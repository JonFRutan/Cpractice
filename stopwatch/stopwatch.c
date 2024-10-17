#include "stopwatch.h"

static clock_t start, stop;
static double cpu_time_elapsed;

int main() {
    printf("Running stopwatch test...\n");
    start_watch(&start);
    unsigned int count = 0;
    for (int i=0;i<TEST_TIME;i++) {
        count++;
        printf("\r%d/%d", count, TEST_TIME);
        fflush(stdout);
    }
    printf("\n");
    stop_watch(&stop);
    print_cpu_time(get_cpu_time_elapsed());
}


void start_watch(clock_t *start) {
    *start = clock();
}

void stop_watch(clock_t *stop) {
    *stop = clock();
}

double get_cpu_time_elapsed() {
    cpu_time_elapsed = ((double)(stop - start)) / CLOCKS_PER_SEC;
    return cpu_time_elapsed;
}

void print_cpu_time(double cpu_time) {
    printf("%f seconds of CPU usage.", cpu_time);
}