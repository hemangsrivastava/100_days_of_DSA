//Q37: Write a program to find the LCM of two numbers.

/*
Sample Test Cases:
Input 1:
4 5
Output 1:
20

Input 2:
7 3
Output 2:
21

*/
#include <stdio.h>
int main(){

    int num1, num2, i, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    for(i=1; i<=num1*num2; i++){
        if(i%num1==0 && i%num2==0){
            lcm = i;
            break;
        }
    }
    printf("LCM of %d and %d is %d\n", num1, num2, lcm);

    return 0;
    
}//Q38: Write a program to find the sum of digits of a number.

/*
Sample Test Cases:
Input 1:
123
Output 1:
6

Input 2:
999
Output 2:
27

*/
#include <stdio.h>
int main(){

    int num, sum=0, rem;
    printf("Enter a number: ");
    scanf("%d", &num);

    while(num!=0){
        rem = num%10;
        sum = sum + rem;
        num = num/10;
    }
    printf("Sum of digits is %d\n", sum);

    return 0;
    
}