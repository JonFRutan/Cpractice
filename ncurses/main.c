#include "main.h"

int main (int argc, char *argv[]) {
    //clock_t start, stop;
    unsigned int max_frames = 1000;
    if (argc >= 2) {
        max_frames = atoi(argv[1]);
        if (!max_frames) { printf("Invalid argument. Provide an int.\n"); return 0; }
    }
    double x_times[max_frames], y_times[max_frames];
    initscr();                                 //Creates window
    noecho();                                  //Prevents input from being displayed in window
    curs_set(FALSE);                           //Removes cursor from the window
    //start_color();
    //init_pair(1, COLOR_BLUE, COLOR_BLACK);
    //start_watch();
    screen_main_loop(max_frames, x_times, y_times);              //Initiates main screen loop
    endwin();                                  //Ends the current window
    //stop_watch();
    //double time_elapsed = get_cpu_time_elapsed();
    double total_time_difference = 0;
    double frame_time_difference = 0;
    for (int i=0; i<max_frames; i++) {
        frame_time_difference = x_times[i]-y_times[i];
        printf("X: %f  |  Y: %f  |  DIFF: %f \n", x_times[i], y_times[i], frame_time_difference);
        total_time_difference += frame_time_difference;
    }
    printf("Total time difference: %f\n", total_time_difference);
    printf("A postitive difference indicates update_y is faster, negative indicates update_x is faster.\n");
    printf("Finished.\n");
}

int screen_main_loop(unsigned int max_frames, double *x_times, double *y_times) {
    int x_pos = 20;         //x value of rendered object
    int x_speed = 1;        //distance object travels along x-axis every loop
    int y_pos = 10;         //y value of rendered object
    int y_speed = 1;        //distance object travels along y-axis every loop
    int x_max = 50;         //Max value of x coordinate (changes w/ window size)
    int y_max = 50;         //Max value of y coordinate (changes w/ window size)
    char guy[2];            //Our object to be rendered
    char *guys[4];          //This is an array of our objects states it can appear as.

    guys[0] = "=";
    guys[1] = "+";
    guys[2] = "-";
    guys[3] = "*";

    for (int frame=0; frame<max_frames; frame++) {
        clear();                               //clears screen
        strcpy(guy, guys[frame%4]);            //Framely updates of our object
        mvprintw(y_pos, x_pos, guy);           //Prints the object to the correct location
        getmaxyx(stdscr, y_max, x_max);        //Grabs the screen size, and sets the correct maxes.
        x_times[frame] = update_x(&x_pos, &x_speed, x_max);     //Next x-position
        y_times[frame] = update_y(&y_pos, &y_speed, y_max);     //Next y-position
        refresh();
        napms(30);
    }
    return 0;
}

// void initialize_frame (char frame[RENDER_HEIGHT][RENDER_WIDTH]) {
//     for (int i=0;i<RENDER_HEIGHT; i++) {
//         for (int j=0;j<RENDER_WIDTH;j++) {
//             frame[i][j] = '-';
//         }
//     }
// }

double update_x(int *x, int *x_speed, int max) {
    start_watch();
    if (*x <= 0 || *x >= max) {
        *x_speed = -(*x_speed);
    }
    *x = *x + *x_speed;
    stop_watch();
    return get_cpu_time_elapsed();
}

//The timers seem to indicate that this function is slightly faster than update_x.
double update_y(int *y, int *y_speed, int max) {
    start_watch();
    int oob = *y + *y_speed;
    oob = ((oob <= 0) || (oob >= max));
    if (oob) {
        *y_speed = -(*y_speed);
    }
    *y = *y + *y_speed;
    stop_watch();
    return get_cpu_time_elapsed();
}
