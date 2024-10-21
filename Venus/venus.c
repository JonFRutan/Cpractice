#include "venus.h"

int main(int argc, char *argv[]) {
    initscr();
    noecho();
    curs_set(FALSE);
    WINDOW *fixed_window = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
    border('|', '|', '=', '=', '@', '@', '@', '@');
    int status_code = main_loop(fixed_window);
    printf("Process status: %d", status_code);
    endwin();
    return 0;
}

int main_loop(WINDOW *fixed_window) {
    int running = 1;
    int user_input = ERR; //'n' for no input.
    int x_cor = 25, y_cor = 25;
    mvprintw(y_cor, x_cor, FIGURE);
    while (running) {
        user_input = getch();
        mvprintw(y_cor, x_cor, " ");
        switch (user_input) {
            case 'w':
            	if (y_cor > 1) { y_cor--; }
                break;
            case 's':
                if (y_cor < WINDOW_HEIGHT - 1) { y_cor++; }
                break;
            case 'd':
            	if (x_cor < WINDOW_WIDTH - 1 ) { x_cor++; } 
                //x_cor += (x_cor+1 & WINDOW_WIDTH); 
                break;
            case 'a':
                if (x_cor > 0) { x_cor--; }
                break;
            case 'q':
                return 0;
                break;

            default:
                break;
        }
        werase(fixed_window); //erases everything window the borders of the window, probably not useful when trying to "render" objects.
        mvprintw(y_cor, x_cor, FIGURE);
        refresh();
        napms(30);
    }
    return 1;
}


