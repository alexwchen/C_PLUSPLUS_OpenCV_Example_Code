#include <highgui.h>
#include <cv.h>
#include <cvaux.h>

int main( int argc, char** argv )
{
    
    char name[] = "car.jpg";

    IplImage* img = cvLoadImage( name );
    cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
    cvShowImage("Example1", img);
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow("Example1");
}
