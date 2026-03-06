#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop(){
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char exp[]){
    int i = 0;

    while(exp[i] != '\0'){
        if(exp[i] == ' '){
            i++;
            continue;
        }

        if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else{
            int val2 = pop();
            int val1 = pop();
            int result;

            switch(exp[i]){
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(result);
            i++;
        }
    }

    return pop();
}

int main(){
    char exp[100];
    fgets(exp, sizeof(exp), stdin);
    printf("%d", evaluatePostfix(exp));
    return 0;
}
