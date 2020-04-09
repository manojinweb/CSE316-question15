#include<stdio.h>
int n;
struct process
{

int pr;

int tarr,tbur,ct,wait_t,turnt,p;

int keyto;
 }arr[100];
 void Sorting()
 {
struct process p;

int x, j;

for(x=0;x<n-1;x++)

{

for(j=x+1;j<n;j++)

{

if(arr[x].tarr > arr[j].tarr)

{

p = arr[x];

arr[x] = arr[j];

arr[j] = p; 

}

}

}
 }
 int main()
 {

int x,t=0,b_t=0,peak;

int a[10];

float wtim = 0, turnt = 0, awt=0, avgt=0;

printf("enter the no. of processes: ");

scanf("%d",&n);

for(x = 0; x < n; x++)

{

arr[x].pr = x+1;

printf("\nDetails For P%d process:-\n", arr[x].pr);
printf("Arrival Time: ");
scanf("%d", &arr[x].tarr );
printf("Enter Burst Time: ");
scanf("%d", &arr[x].tbur);
arr[x].keyto = 0;
b_t = b_t + arr[x].tbur;
}
Sorting();
for(x=0;x<n;x++)
{
a[x]=arr[x].tbur;
}
arr[9].tbur = 9999;
for(t = arr[0].tarr; t <= b_t+1;)
{
peak = 9;
for(x=0;x<n;x++)
{
if(arr[x].tarr <= t && arr[x].tbur < arr[peak].tbur && arr[x].keyto != 1)
{
peak = x;
}
if(arr[peak].tbur==0 && arr[x].keyto != 1)
{
arr[x].keyto = 1;
arr[peak].ct=t;arr[peak].tbur=9999;
printf("P%d completes in %d\n",arr[x].pr,arr[peak].ct);
}
}
t++;
(arr[peak].tbur)--;
}
for(x=0;x<n;x++)
{
arr[x].turnt=(arr[x].ct)-(arr[x].tarr);
avgt=avgt+arr[x].turnt;
arr[x].wait_t=((arr[x].turnt)-a[x]);
awt=awt+arr[x].wait_t;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(x=0;x<n;x++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",arr[x].pr
,arr[x].tarr,arr[x].ct,arr[x].turnt
,arr[x].wait_t);
 }
printf("Average Turn around Time: %f\t\n\n",avgt);
printf("Average Waiting Time :\t %f\t\n",awt);
}
