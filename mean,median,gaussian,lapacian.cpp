#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
 
int main() {
	Mat img, mean, median, gradient, laplacian, sobel, gaussian;
	img = imread("lena_gray_512.jpg");
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", img);

 blur(img, mean,Size(3,3) ,Point(-1,-1), BORDER_DEFAULT);

 namedWindow("mean image", WINDOW_AUTOSIZE);
 imshow("mean image", mean);

 medianBlur(img, median, 3);
 namedWindow("median image", WINDOW_AUTOSIZE);
 imshow("median image", mean);

 GaussianBlur(img,gaussian,Size(3,3), 0, 0, BORDER_DEFAULT);
 namedWindow("Gaussian image", WINDOW_AUTOSIZE);
 imshow("Gaussian image", mean);

 Laplacian(img, laplacian, CV_8U,3, 1, 0, BORDER_DEFAULT);
 namedWindow("Laplacian image", WINDOW_AUTOSIZE);
 imshow("Laplacian image", mean);



 waitKey(0);
 return 0;

}