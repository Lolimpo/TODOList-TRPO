#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_task()
{
    FILE *input;
    char a[100];
    system("clear");
    printf("Enter your decided job:");
    fgets(a, 100, stdin);
    input = fopen("Todo-List.txt", "a+");
    fprintf(input, "%s", a);
    fclose(input);
}

void view_list(FILE *input)
{
    char str[60];
    char *estr;
    puts("Your decided jobs:");
    input = fopen("Todo-List.txt", "r");
    while(!feof(input))
    {
        estr = fgets(str, sizeof(str), input);
        if(estr != NULL)
        printf("%s", str);
    }
    fclose(input);
}

int menu()
{
    char m;
    while(1)
    {
        system("clear");
        puts("1. View your TODO-List");
        puts("2. Add new task");
        puts("3. Mark task as done");
        puts("4. Delete task completely");
        puts("0. Exit program");
        puts("What would you like to do next?");
        m = getchar();
        putchar (getchar());
        switch (m)
        {
            //case '1': view_list (list); break;
            case '2': add_task(); break;
            //case '3': mark_done (list); break;
            //case '4': delete_task (list); break;
            case '0': return 0;
            default : puts("No such command");
        }
    }
}
