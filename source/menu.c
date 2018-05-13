#include <stdio.h>
#include <stdlib.h>
#include "todolib.h"

void menu ()
{
    char m;
    while (1)
    {
        system ("clear");
        puts ("1. View your TODO-List");
        puts ("2. Add new task");
        puts ("3. Mark task as done");
        puts ("4. Delete task completely");
        puts ("0. Exit program");
        m = getchar();
        switch (m)
        {
            case '1': view_list (list); break;
            case '2': add_task (list); break;
            case '3': mark_done (list); break;
            case '4': delete_task (list); break;
            case '0': return 0;
            default : puts ("No such command");
        }
}
