//Q35: Write a program to print all factors of a given number.

/*
Sample Test Cases:
Input 1:
6
Output 1:
1 2 3 6

Input 2:
10
Output 2:
1 2 5 10

*/

#include <stdio.h>

int main(){

int num, i,rem;
printf("Enter a number: ");
scanf("%d", &num);

for(i=1; i<=num; i++){
    if(num%i==0){
        printf("The factors of the number are %d\n", i);

    }else if(i==num){
        printf("No factors found\n");
    }

    }




    return 0;
}//Q36: Write a program to find the HCF (GCD) of two numbers.

/*
Sample Test Cases:
Input 1:
12 18
Output 1:
6

Input 2:
7 9
Output 2:
1

*/
#include <stdio.h>

int main(){

    int num1, num2, i, hcf;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    for(i=1; i<=num1 && i<=num2; i++){
        if(num1%i==0 && num2%i==0){
            hcf = i;
        }
    }
    printf("HCF of %d and %d is %d\n", num1, num2, hcf);

    return 0;
    
}