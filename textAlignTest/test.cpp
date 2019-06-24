#include <gtest/gtest.h>
#include "ImageProcessor.h"
#include <fstream>

TEST(UoloaadTest, correctTest) {
	TextAligner a;
	std::ifstream f("text0grad.bmp");
	ASSERT_EQ(a.upload("text0grad.bmp"), 0); 
}

TEST(UoloaadTest, noFile) {
	TextAligner a;
	ASSERT_EQ(a.upload("123.bmp"), 1);
}

TEST(SaveTest, saveTest) {
	TextAligner a;
	ASSERT_EQ(a.upload("text0grad.bmp"), 0);
	a.save("testSave.bmp");
	std::fstream testFile("testSave.bmp");
	EXPECT_TRUE(testFile);
	remove("testSave.bmp");
}

TEST(AlignText, 0_grad) {

}

TEST(AlignText, 30_grad) {

}

TEST(AlignText, 60_grad) {

}

TEST(AlignText, 90_grad) {

}