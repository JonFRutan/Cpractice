#include "main.h"

int main () {
    initscr();
    noecho();
    curs_set(FALSE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    screen_main_loop();
    endwin();
    printf("Finished.\n\n");
}

int screen_main_loop() {
    int x_pos = 20;
    int x_speed = 1;
    int y_pos = 10;
    int y_speed = 1;
    int x_max = 50;
    int y_max = 50;
    char guy[2];
    char *guys[4];
    guys[0] = "\\";
    guys[1] = "|";
    guys[2] = "/";
    guys[3] = "-";

    for (int frame=0; frame<2000; frame++) {
        clear();
        strcpy(guy, guys[frame%4]);
        mvprintw(y_pos, x_pos, guy);
        getmaxyx(stdscr, y_max, x_max);
        update_x(&x_pos, &x_speed, x_max);
        update_y(&y_pos, &y_speed, y_max);
        refresh();
        napms(30);
    }
    return 0;
}

void initialize_frame (char frame[RENDER_HEIGHT][RENDER_WIDTH]) {
    for (int i=0;i<RENDER_HEIGHT; i++) {
        for (int j=0;j<RENDER_WIDTH;j++) {
            frame[i][j] = '-';
        }
    }
}

int update_x(int *x, int *x_speed, int max) {
    if (*x <= 0 || *x >= max) {
        *x_speed = -(*x_speed);
        *x = *x + *x_speed;
        return 1;
    }
    else {
        *x = *x + *x_speed;
        return 1;
    }
}

int update_y(int *y, int *y_speed, int max) {
    if (*y <= 0 || *y >= max) {
        *y_speed = -(*y_speed);
        *y = *y + *y_speed;
        return 1;
    }
    else {
        *y = *y + *y_speed;
        return 1;
    }
}