#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *list;

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

void view_list()
{
    char str[60];
    char *estr;
    system("clear");
    puts("Your decided jobs:");
    list = fopen("Todo-List.txt", "r");
    if (list == NULL)
        printf("You have no current plans");
    else
    {
        while(!feof(list))
        {
            estr = fgets(str, sizeof(str), list);
            if(estr != NULL)
                printf("%s", str);
        }
        fclose(list);
    }
    puts("\n");
}

void delete_task()
{
    int del_num;
    int i = 0;
    char str[50][100];
    system("clear");
    view_list();
    printf("Which job would you like to delete?");
    scanf("%d", &del_num);
    list = fopen("Todo-List.txt", "r");
    if (list != NULL)
    {
        while(!feof(list))
        {
            fgets(str[i], 100, list);
            i++;
        }
        fclose(list);
        list = fopen("Todo-List.txt", "w");
        int str_num = i;
        i = 0;
        str[del_num - 2][100] = 0;
        while (i < str_num)
        {
            if (str[i] != 0)
                fprintf(list, "%s", str[i]);
            i++;
        }
    }
    fclose(list);
}

int menu()
{
    char m;
    while(1)
    {
        puts("1. View your TODO-List");
        puts("2. Add new task");
        puts("3. Mark task as done");
        puts("4. Delete task completely");
        puts("0. Exit program");
        puts("What would you like to do next?");
        m = getchar();
        putchar(getchar());
        switch(m)
        {
            case '1': view_list(); break;
            case '2': add_task(); break;
            //case '3': mark_done (list); break;
            case '4': delete_task(); break;
            case '0': return 0;
            default : puts("No such command");
        }
    }
}
