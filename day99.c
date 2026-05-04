/*Q149: Use malloc() to allocate structure memory dynamically and print details.

/*
Sample Test Cases:
Input 1:
Student allocated dynamically with details: Tina 105 88
Output 1:
Name: Tina | Roll: 105 | Marks: 88

*/
#include <stdio.h>
#include <stdlib.h>


typedef struct std_details{
      char name[50];
      int roll;
      int marks;
}details;

int main(){
    details *student;
    student = (details*)malloc(sizeof(details));

   
    printf("Enter name, roll number and marks: ");
    scanf("%s %d %d", student->name, &student->roll, &student->marks);

  
    printf("Name: %s | Roll: %d | Marks: %d\n", student->name, student->roll, student->marks);

  
    free(student);
    return 0;
}