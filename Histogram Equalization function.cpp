

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	
	Mat image = imread("Lenna.jpg");

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); 
		return -1;
	}

	
	cvtColor(image, image, COLOR_BGR2GRAY);

	
	Mat hist_equalized_image;
	equalizeHist(image, hist_equalized_image);

	
	String windowNameOfOriginalImage = "Original Image";
	String windowNameOfHistogramEqualized = "Histogram Equalized Image";

	
	namedWindow(windowNameOfOriginalImage, WINDOW_AUTOSIZE);
	namedWindow(windowNameOfHistogramEqualized, WINDOW_AUTOSIZE);

	
	imshow(windowNameOfOriginalImage, image);
	imshow(windowNameOfHistogramEqualized, hist_equalized_image);




	waitKey(0); 

	destroyAllWindows(); 

	return 0;
}