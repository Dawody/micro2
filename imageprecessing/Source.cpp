#include <opencv2/opencv.hpp>


#include "opencv2/core.hpp"
//#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"


#include <cctype>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

/// Global variables
Mat src;



vector <Point2f> pointbuf;

main(int, char** argv)
{


	/// Load an image
	src = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	if (src.empty())
	{
		std::cout<<"error/n/n";
	}


std::cout<<"start search\n";
	bool found = findChessboardCorners(src, Size(7,7), pointbuf, CV_CALIB_CB_ADAPTIVE_THRESH);
std::cout<<"end search\n";

	if (found)
		cout << "Chess board was found" << endl;
else
	std::cout<<"CAN'tFOUND\n";
	namedWindow("chess", WINDOW_AUTOSIZE);
	imshow("chess", src);
	float xmin = 10000, xmax = 0, ymin = 10000, ymax = 0;

	for (int i = 0; i < pointbuf.size(); i++)
	{
		cout << pointbuf[i].x << "    " << pointbuf[i].y << endl;
		if (pointbuf[i].x > xmax)
			xmax = pointbuf[i].x;
		if (pointbuf[i].x < xmin)
			xmin = pointbuf[i].x;
		if (pointbuf[i].y > ymax)
			ymax = pointbuf[i].y;
		if (pointbuf[i].y < ymin)
			ymin = pointbuf[i].y;
	}
	
	cout << endl << endl << endl << xmin << "    " << xmax << endl << ymin << "     " << ymax << endl;//215 220 665 660
	cout << xmax - xmin << "    " << ymax - ymin << endl;
	//Mat rec = cv::imread("chess.jpg");
	//rectangle(src,Point(xmin, ymin), Point(xmax, ymax), Scalar(0, 255, 255),-1,8);
	//namedWindow("Display window", WINDOW_AUTOSIZE);
	//imshow("Display window", src);
	float x2 = (xmax - xmin) / 6;
	float x3 = (ymax - ymin) / 6;
	xmin -= x2;
	xmax += x2;
	ymin -= x3;
	ymax += x3;
	Rect myROI(xmin, ymin, x2, x3);
	//Rect myROI(xmin, ymin, xmax - xmin, ymax - ymin);
	Mat cropped[1] = { src(myROI) };
	namedWindow("Display", WINDOW_AUTOSIZE);
	imshow("Display", cropped[0]);
	waitKey(0);


}
