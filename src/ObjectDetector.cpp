#include "ObjectDetector.h"
#include <vector>
#include "Visualiser.h"

void objectDetector::detector(std::string classifierName, std::string videoPath) {
	cv::VideoCapture cap(videoPath);
	cv::Mat frame;
	cv::Mat grayscale_frame;
	cv::CascadeClassifier classifier(classifierName);
	std::vector<cv::Rect> boundingBox;
	visualiser visualiser;

	if (!cap.isOpened()) {
	cout << "Video not captured" << endl;
	return;
	}

	
	while (cap.isOpened())
	{
		if (cap.read(frame))  
		{
			cv::cvtColor(frame, grayscale_frame, cv::COLOR_BGR2GRAY);
			classifier.detectMultiScale(grayscale_frame, boundingBox, 1.1, 3, 0 | CASCADE_FIND_BIGGEST_OBJECT | CASCADE_SCALE_IMAGE, Size(30, 30), Size(200, 200));
			visualiser.visualiseBoundingBox(boundingBox, frame);
		}
		if (waitKey(1) == 13)
		{
			break;
		}
	}


	cap.release();
	destroyAllWindows();

	
	return;
}