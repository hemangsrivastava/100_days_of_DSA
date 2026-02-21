//Q39: Write a program to find the product of odd digits of a number.

/*
Sample Test Cases:
Input 1:
12345
Output 1:
15 (1*3*5)

Input 2:
2468
Output 2:
1 (no odd digits, assume 1)

*/
#include <stdio.h>
int main() {
    int number, rem, product = 1, Odd = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    int temp = number;
    while (temp > 0) {
        rem = temp % 10;
        if (rem % 2 != 0) {
            product *= rem;
            Odd = 1;
        }
        temp /= 10;
    }

    if (!Odd) {
        product = 1; 
    }

    printf("The product of odd digits is %d\n", product);

    return 0;
}//Q40: Write a program to find the 1’s complement of a binary number and print it.

/*
Sample Test Cases:
Input 1:
1010
Output 1:
0101

Input 2:
1111
Output 2:
0000

*/
#include <stdio.h>
#include <string.h>

int main() {
    char binary[33], onesComplement[33];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    int len = strlen(binary);
    for (int i = 0; i < len; i++) {
        if (binary[i] == '0')
            onesComplement[i] = '1';
        else
            onesComplement[i] = '0';
    }
    onesComplement[len] = '\0';

    printf("%s\n", onesComplement);

    return 0;
}