#include <opencv2/opencv.hpp>
#include "ImageProcessor.h"

int main() {
	TextAligner t;

	t.upload("text.bmp");
	t.alignText();
	t.save("rotated1.bmp");
	return 0;
}