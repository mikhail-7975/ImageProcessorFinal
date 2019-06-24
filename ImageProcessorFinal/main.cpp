#include <opencv2/opencv.hpp>
#include "ImageProcessor.h"

int main() {
	TextAligner t;

	t.upload("testText.bmp");
	t.alignText();
	t.save("testText_aligned.bmp");
	return 0;
}