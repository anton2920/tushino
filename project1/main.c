#include "headers/head.h"

main() {

	/* Intializing variables */
	int func, func2, func3;
	int mas[SIZE], n;
	srand((unsigned int) time(NULL));

	/* I/O flow */
	while (1) {
		n = num_elem();
		switch ((func = menu())) {
			case 1:
				read_key(mas, &n);
				break;
			case 4:
				read_rand(mas, &n);
				break;
			case 2:
				read_file(mas, &n);
				break;
			case 3:
				read_bfile(mas, &n);
				break;
			default:
				break;
		}

		/* Main part */
		printf("Base array: \n");
		write_scr(mas, &n);
		task(mas, n);

		switch ((func2 = menu2())) {
			case 1:
				printf("New array: \n");
				write_scr(mas, &n);
				break;
			case 2:
				printf("New array: \n");
				write_scr(mas, &n);
				write_file(mas, &n);
				break;
			case 3:
				printf("New array: \n");
				write_scr(mas, &n);
				write_bfile(mas, &n);
				break;
			case 23: case 32:
				printf("New array: \n");
				write_scr(mas, &n);
				write_file(mas, &n);
				write_bfile(mas, &n);
				break;
			default:
				break;
		}
		if ((func3 = menu3())) {
			continue;
		} else {
			break;
		}
	}
}