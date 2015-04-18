#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/opencv.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
using namespace cv;
int diff(int a,int b)
{
return (a>b)?(a-b):(b-a);
}
int main( int argc, char** argv)
{
  Mat img;
  int x,i,j;
  img= imread(argv[1],1);
  int z[3][100];
  Mat cc(img.rows,img.cols,CV_8UC1);
  int c[300][200];
  float d[300][200];
  for(i=1;i<img.rows-1;i++)
  {
    for(j=1;j<img.cols-1;j++)
    {
    c[i][j]=0;
      for(x=0;x<=2;x++)
      {z[x][0]=img.at<Vec3b>(i,j)[x];
      z[x][1]=img.at<Vec3b>(i+1,j)[x];
      z[x][2]=img.at<Vec3b>(i,j+1)[x];
      z[x][3]=img.at<Vec3b>(i,j-1)[x];
      z[x][4]=img.at<Vec3b>(i-1,j)[x];
      z[x][5]=img.at<Vec3b>(i+1,j+1)[x];
      z[x][6]=img.at<Vec3b>(i+1,j-1)[x];
      z[x][7]=img.at<Vec3b>(i-1,j+1)[x];
      z[x][8]=img.at<Vec3b>(i-1,j+1)[x];
      c[i][j]+=(diff(z[x][1],z[x][0])+diff(z[x][2],z[x][0])+diff(z[x][3],z[x][0])+diff(z[x][4],z[x][0])+diff(z[x][5],z[x][0])+diff(z[x][6],z[x][0])+diff(z[x][7],z[x][0])+diff(z[x][8],z[x][0]));
      }
      d[i][j]=((float)c[i][j])/((float)24);
    }  
   }
   for(i=1;i<img.rows-1;i++)
   {for(j=1;j<img.cols-1;j++)
   {
   if(d[i][j]>=30)
   cc.at<uchar>(i,j)=255;
   else
   cc.at<uchar>(i,j)=0;
   }}
   
   imshow("Control",cc);
   imshow("Original",img);
   waitKey(0);
  cout<<"Loop terminated"<<endl;
   
   return 0;
   }
