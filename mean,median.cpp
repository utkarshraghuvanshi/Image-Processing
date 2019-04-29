#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img, mean, median, gradient, laplacian, sobel, gaussian;
	img = imread("Lenna.jpg");
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", img);



	blur(img, mean, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);

	namedWindow("mean image", WINDOW_AUTOSIZE);
	imshow("mean image", mean);

	//medianblur
	medianBlur(img, median, 3);
	namedWindow("median image", WINDOW_AUTOSIZE);
	imshow("median image", mean);





	

	waitKey(0);
	return 0;

}