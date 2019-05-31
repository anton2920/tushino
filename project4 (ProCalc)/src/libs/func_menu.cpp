/*
ProCalc — powerful multifunctional calculator
Copyright © 2019 Tushino Software LLC

This file is part of ProCalc.

ProCalc is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

ProCalc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProCalc. If not, see <https://www.gnu.org/licenses/>.
*/

#include "../headers/header.h"

int choose_function()
{
	/* Initializing variables */
	int func, junk, n;
	struct func foo;

	/* I/O flow */
	while (true) {
		printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                    >> Functions stuff <<                   |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Sine                                              |\n"
"|       2) Cosine                                            |\n"
"|       3) Exponential                                       |\n"
"|       4) Power                                             |\n"
"|       5) Logarithmic                                       |\n"
"|       6) Polynomial                                        |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
		printf("| Answer: ");
		func = getchar();
        prt_ln();
		if (isdigit(func) && func >= '1' && func <= '6') {
			func -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n');
				no_cmd();
				continue;
			}

			switch (func) {
			case 1:
				read(foo, 1);
				break;
			case 2:
				read(foo, 2);
				break;
			case 3:
				read(foo, 3);
				break;
			case 4:
				read(foo, 4);
				break;
			case 5:
				read(foo, 5);
				break;
			case 6:
				read(foo, 6);
				break;
			default:
				break;
			}

            prt_ln();
            print(foo);
            prt_ln();

            while ((junk = getchar()) != '\n')
                ;

            n = func_list(foo);

            if (!n) {
                continue;
            } else if (n == -1) {
                return -1;
            } else {
                return 1;
            }

		}
		else if (func == 'q') {
			if (quit_m()) {
				return -1;
			}
			else {
				continue;
			}
		}
		else if (func == 'b') {
			if (back_m()) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			no_cmd();
			while ((junk = getchar()) != '\n');
			continue;
		}
	}
}

int func_list(func& foo)
{
	/* Initializing variables */
	int func, junk, n;

	/* I/O flow */
	while (true) {
		printf(" ------------------------------------------------------------\n"
"|                                                            |\n"
"|                    >> Functions stuff <<                   |\n"
"|                                                            |\n"
"|  >> Choose a function:                                     |\n"
"|                                                            |\n"
"|       1) Plot a graph (SDL required)                       |\n"
"|       2) Approximately calculate the definite integral     |\n"
"|       3) Find root (Y = 0)                                 |\n"
"|       4) Find extreme points                               |\n"
"|                                                            |\n"
"|       >> Type \"back\" to go to the previous menu <<         |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
		printf("| Answer: ");
		func = getchar();
        prt_ln();
		if (isdigit(func) && func >= '1' && func <= '6') {
			func -= '0';
			if ((junk = getchar()) != '\n') {
				while ((junk = getchar()) != '\n')
                    ;
				no_cmd();
				continue;
			}

			switch (func) {
                case 1:
                #if (HAVE_SDL2_SDL_H == 1 || HAVE_SDL_H == 1 || HAVE_SDL_SDL_H == 1)
                {
                    SDL_Window* window = nullptr;
                    SDL_Renderer* renderer = nullptr;

                    PC computer = {16, 9, 0, 0, 0};

                    if (SDL_start(&window, &renderer, &computer)) {

                        computer.size = computer.window_width / computer.ratio_x;
                        bool close_requested = false;
                        int x_pos = computer.window_height / 2, y_pos = computer.window_width / 2;
                        SDL_Event event;


                        while (!close_requested) {
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_QUIT) {
                                    close_requested = true;
                                    break;
                                } else if (event.type == SDL_KEYDOWN) {
                                    if (event.key.keysym.sym == SDLK_LEFT) {
                                        y_pos += computer.size / 2;
                                    } else if (event.key.keysym.sym == SDLK_RIGHT) {
                                        y_pos -= computer.size / 2;
                                    } else if (event.key.keysym.sym == SDLK_UP) {
                                        x_pos += computer.size / 2;
                                    } else if (event.key.keysym.sym == SDLK_DOWN) {
                                        x_pos -= computer.size / 2;
                                    } else if (event.key.keysym.sym == SDLK_SPACE) {
                                        x_pos = computer.window_height / 2;
                                        y_pos = computer.window_width / 2;
                                    }
                                }
                            }
                            clear_window(renderer);

                            draw_grid(renderer, &computer);
                            draw_y_axis(renderer, y_pos, &computer);
                            draw_x_axis(renderer, x_pos, &computer);
                            plotGraph(renderer, foo, x_pos, y_pos, &computer);
                            SDL_RenderPresent(renderer);

                            SDL_Delay(10);
                        }

                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                    }
                }
                #else
                    std::cout << "| menu: you don't have SDL installed                         |\n";
                    continue;
                #endif
                    ungetc('\n', stdin);
                    break;
                case 2:
                {
                    double x_left, x_right, ans;
                    menu_bounds(&x_left, &x_right);
                    bool check = true;

                    ans = def_int(foo, x_left, x_right, &check);
                    if (check) {
                        std::cout << "| Answer: " << ans << "\n";
                    }
                    prt_ln();
                    break;
                }
                case 3:
                {
                    double x_left, x_right;
                    menu_bounds(&x_left, &x_right);

                    BisectionMethod(foo, x_left, x_right);
                    prt_ln();
                    break;
                }
                case 4:
                {
                    double x_left, x_right;
                    menu_bounds(&x_left, &x_right);

                    extremum(foo, x_left, x_right);
                    break;
                }
                default:
                    break;
			}

            while ((junk = getchar()) != '\n')
                ;

            return 1;

		}
		else if (func == 'q') {
			if (quit_m()) {
				return -1;
			}
			else {
				continue;
			}
		}
		else if (func == 'b') {
			if (back_m()) {
				return 0;
			}
			else {
				continue;
			}
		}
		else {
			no_cmd();
			while ((junk = getchar()) != '\n');
			continue;
		}
	}
}

void menu_bounds(double *l, double *r) {

    /* I/O flow */
    do {
        std::cout << "| Type the left bound: ";
        std::cin >> *l;
        std::cout << "| Type the right bound: ";
        std::cin >> *r;
        prt_ln();
    } while (*l >= *r);
}