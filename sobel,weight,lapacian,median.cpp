#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;


void insertionSort(int window[])
{
    int temp, i , j;
    for(i = 0; i < 9; i++){
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--){
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}

int main()
{
      Mat src;

      // Load an image

	  src = imread("Lenna.png",0);

      if( !src.data )
      { return -1; }

      //create a sliding window of size 9
      int window[9];

      Mat  mean = src.clone();
	  Mat meadian = src.clone();
	  Mat weighted = src.clone();
	  Mat sobel = src.clone();
	  Mat laplacian = src.clone();

        for(int y = 0; y < src.rows; y++)
			for (int x = 0; x < src.cols; x++)
			{
				mean.at<uchar>(y, x) = 0.0;
				meadian.at<uchar>(y, x) = 0.0;
				weighted.at<uchar>(y, x) = 0.0;
				sobel.at<uchar>(y, x) = 0.0;
				laplacian.at<uchar>(y, x) = 0.0;
				
			}
		
        for(int y = 1; y < src.rows - 1; y++){
            for(int x = 1; x < src.cols - 1; x++){

                // Pick up window element

                window[0] = src.at<uchar>(y - 1 ,x - 1);
                window[1] = src.at<uchar>(y, x - 1);
                window[2] = src.at<uchar>(y + 1, x - 1);
                window[3] = src.at<uchar>(y - 1, x);
                window[4] = src.at<uchar>(y, x);
                window[5] = src.at<uchar>(y + 1, x);
                window[6] = src.at<uchar>(y - 1, x + 1);
                window[7] = src.at<uchar>(y, x + 1);
                window[8] = src.at<uchar>(y + 1, x + 1);

				 
                // sort the window to find median
                
				insertionSort(window);
                // assign the median to centered element of the matrix
				meadian.at<uchar>(y, x) = window[4];

		        mean.at<uchar>(y, x) = (window[0] + window[1] + window[2] + window[3] + window[4] + window[5] + window[6] + window[7] + window[8]) / 9;

		        weighted.at<uchar>(y, x) = ((window[0] + window[1] + window[2] + window[3] + 2 * window[4] + window[5] + window[6] + window[7] + window[8]) / 10);
				sobel.at<uchar>(y, x) = (-1 * window[0]) + (-2 * window[1]) + (-1 * window[2]) + (1 * window[6]) + (2 * window[7]) + (1 * window[8]);
				laplacian.at<uchar>(y, x) = (1 * window[1]) + (1 * window[3]) + (-4 * window[4]) + (1 * window[5]) + (1 * window[7]);
                



            }

        }
	
        namedWindow("Initial");
        imshow("Initial", src);

        namedWindow("Median");
        imshow("Median", meadian);

		namedWindow("Mean");
		imshow("Mean", mean);

		namedWindow("Weighted");
		imshow("Weighted", weighted);

		namedWindow("Sobel");
		imshow("Sobel", sobel);


		namedWindow("Laplacian");
		imshow("Laplacian", laplacian);




		waitKey(0);


    return 0;
}