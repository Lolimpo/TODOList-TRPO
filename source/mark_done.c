#include "todolib.h"

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
