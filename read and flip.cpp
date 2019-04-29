
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	double alpha, beta;

	Mat src1, src2;

	src1 = imread("LenaRGB.bmp");

	if (!src1.data) { printf("Error loading src1 n"); return -1; }


	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", src1);
	for (int i = -1;i < 2;i++)
	{
		flip(src1, src2, i);
		namedWindow("Flip", WINDOW_AUTOSIZE);
		imshow("Flip", src2);
		waitKey(0);
	}
	waitKey(0);
	return 0;
}

