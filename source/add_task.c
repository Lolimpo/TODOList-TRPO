#include "todolib.h"

void add_task(char input_string[100])
{
    list = fopen("Todo-List.txt", "a+");
    fprintf(list, "%s", input_string);
    fclose(list);
}
