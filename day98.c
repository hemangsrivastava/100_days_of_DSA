/*Q148: Take two structs as input and check if they are identical.

/*
Sample Test Cases:
Input 1:
Student1: Asha 101 90
Student2: Asha 101 90
Output 1:
Same

*/
#include <stdio.h>
#include <string.h> 


typedef struct {
    char name[50];
    int roll_nm;
    int marks;
} Student;

int main() {
    Student s1, s2;

  
    printf("Enter details for Student 1 (Name ID MARKS): ");
    scanf("%s %d %d", s1.name, &s1.roll_nm, &s1.marks);

    printf("Enter details for Student 2 (Name ID MARKS): ");
    scanf("%s %d %d", s2.name, &s2.roll_nm, &s2.marks);

    if (strcmp(s1.name, s2.name) == 0 && 
        s1.roll_nm == s2.roll_nm && 
        s1.marks == s2.marks) {
        
        printf("Same\n");
    } else {
        printf("Not same\n");
    }

    return 0;
}