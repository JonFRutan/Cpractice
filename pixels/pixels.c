//jfr
#include "pixels.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;                           //Window from SDL library.
    SDL_Renderer *renderer = NULL;                       //Renderer from SDL library.
    SDL_Rect pixels[PIXEL_COUNT];                        //Array of pixels for the screen, rectangles from SDL.
    int speedX[PIXEL_COUNT], speedY[PIXEL_COUNT];        //Speed for updating x and y, signed because we want negatives. (Maybe direction in future?)
    int coordinate_key[PIXEL_COUNT];                     //FIXME - Implement a quadtree for 2d positioning.
    srand(time(NULL));                                   //Random number generator

    //Creating our pixels
    for (int i=0; i<PIXEL_COUNT; i++) {
        printf("pixel: %d created\n", i);
        pixels[i].h = PIXEL_SIZE;
        pixels[i].w = PIXEL_SIZE;
        pixels[i].x = i*2;           //Offset each pixel by 25 on x
        pixels[i].y = i*2;
     //   coordinate_key[i] = pixels[i].x % pixels[i].y;

        speedX[i] = 10;               //Initial pixel speed x
        speedY[i] = 10;               //Initial pixel speed y
    }

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error initializing SDL - SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    //Create window
    window = SDL_CreateWindow("Pixels", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Error creating window - SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    //Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Error creating renderer - SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    int running = 1;
    int noise = 0;
    SDL_Event e;
    //Game loop
    while (running) {
        //Handle events. PollEvent is an SDL function returns an int, 1 or 0, 1 being an event is available and 0 is no events.
        while (SDL_PollEvent(&e) != 0) {
            //If there is an event it is passed to the address of 'e'
            //e, being an SDL_Event, will be read for what the event was.
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }
        //Move pixels
        for (int i=0; i<PIXEL_COUNT; i++) {
            pixels[i].x += speedX[i];
            pixels[i].y += speedY[i];
        }

        //Check for collions
            for (int i=0; i<PIXEL_COUNT; i++) {
            //Window collisions
            if (pixels[i].x <= 0 || pixels[i].x + PIXEL_SIZE >= WINDOW_WIDTH) {
                speedX[i] = -(speedX[i]);
                if (pixels[i].x <= 0) {
                    pixels[i].x = PIXEL_SIZE;
                }
                else if (pixels[i].x + PIXEL_SIZE >= WINDOW_WIDTH) {
                    pixels[i].x = WINDOW_WIDTH-PIXEL_SIZE;
                }
            }
            if (pixels[i].y <= 0 || pixels[i].y + PIXEL_SIZE >= WINDOW_HEIGHT) {
                speedY[i] = -(speedY[i]);
                if (pixels[i].y <= 0) {
                    pixels[i].y = PIXEL_SIZE;
                }
                else if (pixels[i].y + PIXEL_SIZE >= WINDOW_HEIGHT) {
                    pixels[i].y = WINDOW_HEIGHT-PIXEL_SIZE;
                }
            }
            //coordinate_key[i] = pixels[i].x % pixels[i].y;
            //Other pixel collisions
            //Will be using a hashmap or a quadtree to implement a collision checker.
        }

        //Clears the current frame
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Places the pixel in frame
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        for (int i=0; i<PIXEL_COUNT; i++) {
            SDL_RenderFillRect(renderer, &pixels[i]);
        }

        //Updates to new frame
        SDL_RenderPresent(renderer);

        //Milliseconds before next update
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
