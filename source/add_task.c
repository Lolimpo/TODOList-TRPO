#include "todolib.h"

void add_task()
{
    char input_string[100];
    system("clear");
    printf("Enter your job:");
    fgets(input_string, 100, stdin);
    list = fopen("Todo-List.txt", "a+");
    fprintf(list, "%s", input_string);
    fclose(list);
}
