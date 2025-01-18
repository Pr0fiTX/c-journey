#include <stdio.h>
#include <string.h>
#define STR_SIZE 100
char* srhchrinstr(char chrtosrh, char strwheresrh[]); // Searches char in str

int main(void)
{
    char ar[STR_SIZE]; // == strwheresrh[]
    char* ptr_zero_ar = &ar[0];
    char des_char; // == chrtosrh
    char* ch_pos_in_ar; // out of srhchrinstr()

    printf("=> This programm searches char in string. ~user~ must input char and string.");
    printf(" Type \"exit\" as string to exit from programm.\n\n");
    while (1)
    {
        printf("=> Type a string: ");
        fgets(ar, STR_SIZE - 1, stdin);
        if (!strcmp(ar, "exit\n"))
        {
            printf("!> Exiting...\n");
            return 0;
        }
        printf("=> Enter the character you want to find: ");
        scanf("%c", &des_char);

        ch_pos_in_ar = srhchrinstr(des_char, ar);

        if ((ch_pos_in_ar - ptr_zero_ar) + 1 > STR_SIZE) {
            printf("=> Char (%c) wasn\'t found :(\n", des_char);
            while (getchar() != '\n') continue;
        } else {
            printf("=> Char (%c) was succesfuly found in -> %d position\n", 
            *ch_pos_in_ar, (ch_pos_in_ar - ptr_zero_ar) + 1);

            while (getchar() != '\n') continue;
        }
    }
    return 0;
}

char* srhchrinstr(char chrtosrh, char strwheresrh[])
{   
    char* cursor = &strwheresrh[0];
    int i = 1;
    
    while (*cursor != chrtosrh || *cursor == '\0') {
        cursor = &strwheresrh[i];
        i++;
    }

    if (*cursor == '\0') { 
        return NULL;
    } else { 
        return cursor;
    }
}