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
    char str[100];
    char *estr;
    system("clear");
    puts("Your decided jobs:");
    list = fopen("Todo-List.txt", "r");
    if (list == NULL || (estr = fgets(str, 100, list)) == NULL)
        printf("You have no current plans");
    else
    {
		rewind(list);
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

void mark_done()
{
    int i = 0;
    int done_str;
    char str[50][100];
    FILE * done;
    system("clear");
    view_list();
    printf("Which job would you like to done?");
    scanf("%d", &done_str);
    list = fopen("Todo-List.txt", "r");
    if (list != NULL)
    {
        while(!feof(list))
        {
            fgets(str[i],100,list);
            i++;
        }
    }
    fclose(list);
    int str_count = i;
    i = 0;
    done = fopen("Done-list.txt", "at");
    fprintf(done, "%s", str[done_str-1]);
    str[done_str-2][100] = 0;
    list = fopen("Todo-List.txt", "w");
    while (i < str_count)
    {
        if(str[i] !=0)
            fprintf(list,"%s", str[i]);
        i++;
    }
    fclose(list);
    fclose(done);
    puts ("\n");
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

void delete_list()
{
	char str[100];
	system("clear");
	list = fopen("Todo-List.txt","r");
	if(list == NULL || fgets(str, 100, list) == NULL)
	{
		printf("You have no current plans");
	}
	else
	{
	fclose(list);
    list = fopen("Todo-List.txt","w+");
	fclose(list);
    printf("Your task list is now empty!\n");
	}
}

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
