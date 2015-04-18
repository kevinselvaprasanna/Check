#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat img,hs,img1;

int swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;b=t;
    return(0);
 }
 int check(int a,int b,int c,int d)
 {	
 	 int f[406];
 	 int o=0,m;
 	 for(int i=a;i<b;i++)
	        for(int j=c;j<d;j++)
	        {
	        f[o]=hs.at<Vec3b>(j,i)[0];
	        o++;
	        }
	        
	  for(int i=0;i<405;i++)
	  for(int j=0;j<i;j++)
	  {  
	  if(f[j]>f[j+1])
	  swap(f[j],f[j+1]);
	  }
	  cout<<" "<<f[200];
	  m=f[200];
 	 if((m<10)||(m>170)){
	  	cout<<" R";
	  	 for(int i=a;i<b;i++)
	        for(int j=c;j<d;j++)
	        {
	        img.at<Vec3b>(j,i)[0]=0;
	        img.at<Vec3b>(j,i)[1]=0;
	        img.at<Vec3b>(j,i)[2]=255;
	        }
	        }
	  if((m<140)&&(m>70))
	  {
	  	cout<<" B";
	  	 for(int i=a;i<b;i++)
	        for(int j=c;j<d;j++)
	        {
	        img.at<Vec3b>(j,i)[0]=255;
	        img.at<Vec3b>(j,i)[1]=0;
	        img.at<Vec3b>(j,i)[2]=0;
	        }
	        }
	  if((m<17)&&(m>5)){
	  	cout<<" O";
	  	 for(int i=a;i<b;i++)
	        for(int j=c;j<d;j++)
	        {
	        img.at<Vec3b>(j,i)[0]=0;
	        img.at<Vec3b>(j,i)[1]=165;
	        img.at<Vec3b>(j,i)[2]=255;
	        }
	  	}
	  if((m<35)&&(m>18)){
	  	cout<<" Y";
	  	 for(int i=a;i<b;i++)
	        for(int j=c;j<d;j++)
	        {
	        img.at<Vec3b>(j,i)[0]=0;
	        img.at<Vec3b>(j,i)[1]=255;
	        img.at<Vec3b>(j,i)[2]=255;
	        }
	  	}
	  if((m<70)&&(m>40))
	  {
	  	cout<<" G";
	  	 for(int i=a;i<b;i++)
	        for(int j=c;j<d;j++)
	        {
	        img.at<Vec3b>(j,i)[0]=0;
	        img.at<Vec3b>(j,i)[1]=255;
	        img.at<Vec3b>(j,i)[2]=0;
	        }
	        }
	  
	  
 }
int main()
{
	int c,o=0;
	VideoCapture cap(0);
	//cap.set(CV_CAP_PROP_FRAME_WIDTH,300);
	//cap.set(CV_CAP_PROP_FRAME_HEIGHT,300);
	namedWindow("out",WINDOW_NORMAL);
	
	
	while(1)
	{	
	        cap>>img1;
	        resize(img1,img,Size(100,100));
	        //GaussianBlur( img, img2, Size(3, 3), 2, 2 );
	        cvtColor(img,hs,CV_BGR2HSV);
	        rectangle(img, Point(20,20), Point (80,80), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(20,20), Point (40,40), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(20,40), Point (40,60), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(20,60), Point (40,80), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(40,20), Point (60,40), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(40,40), Point (60,60), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(40,60), Point (60,80), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(60,20), Point (80,40), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(60,40), Point (80,60), Scalar(255,255,255), 1, 8, 0);
	        rectangle(img, Point(60,60), Point (80,80), Scalar(255,255,255), 1, 8, 0);
	        o=0;
	        check(20,40,20,40);
	        check(20,40,40,60);
	        check(20,40,60,80);
	        check(40,60,20,40);
	        check(40,60,40,60);
	        check(40,60,60,80);
	        check(60,80,20,40);
	        check(60,80,40,60);
	        check(60,80,60,80);
	        cout<<"\n";
		imshow("out", img);
		c=waitKey(10);

	    if(c==27)
		return 0;
	
	}
return 0;
}
	


