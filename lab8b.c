#include<stdio.h>
#define MAX 20
void warshals(int n,int r[MAX][MAX]){
int i,j,k;
for(k=1;k<=n;k++){
for(i=0;i<=n;i++){
for(j=1;j<=n;j++){
r[i][j]=r[i][j] || r[i][k] && r[k][j];
}
}
}
printf("transitive closure matrix is\n");
for(i=1;i<=n;i++){
printf("\t%d",i);
}
printf("\n\t------------------\n");
for(i=1;i<=n;i++){
printf("%d|\t",i);
for(j=1;j<=n;j++){
printf("%d\t",r[i][j]);
}
printf("\n");
}
}
int main(){
int r[MAX][MAX];
int i,j,n;
printf("enter the no of nodes /vertices:");
scanf("%d",&n);
printf("enter the adjacency matrix(1 for edge,0 for no edge):\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&r[i][j]);
}
}
warshals(n,r);
return 0;
}
