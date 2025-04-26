#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxvalue(double W,double weight[],double value[],double ratio[],int nitem){
double cw=0;
double cv=0;
printf("\n items consided are\n");
while(cw<W){
int item=getNextitem(weight,value,ratio,nitem);
if(item==-1){
break;
}
printf("item %d\n",item+1);
if(cw+weight[item]<=W){
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(W-cw));
cw+=(W-cw);
break;
}
}
return cv;
}
int getNextitem(double weight[],double value[],double ratio[],int nitem){
int i;
double highest=0;
int index=-1;
for(i=0;i<nitem;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}
int main(){
int nitem,i;
double W;
double weight[MAX_ITEMS];
double value[MAX_ITEMS];
double ratio[MAX_ITEMS];
printf("enter the no of items:");
scanf("%d",&nitem);
printf("enter the weight\n");
for(i=0;i<nitem;i++){
scanf("%lf",&weight[i]);
}
printf("enter the values/profit of the items:\n");
for(i=0;i<nitem;i++){
scanf("%lf",&value[i]);
}
for(i=0;i<nitem;i++){
ratio[i]=value[i]/weight[i];
}
printf("enter the capacity of the knapsack:");
scanf("%lf",&W);
printf("\n maximum value in a knapsack of capacity %.2f is :%.2f\n",W,computeMaxvalue(W,weight,value,ratio,nitem));
return 0;
}

