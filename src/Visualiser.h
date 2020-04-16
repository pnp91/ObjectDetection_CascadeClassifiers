#pragma once
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "util.h"

using namespace cv;

class visualiser
{

public:
	void visualiseBoundingBox(std::vector<cv::Rect> boundingBox, Mat frame);
};