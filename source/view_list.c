#include "todolib.h"

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
    puts("Your completed tasks:");
    list = fopen("Done-List.txt", "r");
    if (list == NULL || (estr = fgets(str, 100, list)) == NULL)
        printf("You haven't done any jobs");
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
