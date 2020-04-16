#include "Visualiser.h"


void visualiser::visualiseBoundingBox(std::vector<cv::Rect> boundingBox, Mat frame)
{
	for (std::vector<cv::Rect>::iterator it = boundingBox.begin(); it != boundingBox.end(); ++it) {
		cv::rectangle(frame, *it, cv::Scalar(0, 0, 255));
	}
	imshow("Classifier", frame);
	return;
}