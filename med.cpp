#include<iostream>
using namespace std;
int swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;b=t;
    return(153);
 }
int main()
{
  int a[100];
  int i=0,j=0;
  cout<<"Enter";
  while(i<7)
  {  cin>>a[i];
     i++;
     }
  for(i=0;i<7;i++)
  for(j=0;j<=i;j++)
  {  
  if(a[j]>a[j+1])
  swap(a[j],a[j+1]);
  }
  
  for(i=0;i<7;i++)
  cout<<a[i]<<"\t";
  cout<<"\n";
  return(0);
}
