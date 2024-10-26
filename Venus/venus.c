//jfr
#include "venus.h"

int main(int argc, char *argv[]) {
    initscr();
    noecho();
    curs_set(FALSE);
    WINDOW *fixed_window = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
    //border('|', '|', '=', '=', '@', '@', '@', '@');
    nodelay(stdscr, TRUE);  //This tells the system *not* to wait for user input.
    int status_code = main_loop(fixed_window);
    printf("Process status: %d\n", status_code);
    endwin();
    return 0;
}

int main_loop(WINDOW *fixed_window) {
    int shape_size = 25;
    int user_input = ERR; //ERR for no input.
    Figure figure = {5, 5, 1, 0, '@'};
    while (shape_size) {
        user_input = getch();
        switch (user_input) {
            case 'q':
                return 0;
                break;
            default:
                break;
        }
        update_position(&figure);
        //werase(fixed_window); //erases everything window the borders of the window, probably not useful when trying to "render" objects.
        refresh();
        napms(25);
    }
    return 1;
}

int update_position(Figure *figure) {
	if (figure->x_cor + 1 < WINDOW_WIDTH) { figure->x_cor += figure->x_velocity; }
	else { figure->y_velocity = 1; figure->x_velocity = 0; }
	
	if (figure->y_cor < WINDOW_HEIGHT) { figure->y_cor += figure->y_velocity; }
	else { figure->x_velocity = 1; figure->y_velocity = 0; }

	if (!figure->x_velocity && !figure->y_velocity) {figure->x_velocity--; ;}
    mvprintw(figure->y_cor, figure->x_cor, "#");
	
	return 1;
}


