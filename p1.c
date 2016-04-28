#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
int main(){
int *array1,*array2;
int N = 1024;
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
double delta = end.tv_sec - begin.tv_sec + (double)(end.tv_usec - begin.tv_usec)/1000000;
if(delta<0)delta+=1.0;
printf("The Array Size: %4d\n The Execution time: %3.6f\n",N,delta);
return 0;
}
