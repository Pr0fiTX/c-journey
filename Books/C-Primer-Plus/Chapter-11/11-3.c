#include <stdio.h>
#define WORD 101 // I don't think i'll find word longer than 100 characters
int rword(char *string, char ar[], int size);

int main(int argc, char *argv[])
{
    char word[WORD];
    int word_size;

    if (argc == 1) {
        printf("!> Not enough arguments. Type string as argument (use \"\").");
        return 1;
    } else if (argc > 2) {
        printf("!> Too many arguments. Use \"\" to type string.");
        return 2;
    } else {
        printf("=> This small programm reads a string until find space,");
        printf(" tab or char of new string.\n\n");
    }
    
    word_size = rword(argv[1], word, WORD);

    printf("=> Word -> ");
    for (int c = 0; c < word_size; c++)
    {
        printf("%c", word[c]);
    }
    putchar('\n');
    putchar('\n');
    for (int c = 0; c < word_size; c++)
    {
        printf("word[%d] -> %c\n", c, word[c]);
    }

    return 0;
}

int rword(char *string, char ar[], int size)
{
    int i = 0;

    while (*(string + i) != ' ' && *(string + i) != '\n' && *(string + i) != '\t')
    {
        ar[i] = *(string + i); 
        i++;
    }
    
    return i;
}