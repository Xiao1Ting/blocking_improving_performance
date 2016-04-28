#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
int main(){
int *array1,*array2;
int N = 16;
int block = 8;
int num = 0;
double ir[100];
while( N <= 4096 ){
array1 = (int *)malloc(N*N*sizeof(int));
array2 = (int *)malloc(N*N*sizeof(int));
int i,j,k,l;
for(i=0;i<N;i++){
for(j=0;j<N;j++){
array1[i*N+j] = i+j;
}
}
struct timeval begin,end;
gettimeofday(&begin,NULL);
for( i = 0; i < N ; i += block ){
for( j = 0; j < N ; j += block ){
for( k = i ; k < i + block ; k++ ){
for( l = j ; l < j + block ; l++ ){
array2[k*N+l]=array1[l*N+k];
}
}
}
}
gettimeofday(&end,NULL);
double delta = end.tv_sec - begin.tv_sec + (double)(end.tv_usec -
begin.tv_usec)/1000000;
if(delta<0) delta+=1.0;
ir[num] = delta;
printf("The Array Size: %4d and The Execution time: %3.6lf\n ",N,delta);
printf("\n");
num++;
N*=2;
}
return 0;
}
