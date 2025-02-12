#include <ctype.h>
#include <stdio.h>

#define TEXT_LIM 1023

/* void analyzetext(char *ar, int ch_c) {} */

int readinput(char *ar, int limit) 
{
  printf("=> Type some text [or -> g , "
         "to use auto-generated text]\n");
}

int main(void) 
{
  char text[TEXT_LIM + 1]; // one byte for '\0'
  int chars_c;             // count of readed chars

  printf("=> This program prints various stuff about "
         "inputed text\n");
  chars_c = readinput(text, TEXT_LIM);
  analyzetext(text, chars_c);

  return 0;
}
