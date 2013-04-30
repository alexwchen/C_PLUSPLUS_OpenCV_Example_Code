#include "cv.h"
#include <stdio.h>

int main()
{
    // Create an OpenCV Matrix containing some fixed data.
    //
    float vals[] = { 0.866025, -0.500000, 0.500000, 0.866025};
     
    CvMat rotmat;
    
    // cvInitMatHeader Method (mat, rows, cols, type, data, step)
    cvInitMatHeader(
      &rotmat,  // mat
      2,        // rows
      2,        // cols
      CV_32FC1, // type
      vals      // data
    );
    printf("Ex 3_3 matrix initialized\n");


    // Matrix created (init all 0 ) and accessed [3,2]
    // cvCreateMat(int rows, int cols, int type) 
    CvMat* mat = cvCreateMat( 5, 5, CV_32FC1 );

    // CV_MAT_ELEM( matrix, elemtype, row, col )
    float element_3_2 = CV_MAT_ELEM( *mat, float, 3, 2 );
    printf("Exercise 3_4, matrix created and accessed [3,2]=%f\n",element_3_2);
  


    // cvCreateMat(int rows, int cols, int type) 
    CvMat* matTwo = cvCreateMat( 5, 5, CV_32FC1 );
    
    // ////////////////////////////////////////////////
    // Good to Know But Should Not Use ( Not Efficient )
    // ////////////////////////////////////////////////
    // Different Method of Setting Value in cvMat:
    // Method 1
    float Element_3_2 = 7.7;
    *( (float*)CV_MAT_ELEM_PTR( *matTwo, 3, 2 ) ) = Element_3_2;

    // Different Method of Setting Value in cvMat:
    // Method 2
    cvmSet( matTwo, 2, 2, 0.5000 );
    
    // Different Method of Setting Value in cvMat:
    // Method 3
    cvSetReal2D( matTwo, 3, 3, 0.3300 );
    
    
    printf("Exercise 3_5, matrix created and accessed [3,2]=%f, [2,2]=%f, [3,3]=%f\n",CV_MAT_ELEM( *mat, float, 3, 2 ),CV_MAT_ELEM( *mat, float, 2, 2 ),CV_MAT_ELEM( *mat, float, 3, 3 ));
    
    // ////////////////////////////////////////////////
    // Access Mat Value (Sum Up All Val in cvMat)
    // ////////////////////////////////////////////////
    
    float s = 0.0f;
    for( int row=0; row<mat->height; row++ ) {
      float* ptr = mat->data.fl + row * mat->step/4;
      for( int col=0; col<mat->width; col++ ) {
        s += *ptr++;
      }
    }
    printf("Sum of cvMat is %f\n", s);

    


}
