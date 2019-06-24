#pragma once
#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
	ImageProcessor() = default;
	virtual ~ImageProcessor();
	int upload(const std::string name);
	int save(const std::string name);

protected:
	
	cv::Mat _img;
	cv::Mat result;
};

class TextAligner : public ImageProcessor {
public:
	int alignText();
private:
 
	double computeAngle();
	double rotateImg(double angle); 
	
};
