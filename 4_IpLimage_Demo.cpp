#include <stdio.h>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

void saturate_sv( IplImage* img ) {

  for( int y=0; y<img->height; y++ ) {
    uchar* ptr = (uchar*) (
      img->imageData + y * img->widthStep 
    );
    for( int x=0; x<img->width; x++ ) {
      ptr[3*x+1] = 255;
      ptr[3*x+2] = 255;
    }
  }
}

int main()
{

    char name[] = "car.jpg";
    IplImage* iplimg = cvLoadImage(name);

    // ///////////////////////////////////
    // Hack:
    // use cv::Mat (c++) to convert iplimage
    // and somehow change it back to c  
    // 
    // cv::Mat imgMat(iplimg, 0);
    // means point the data of cv::Mat to iplimage on the same memory
    // no copied is performed, just pointer operation
    // ///////////////////////////////////
    float vals[] = { 0.866025, -0.500000, 0.500000, 0.866025};
    CvMat rotmat;
    cvInitMatHeader(
      &rotmat,  // mat
      2,        // rows
      2,        // cols
      CV_32FC1, // type
      vals      // data
    );


    // Matrix created (init all 0 ) and accessed [3,2]
    // cvCreateMat(int rows, int cols, int type) 
    //cv::Mat imgMat(iplimg);
    //CvMat mat = imgMat;

    char *p;
    p = iplimg->imageData;
    printf("%ld\n", sizeof(p));
    
    float *v;
    CvMat *mat = &rotmat;
    float * fp = (float*) mat->data.ptr;
    printf("%ld\n", sizeof(fp));


    // ///////////////////////////////////
    // Demoing How IplImage Read Pixels
    // ///////////////////////////////////

    IplImage* img = cvLoadImage(name);
    cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
    saturate_sv(img);
    cvShowImage("Example1", img );
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow("Example1");


    // ///////////////////////////////////
    // Demoing How ROI Works
    // ///////////////////////////////////

    cvNamedWindow("Example3_12_pre", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Example3_12_post", CV_WINDOW_AUTOSIZE);  
    IplImage* src= cvLoadImage(name);
	cvSetImageROI(src, cvRect(10,10,100,100));
    cvShowImage( "Example3_12_pre", src);
	cvAddS(src, cvScalar(10),src);
	cvResetImageROI(src);
	cvShowImage( "Example3_12_post",src);
    cvWaitKey(0);
    cvReleaseImage( &src );
    cvDestroyWindow("Example3_12_pre");
    cvDestroyWindow("Example3_12_post");   






    return 0;
}


