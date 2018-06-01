#ifndef TODOLIB_H_
#define TODOLIB_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *list;
int menu();
void add_task(char input_string[100]);
void view_list();
void mark_done();
void delete_task();
void delete_list();

#endif
