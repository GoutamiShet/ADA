#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}
int partition(int a[],int low,int high){
int pivot=a[low];
int i=low+1;
int j=high;
while(i<=j){
while(i<=high && a[i]<=pivot)
i++;
while(a[j]>pivot)
j--;
if(i<j)
swap(&a[i],&a[j]);
}
swap(&a[low],&a[j]);
return j;
}
void quicksort(int a[],int low,int high){
if(low<high){
int pivotIndex=partition(a,low,high);
quicksort(a,low,pivotIndex-1);
quicksort(a,pivotIndex+1,high);
}
}

int main(){
int n,i;
printf("enter the value of n:");
scanf("%d",&n);
int a[n];
//printf("enter the array elements");
srand(time(NULL));
for(i=0;i<n;i++){
a[i]=rand()%100000;
}
clock_t start=clock();
quicksort(a,0,n-1);
clock_t end=clock();
double timetaken=((double)(end-start))/CLOCKS_PER_SEC;
printf("the time taken is %f\n",timetaken);
//printf("array after sorting is\n");
/*for(i=0;i<n;i++){
printf("%d ",a[i]);
}*/
return 0;
}