#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;
int main( int argc, char** argv )
 {
    namedWindow("Control", CV_WINDOW_AUTOSIZE); 
        Mat img;
        img = imread(argv[1], 1);
        Mat cc(img.rows,img.cols,CV_8UC1);
    Mat imgHSV;
   cvtColor(img, imgHSV, COLOR_BGR2HSV); 
 while(1)
 {cout<<"Entered loop"<<endl;
  for(int i=0;i<img.rows;i++)
  {
  for(int j=0;j<img.cols;j++)
  {
      int z[10];
      z[0]=imgHSV.at<Vec3b>(i,j)[0];
      z[1]=imgHSV.at<Vec3b>(i,j)[1];
      z[2]=imgHSV.at<Vec3b>(i,j)[2];
    if(((z[0]>=170)||(z[0]<=5))&&(z[1]>=200)&&z[2]>=200 )
      cc.at<uchar>(i,j)=255;
      else if((z[0]>5&&z[0]<=10)&&z[1]>=200&&z[2]>=200)
      cc.at<uchar>(i,j)=200;
      else if((z[0]>10&&z[0]<=30)&&z[1]>=200&&z[2]>=200)
      cc.at<uchar>(i,j)=150;
      else if((z[0]>=40&&z[0]<=70)&&z[1]>=150&&z[2]>=150)
      cc.at<uchar>(i,j)=100;
      else if((z[0]>=100&&z[0]<=140)&&z[1]>=150&&z[2]>=150)
      cc.at<uchar>(i,j)=50;
      else
      cc.at<uchar>(i,j)=0;
  }}
     imshow("Control",cc);
     imshow("Original",img);
     if(waitKey(0)==27)
  {cout<<"Loop terminated"<<endl;
  break;
  }
  else
  continue;
  }
   return 0;}

//g++ -o <objectfilename> <fn.cpp> `pkg-config --cflags --libs opencv`

