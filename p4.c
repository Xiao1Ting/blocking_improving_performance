#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
int main(){
int *array1,*array2;
int N = 2048;
int block = 4;
int num = 0;
double ir[100];
printf("The Array Size: 4096\n");
while( block <= 512 ){
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
ir[num] = delta;
printf("The Block Factory: %3d The Execution time: %3.6lf",block,delta);
printf("\n");
block*=2;
num++;
}
return 0;
}
