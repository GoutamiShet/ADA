#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
int n,i,j,k,t;
printf("enter the value of n:");
scanf("%d",&n);
int a[n];
//printf("enter the array elements");
srand(time(NULL));
for(i=0;i<n;i++){
a[i]=rand()%25000;
}
clock_t start=clock();
for(i=0;i<n;i++){
j=i;
for(k=i+1;k<n;k++){
if(a[k]<a[j])
j=k;
}
t=a[i];
a[i]=a[j];
a[j]=t;
}
clock_t end=clock();
double timetaken=((double)(end-start))/CLOCKS_PER_SEC;
printf("the time taken is %f\n",timetaken);
/*printf("array after sorting is\n");
for(i=0;i<n;i++){
printf("%d ",a[i]);
}*/
}
