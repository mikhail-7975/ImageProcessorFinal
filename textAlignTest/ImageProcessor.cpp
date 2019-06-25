#include "ImageProcessor.h"

ImageProcessor::~ImageProcessor()
{
}

int ImageProcessor::upload(const std::string name)
{
	_img = cv::imread(name, 0);
	duplicate = cv::imread(name, 0);
	if (_img.data == NULL) return 1; else return 0;
}

int ImageProcessor::save(const std::string name)
{
	if (_img.data == NULL) return 1;
	cv::imwrite(name, _img);
	return 0;
}

int TextAligner::alignText()
{
	double angle = computeAngle();

	std::cout << angle;
	rotateImg(angle);
	return 0;
}

double TextAligner::computeAngle()
{
	if (_img.data == NULL) return 0.;
	// Load in grayscale.
	cv::Mat img = _img;//cv::imread("text.bmp", 0);

	// Binarize
	cv::threshold(img, img, 225, 255, cv::THRESH_BINARY);

	// Invert colors
	cv::bitwise_not(img, img);

	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 3));
	cv::erode(img, img, element);

	std::vector<cv::Point> points;
	cv::Mat_<uchar>::iterator it = img.begin<uchar>();
	cv::Mat_<uchar>::iterator end = img.end<uchar>();
	for (; it != end; ++it)
		if (*it)
			points.push_back(it.pos());

	cv::RotatedRect box = cv::minAreaRect(cv::Mat(points));

	double angle = box.angle;
	if (angle < -45.)
		angle += 90.;

	cv::Point2f vertices[4];
	box.points(vertices);
	for (int i = 0; i < 4; ++i)
		cv::line(img, vertices[i], vertices[(i + 1) % 4], cv::Scalar(255, 0, 0), 1, 16);

	if (angle < -2) angle += 90;
	return angle;
}

double TextAligner::rotateImg(double angle)
{
	if (duplicate.data == NULL) return -1;
	if (angle == 0) {
		_img = duplicate;
		return 0;
	}
	cv::Mat img = duplicate;

	cv::bitwise_not(img, img);

	std::vector<cv::Point> points;
	cv::Mat_<uchar>::iterator it = img.begin<uchar>();
	cv::Mat_<uchar>::iterator end = img.end<uchar>();
	for (; it != end; ++it)
		if (*it)
			points.push_back(it.pos());

	cv::RotatedRect box = cv::minAreaRect(cv::Mat(points));

	cv::Mat rot_mat = cv::getRotationMatrix2D(box.center, angle, 1);

	cv::Mat rotated;
	cv::warpAffine(img, rotated, rot_mat, img.size(), cv::INTER_CUBIC);

	cv::bitwise_not(rotated, rotated);

	_img = rotated;
	//cv::imwrite("out.bmp", rotated);

	return 0;
}
