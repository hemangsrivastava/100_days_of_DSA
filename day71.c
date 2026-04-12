#include <stdio.h>
#include <string.h>
#define EMPTY -1

int table[1000];

void insert(int key, int m){
  for (int i=0; i<m; i++){
    int index = (key % m + i * i)%m;
    if (table[index] == EMPTY){
      table[index] = key;
      return;
    }
  }
}

void search(int key, int m){
  for (int i=0; i<m; i++){
    int index = (key %m + i * i ) % m;
    if (table[index] == EMPTY){
      printf("not found\n");
      return;
    }
    if (table[index] == key){
      printf("Found \n");
      return;
    }
  }
  printf("Not found");
}

int main(){
  int m,q;
  scanf("%d",&m);
  scanf("%d",&q);

  for (int i = 0; i<m; i++){
    char op[10];
    int key;
    scanf("%s %d", op, &key);
    
    if (strcmp(op, "INSERT")==0){
      insert(key,m);
    }
    if (strcmp(op, "SEARCH")==0){
      search(key,m);
    }
  }
}
