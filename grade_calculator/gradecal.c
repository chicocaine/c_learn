#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void reverse_string(char str[]);

double calculate_grade(double first_exam, double second_exam, double third_exam, double fourth_exam, double others);

int main ()
{
  double total_grade = calculate_grade(75, 96, 100, 83, 80);
  printf("%.2lf\n", total_grade);

  return 0; 
}

double calculate_grade
(
  double first_exam, 
  double second_exam, 
  double third_exam, 
  double fourth_exam, 
  double others
)
{
  double total_grade;

  double first_grade = ((first_exam) * 0.85) + 15;
  double second_grade = ((second_exam) * 0.85) + 15;
  double third_grade = ((third_exam) * 0.85) + 15;
  double fourth_grade = ((fourth_exam) * 0.85) + 15;

  total_grade = (first_grade/100 * .10) + 
                (second_grade/100 * .10) + 
                (third_grade/100 * .10) + 
                (fourth_grade/100 * .40) +
                (others/100 * .30);

  return total_grade;
}