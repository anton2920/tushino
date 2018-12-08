#ifndef HEADER_FILE
#define HEADER_FILE

#define SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read_key(int *, const int *);
void read_rand(int *, const int *);
void read_file(int *, const int *);
void read_bfile(int *, const int *);
void write_scr(const int *, const int *);
void write_file(const int *, const int *);
void write_bfile(const int *, const int *);
int menu(void);
int menu2(void);
int menu3(void);
int num_elem(void);
void task(int *, int);

/* Custom */
void swap(int *, int *);
int rand_number(int, int);
void max_min(int *, int *, const int *, int);

#endif