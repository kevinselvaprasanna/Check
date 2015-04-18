#include <opencv2/opencv.hpp>
#include <iostream>
#define s 600
using namespace cv;
using namespace std;



Mat element = getStructuringElement( MORPH_CROSS, Size( 3, 3 ));

/* 	param1 = 1 : Dilation after canny.
	param2 = 1 : GaussianBlur() is applied
*/
void func( Mat &img, vector<vector<Point> > & contours , vector<Vec4i> & hierarchy, vector<vector<Point> > &app, int param1 = 0, int param2= 1)
{	
	Mat oimg, oimg1, oimgr1, oimgr, oimgr2, img1, img2, imgc, dst;
    
	if(	img.rows > s)
	resize( img, img2, Size( s, s*img.rows/img.cols));
	
	else
	img2 = img.clone();
	
	 imshow( "pic", img2);
	
	int i, j;
	
	if( param2 ==1)
	{	GaussianBlur( img2, img1, Size(5,3), 0, 0);
		imshow("After Blur", img1);
	}
	else	img1 = img2.clone();
	if( param1 == 0)
	{	Canny( img1, imgc, 100, 180, 3, 1);
    	imshow("After canny", imgc);
    }
    
    if( param1 == 1)
    {	Canny( img1, dst, 100, 180, 3, 1);
    	dilate( dst, imgc, element);
    	imshow("After canny & dilate", imgc);
    }
    
    
    findContours( imgc, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_TC89_L1, Point(0, 0) ); 
    																	// FINDING CONTOURS
      																	// 4TH PARAMETER: CV_RETR_CCOMP -retrieves all 
      																	// of the contours and organizes them into a two-level hierarchy.
      																	// - One level contains External contours. Other level internal.
     
    // DRAWING CONTOURS									
    oimg  = Mat::zeros( imgc.size(), CV_8UC3 );
    resize( oimg, oimgr,Size(imgc.cols, imgc.rows));
    oimg1 = oimgr.clone(); 
    oimgr1 = oimgr.clone();
    // 1. DRAWING ALL CONTOURS
    for(i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( 103, 224, 50 );
        drawContours( oimg1, contours, i, color, 1, 8, hierarchy, 0, Point() );
    }
    // 2. DRAWING CONTOURS WHOSE AREA IS GREATER THAN A GIVEN THRESHOLD VALUE : 1/200 * Area of image
    for(i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( (10*i)%255, (49*i)%255, (32*i)%255 );
         if( contourArea(contours[i]) >= oimg1.cols * oimg1.rows/200)
        	{	drawContours( oimgr1, contours, i, color, 1, 8, hierarchy, 0, Point() );
        	}
        	
    }
    imshow("Contours", oimg1);
    imshow("Contours2", oimgr1);
    
    // FINDING POLYGONS USING approxPolyDp()
    oimgr2=oimgr.clone();
        app.resize( contours.size() );
    for( i = 0; i< contours.size(); ++i)
    	approxPolyDP( Mat(contours[i]), app[i], 3, 1); 	// 3RD PARAMETER : epsilon: epsilon – The maximum distance between 
    													// the original curve and its approximation.
    													// 4TH PARAMETER :	value = 1 => polygon is closed
    
    // 3. DRAWING ALL POLYGONS
    for(i = 0; i< app.size(); i++ )
    {
        Scalar color = Scalar( 200, 23, 100 );
        drawContours( oimgr, app, i, color, 1, 8, hierarchy, 0, Point() );
    }
    imshow("Polys", oimgr);
    
    // 4. DRAWING POLYGONS WHOSE AREA IS GREATER THAN A GIVEN THRESHOLD VALUE : 1/200 * Area of image
    for(i = 0; i< app.size(); i++ )
    {
        Scalar color = Scalar( (10*i)%255, (49*i)%255, (32*i)%255 );
        
        if( contourArea(app[i]) >= oimgr2.cols * oimgr2.rows/200)
        	{	if((app[i]). size() >= 4 && (app[i]). size() <= 15)
           		drawContours( oimgr2, app, i, color, 2, 8, hierarchy, 0, Point() );
    		}
    }
    imshow(" Display window", oimgr2);
    
   	waitKey(0);
  }
  
 
int main( int argc, char** argv )
{
    Mat img = imread( argv[1],0);
    vector<vector<Point> > contours[4];
    vector<Vec4i> hierarchy[4];
    vector<vector<Point> > app[4];
    
    func( img, contours[0], hierarchy[0], app[0], 0, 0);	// No blur No dilation after canny
    func( img, contours[1], hierarchy[1], app[1], 1, 0);	// No blur but dilation after canny
    func( img, contours[2], hierarchy[2], app[2], 0, 1);	// blur No dilation after canny
    func( img, contours[3], hierarchy[3], app[3], 1, 1);	// blur and dilation after canny
                       
    return 0;
}
