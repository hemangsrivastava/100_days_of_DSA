#include <stdio.h>

int main(){
  int n,m;

  printf("Enter the number of vertices");
  scanf("%d",&n);

  printf("Enter the number of edges");
  scanf("%d",&m);

  int adj[n][m];

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      adj[i][j]=0;
    }
  }

  int u,v;

  printf("Enter edges (uv):\n");

  for (int i=0; i<m; i++){
    scanf("%d %d", &u,&v);

    adj[u][v]=1;
  }

  printf("\nAdjancency Matrix:\n");
  for (int i=0;i<n;i++){
    for(int j=0; j<n; j++){
      printf("%d",adj[i][j]);
    }
    printf("\n");
  }
  return 0;
}
