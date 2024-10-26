//jfr
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
    start_watch();
    screen_main_loop(max_frames, x_times, y_times);              //Initiates main screen loop
    endwin();                                  //Ends the current window
    stop_watch();
    double time_elapsed = get_cpu_time_elapsed();
    //double total_time_difference = 0;
    //double frame_time_difference = 0;
    //for (int i=0; i<max_frames; i++) {
    //    frame_time_difference = x_times[i]-y_times[i];
    //    printf("X: %f  |  Y: %f  |  DIFF: %f \n", x_times[i], y_times[i], frame_time_difference);
    //    total_time_difference += frame_time_difference;
    //}
    //printf("Total time difference: %f\n", total_time_difference);
    //printf("A postitive difference indicates update_y is faster, negative indicates update_x is faster.\n");
    printf("Finished using %f CPU seconds.\n", time_elapsed);
    return 0;
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

    guys[0] = "|";
    guys[1] = "/";
    guys[2] = "-";
    guys[3] = "\\";

    for (int frame=0; frame<max_frames; frame++) {
        clear();                               //clears screen
        strcpy(guy, guys[(frame%64)/16]);        //Framely updates of our object, notice every "sprite" will run for 4 frames.
        //We can "slow" the sprite of our character by following a short formula:
        // [i%(B^S)]/B^(S-1)  - Where i is our iteration (frame here), B is our base (4 here), and S is our "Slowdown" (4 here)
        mvprintw(y_pos, x_pos, guy);           //Prints the object to the correct location
        getmaxyx(stdscr, y_max, x_max);        //Grabs the screen size, and sets the correct maxes.
        y_times[frame] = update_position(&y_pos, &y_speed, y_max);     //Next y-position
        x_times[frame] = update_position(&x_pos, &x_speed, x_max);     //Next x-position
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

//Takes an axis position and the axis speed and calculates the next position.
//This returns a double for timing purposes.
double update_position(int *position, int *pos_speed, int max) {
    start_watch();
    int rng = 2 * (~(*pos_speed >> 15));
    int next = *position + *pos_speed;
    if (next < 0 || next > max) {
        *pos_speed = -(*pos_speed);
        next += rng;
    }
    *position = next;
    stop_watch();
    return get_cpu_time_elapsed();
}
