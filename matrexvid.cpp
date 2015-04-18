#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	int c;

	VideoCapture cap(0);
	cap.set(0

	Mat image;
	Mat image2;
	int th;


	namedWindow("out");
	namedWindow("Threshold");
	createTrackbar( "Threshold", "Threshold", &th, 200 );

	while(1)
	{
	Mat imgc,img;
	    cap>>imgc;
	    cvtColor(imgc,img,CV_RGB2GRAY);
	    Mat cc(img.rows, img.cols, CV_8UC1);
		int x[9],ds=0;
		for(int i=1;i<img.cols-1;i++)
		for(int j=1;j<img.rows-1;j++)
		{
			x[0]=(img.at<uchar>(j,i)-img.at<uchar>(j+1,i-1));
			x[1]=(img.at<uchar>(j,i)-img.at<uchar>(j+1,i));
			x[2]=(img.at<uchar>(j,i)-img.at<uchar>(j+1,i+1));
			x[3]=(img.at<uchar>(j,i)-img.at<uchar>(j,i-1));
			x[4]=(img.at<uchar>(j,i)-img.at<uchar>(j,i));
			x[5]=(img.at<uchar>(j,i)-img.at<uchar>(j,i+1));
			x[6]=(img.at<uchar>(j,i)-img.at<uchar>(j-1,i-1));
			x[7]=(img.at<uchar>(j,i)-img.at<uchar>(j-1,i));
			x[8]=(img.at<uchar>(j,i)-img.at<uchar>(j-1,i+1));
			for(int k=0;k<9;k++)
			{
				ds+=pow(x[k],2);
			}
			ds = sqrt(ds);
			if(ds>th)
				cc.at<uchar>(j,i)=255;
		
			else
				cc.at<uchar>(j,i)=0;
		}
		imshow("out", cc);
		c=waitKey(33);

	    if(c==27)
		return 0;
	}
return 0;
}
	


