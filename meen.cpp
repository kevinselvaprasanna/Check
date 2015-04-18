#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main()
{
	int c;
	VideoCapture cap(0);

	Mat img,hs;
	namedWindow("out");
	int s1=0,sd=0;

	while(1)
	{	
	        cap>>img;
	        cvtColor(img,hs,CV_BGR2HSV);
	        rectangle(img, Point(130,100), Point (430,400), Scalar(255,255,255), 5, 8, 0);
	        rectangle(img, Point(130,100), Point (230,200), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(130,200), Point (230,300), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(130,300), Point (230,400), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(230,100), Point (330,400), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(230,200), Point (330,300), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(230,300), Point (330,400), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(330,100), Point (430,200), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(330,200), Point (430,300), Scalar(255,255,255), 2, 8, 0);
	        rectangle(img, Point(330,300), Point (430,400), Scalar(255,255,255), 2, 8, 0);
	        for(int i=130;i<230;i++)
	        for(int j=100;j<200;j++)
	        	s1+=hs.at<Vec3b>(j,i)[0];
	        s1=s1/10000;
	        cout<<s1<<'\t';
	        for(int i=130;i<230;i++)
	        for(int j=100;j<200;j++)
	        	sd+=pow((hs.at<Vec3b>(j,i)[0]-s1),2);
	        sd=sd/10000;
	        sd=pow(sd,0.5);
	        cout<<sd<<'\t';
	        cout<<(int)hs.at<Vec3b>(150,170)[0];
	        cout<<"\n";
	          for(int i=130;i<230;i++)
	        for(int j=100;j<200;j++)
	        	s1+=hs.at<Vec3b>(j,i)[0];
	        s1=s1/10000;
	        cout<<s1<<'\t';
	        for(int i=130;i<230;i++)
	        for(int j=100;j<200;j++)
	        	sd+=pow((hs.at<Vec3b>(j,i)[0]-s1),2);
	        sd=sd/10000;
	        sd=pow(sd,0.5);
	        cout<<sd<<'\t';
	        cout<<hs.at<Vec3b>(150,170)[0];
	        cout<<"\n";
		imshow("out", img);
		c=waitKey(100);

	    if(c==27)
		return 0;
	
	}
return 0;
}
	


