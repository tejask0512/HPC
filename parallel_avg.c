#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
   int a[100],n,i;
   cout<<"enter the number of elements in array : ";
   cin>>n; 
   cout<<"\n enter array elements : ";
   for(i=0;i<n;i++)
   {
      cin>>a[i];
   }
   cout<<"\n array elements are: ";
   for(i=0;i<n;i++)
   {
      cout<<a[i]<<"\t";
   }
   float avg=0,sum=0;
   #pragma omp parallel 
   {
     int id=omp_get_thread_num();
     #pragma omp for
     for(i=0;i<n;i++)
     {
       sum=sum+a[i];
       cout<<"\nfor i= " <<i<<" thread "<<id<<" is executing "<<endl;
     }
   }
   avg=sum/n;
   cout<<"output= "<<avg<<endl;
}
