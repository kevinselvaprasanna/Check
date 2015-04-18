#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<iostream>
using namespace std;
using namespace cv;

Mat laplacianFilter(Mat image)
{
Mat hImage;

GaussianBlur(image,hImage,Size(3,3),0,0,BORDER_DEFAULT);
cvtColor(hImage,hImage,CV_RGB2GRAY);
Laplacian(hImage,hImage,CV_16SC1,3,1,0,BORDER_DEFAULT);
convertScaleAbs(hImage,hImage,1,0);

return hImage;
}

Mat hghTransform(Mat image, Mat &image2)
{
Mat lImage;

Canny(image,image,50,200,3);
cvtColor(image,lImage,CV_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(image, lines, 1, CV_PI/180, 50, 50, 10 );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        line( image2, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,255,0), 3, CV_AA);
    }

return lImage;
}


int main()
{
int c;

VideoCapture cap(0);

Mat image;
Mat image2;

namedWindow("hghtransform");
namedWindow("laplacianfilter");
namedWindow("cannyOutput");

while(1)
{
    cap>>image;
    cap>>image2;

    //Output
    imshow("laplacianfilter",laplacianFilter(image));
    imshow("cannyOutput",hghTransform(laplacianFilter(image),image2));
    imshow("hghtransform",image2);

    c=waitKey(33);

    if(c==27)
        return 0;

}

return 0;
}

