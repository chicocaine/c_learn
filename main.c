#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void reverse_string(char str[]);

enum Day 
{
  sun = 1,
  mon = 2,
  tue = 3,
  wed = 4,
  thu = 5,
  fri = 6,
  sat = 7
};

int main ()
{
  int today = sun;

  printf("%d", today);

  return 0; 
}

void reverse_string(char str[]) 
{
  int start = 0;
  int end = strlen(str) - 1;

  while (start < end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    start++;
    end--;
  } 
}