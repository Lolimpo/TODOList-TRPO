#include "todolib.h"

int menu()
{
    int m;
    while(1)
    {
        puts("1. View your TODO-List");
        puts("2. Add new task");
        puts("3. Mark task as done");
        puts("4. Delete tasks");
        puts("0. Exit program");
        puts("What would you like to do next?");
        scanf("%d%*c",&m);
        switch(m)
        {
            case 1:
                view_list(); break;
            case 2:
                add_task(); break;
            case 3:
                mark_done(); break;
            case 4:
                system("clear");
                puts("1. Delete 1 task");
                puts("2. Delete all current tasks");
                puts("0. Return to main menu");
                scanf("%d%*c",&m);
                switch(m)
                {
                    case 1: delete_task(); menu(); break;
                    case 2: delete_list(); menu(); break;
                    case 0: system("clear"); menu(); break;
                }
            case 0: return 0;
            default : puts("No such command");
        }
    }
}
