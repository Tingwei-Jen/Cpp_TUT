#include "DisplayImage.h"

int main(int argc, char** argv )
{
    if ( argc != 2 ){
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat img1;
    img1 = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );

    DisplayImage(img1);
    
    return 0;
}
