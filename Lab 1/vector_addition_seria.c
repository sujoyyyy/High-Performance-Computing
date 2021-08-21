/*
* @Author: prateek
* @Date:   2021-08-19 15:41:50
* @Last Modified by:   prateek
* @Last Modified time: 2021-08-19 16:41:30
*/



#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define n 100000
#define m 100000
int main()
{
double a[n],b[n], c[n];
int i,k;
int omp_rank;
float rtime;
clock_t startTime = clock();

/* here, do your time-consuming job */



for(i=0;i<n;i++)
{
a[i] = i * 10.236 ;
// Use Random function and assign a[i]
b[i] = i * 152.123;
// Use Random function and assign b[i]
for(int j=0;j<m;j++)
c[i] = a[i] + b[i];
}
clock_t endTime = clock();

double time_spent = (double)(startTime - endTime) / CLOCKS_PER_SEC;
printf("\n rtime=%f\n",time_spent);
return(0);

}