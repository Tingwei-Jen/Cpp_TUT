#include "DisplayImage.h"

void DisplayImage(Mat img)
{
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", img);
    waitKey(0);
}

