#include<stdio.h>
#include<iostream>
#include<cstdlib>
//****important to add following library to allow a programmer to use parallel paradigms*****
#include<omp.h>	
using namespace std;
#define MAX 100

int main()
{
  int a[MAX],b[MAX],c[MAX],i;
  printf("\n First Vector:\t");
  //Instruct a master thread to fork and generate more threads to process following loop structure
  #pragma omp parallel for
  for(i=0;i<MAX;i++)
  {
     a[i]=rand()%1000;
  }
  //Discuss issue of this for loop below-if we make it parallel, possibly values that get printed will not be in sequence as we dont have any control on order of threads execution
  for(i=0;i<MAX;i++)
  {
     printf("%d\t",a[i]);
  }
  printf("\n Second Vector:\t");
  #pragma omp parallel for
  for(i=0;i<MAX;i++)
  {
     b[i]=rand()%1000;
  }
  for(i=0;i<MAX;i++)
  {
     printf("%d\t",b[i]);
  }
  printf("\n Parallel-Vector Addition:(a,b,c)\t");
  #pragma omp parallel for
  for(i=0;i<MAX;i++)
  {
     c[i]=a[i]+b[i];
  }
  for(i=0;i<MAX;i++)
  {
     printf("\n%d\t%d\t%d",a[i],b[i],c[i]);
  }
}
