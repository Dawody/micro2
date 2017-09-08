#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src, src2, src_gray;
int chess[8][8];
vector<vector<Point2f> > expected_corners;
vector<vector<Point2f> > final_corners;
char gcolours[8][8];
Vec3b colours[8][8];
//Vec3b wpiece(230, 230, 230);
//Vec3b bpiece(20, 20, 20);
//Vec3b bsquare(55, 120, 195);
//Vec3b wsquare(208, 130, 0);
float accepted_error = 15;
float length_of_single_square, width_of_single_square;
float xmin, xmax, ymin, ymax;
double qualityLevel = 0.06;
double minDistance = 20;
int blockSize = 3;
bool useHarrisDetector = false;
double k = 0.04;
RNG rng(12345);
/*char* */ string source_window = "Image";
ofstream file("colours2.txt");
ofstream file2("colours3.txt");
ofstream file3("chess.txt");
void goodFeaturesToTrack_Demo(int, void*)
{
	expected_corners.clear();
	xmin = 1000000; xmax = 0;
	ymin = 1000000; ymax = 0;
	vector<Point2f> corners;
	src2 = src.clone();
	goodFeaturesToTrack(src_gray,
		corners,
		0,
		qualityLevel,
		minDistance,
		Mat(),
		blockSize,
		useHarrisDetector,
		k);
	cout << "** Number of corners detected: " << corners.size() << endl;
	if (corners.size() <= 8)
	{
		return;
	}
	int r = 4;
	for (int i = 0; i < corners.size(); i++)
	{
		/*circle(src2, corners[i], r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
		rng.uniform(0, 255)), -1, 8, 0);*/
		if (corners[i].x < xmin)
			xmin = corners[i].x;
		if (corners[i].x > xmax)
			xmax = corners[i].x;
		if (corners[i].y < ymin)
			ymin = corners[i].y;
		if (corners[i].y > ymax)
			ymax = corners[i].y;
	}
	length_of_single_square = (xmax - xmin) / 8;
	width_of_single_square = (ymax - ymin) / 8;
	cout << length_of_single_square<<"   ";
	cout << width_of_single_square << endl;
	for (int i = 0; i < 9; i++)
	{
		vector<Point2f> x;
		for (int j = 0; j < 9; j++)
		{
			x.push_back(Point2f(xmin + length_of_single_square*j, ymin + width_of_single_square*i));
		}
		expected_corners.push_back(x);
	}
	final_corners = expected_corners;
	for (int i = 0; i < final_corners.size(); i++)
	{
		for (int k = 0; k < final_corners[i].size(); k++)
		{
			for (int j = 0; j < corners.size(); j++)
			{
				float dxcurrent = expected_corners[i][k].x - corners[j].x;
				float dycurrent = expected_corners[i][k].y - corners[j].y;
				float dxprevious = final_corners[i][k].x - corners[j].x;
				float dyprevious = final_corners[i][k].y - corners[j].y;
				float current = sqrt(dxcurrent*dxcurrent + dycurrent*dycurrent);
				float previous = sqrt(dxprevious*dxprevious + dyprevious*dyprevious);
				/*if ((fabs(expected_corners[i][k].x - corners[j].x) <= accepted_error) && (fabs(expected_corners[i][k].y - corners[j].y) <= accepted_error))
				{
						if (final_corners[i][k] != corners[j] && fabs(expected_corners[i][k].x - corners[j].x)<fabs(final_corners[i][k].x - corners[j].x))
						{
							final_corners[i][k] = corners[j];
							break;
						}
				}*/
				if (current < accepted_error&&current<previous)
				{
					final_corners[i][k] = corners[j];
				}
			}
			/*circle(src2, final_corners[i][k], r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
			rng.uniform(0, 255)), -1, 8, 0);*/
		}
	}
	vector<vector<Point2f> > temp_corners;
	for (int i = final_corners.size() - 1; i >= 0; i--)
	{
		vector<Point2f> x;
		for (int k = 0; k < final_corners[i].size(); k++)
		{
			x.push_back(final_corners[i][k]);
		}
		temp_corners.push_back(x);
	}
	final_corners = temp_corners;

	for (int i = 0; i < final_corners.size() - 1; i++)
	{
		for (int k = 0; k < final_corners[i].size() - 1; k++)
		{
			Point2i center;
			center.x = final_corners[i][k].x + ((final_corners[i][k + 1].x - final_corners[i][k].x) / 2);
			center.y = final_corners[i][k].y + ((final_corners[i + 1][k].y - final_corners[i][k].y) / 2);
			Vec3b colour = src.at<Vec3b>(Point(center.x, center.y));
			char gcolour = src_gray.at<char>(Point(center.x, center.y));
			gcolours[i][k] = gcolour;
			colours[i][k] = colour;
			circle(src2, center, r, Scalar(rng.uniform(0, 255), rng.uniform(0, 255),
				rng.uniform(0, 255)), -1, 8, 0);
			int x77 = static_cast<int>(gcolours[i][k]);
			if (x77 < 0)
				x77 += 256;
			if (static_cast<int>(colour.val[0]) <= 70 && static_cast<int>(colour.val[1]) <= 70 && static_cast<int>(colour.val[2]) <= 70)
			{
				chess[i][k] = 0;
			}
			else if (static_cast<int>(colour.val[2]) >= 110)
			{
				chess[i][k] = 1;
			}
			else
			{
				chess[i][k] = 2;
			}
		}
	}

	//char key = (char)waitKey(/*cap.isOpened() ? 50 : 500*/50);
	/*if ((char)key == 'h')
	{
		for (int i = 0; i < 8; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				Vec3b colour = colours[i][k];
				file << i << "   " << k << "   " << static_cast<int>(colour.val[0]) << "   " << static_cast<int>(colour.val[1]) << "   " << static_cast<int>(colour.val[2]) << endl;
				file2 << i << "   " << k << "   ";
				int x77 = static_cast<int>(gcolours[i][k]);
				if (x77 < 0)
					x77 += 256;
				file2 << x77 << endl;
				file3 << (char)chess[i][k] << "   ";
			}
			file3 << endl;
		}

		file << endl << endl;
		file2 << endl << endl;
		file3 << endl << endl;
	}*/
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src2);
}
void outputArray()
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			Vec3b colour = colours[i][k];
			file << i << "   " << k << "   " << static_cast<int>(colour.val[0]) << "   " << static_cast<int>(colour.val[1]) << "   " << static_cast<int>(colour.val[2]) << endl;
			file2 << i << "   " << k << "   ";
			int x77 = static_cast<int>(gcolours[i][k]);
			if (x77 < 0)
				x77 += 256;
			file2 << x77 << endl;
			file3 << chess[i][k] << "   ";
		}
		file3 << endl;
	}

	file << endl << endl;
	file2 << endl << endl;
	file3 << endl << endl;
}

int main(int argc, char** argv)
{
	VideoCapture cap(1);
	if (!cap.isOpened())
		return -1;
	//Mat src = imread(argv[1],IMREAD_COLOR);
	//src = imread(argv[1]/*,IMREAD_REDUCED_COLOR_8*/);


	while (1)
	{
		//char key = (char)waitKey(/*cap.isOpened() ? 50 : 50);
		//createTrackbar("Max  corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo);
		cap >> src; // get a new frame from camera
		cvtColor(src, src_gray, CV_BGR2GRAY);
		goodFeaturesToTrack_Demo(0, 0);
		char key = (char)waitKey(50);

		if (key == 27)
			break;
		else if ((char)key == 'h')
			outputArray();
	}
	return 0;
}
