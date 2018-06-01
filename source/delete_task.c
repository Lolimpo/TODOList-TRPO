#include "todolib.h"

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
            fgets(str[i], sizeof(str), list);
            i++;
        }
        fclose(list);
        list = fopen("Todo-List.txt", "w");
        int str_count = i;
        i = 0;
        str[del_num - 2][100] = 0;
        while (i < str_count)
        {
            if (str[i] != 0)
                fprintf(list, "%s", str[i]);
            i++;
        }
    }
    fclose(list);
}
