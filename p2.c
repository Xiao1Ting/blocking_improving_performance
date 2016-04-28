#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
int main(){
int *array1,*array2;
int N = 16;
int num = 0;
double ir[100];
while( N <= 4096 ){
array1 = (int *)malloc(N*N*sizeof(int));
array2 = (int *)malloc(N*N*sizeof(int));
int i,j;
for(i=0;i<N;i++){
for(j=0;j<N;j++){
array1[i*N+j] = i+j;
}
}
struct timeval begin,end;
gettimeofday(&begin,NULL);
for(i=0;i<N;i++){
for(j=0;j<N;j++){
array2[i*N+j] = array1[j*N+i];
}
}
gettimeofday(&end,NULL);
double delta = end.tv_sec - begin.tv_sec + (double)(end.tv_usec -
begin.tv_usec)/1000000;
if(delta<0) delta+=1.0;
ir[num] = delta;
printf("The Array Size: %4d and The Execution time: %3.6lf\n ",N,delta);
if( num > 0 ){
printf("The increasing rate: %3.6lf", ir[num] / ir[num - 1]);
}
printf("\n");
num++;
N*=2;
}
return 0;
}
