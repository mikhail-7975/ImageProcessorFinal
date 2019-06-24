#include <gtest/gtest.h>
#include "ImageProcessor.h"
#include <fstream>

//working catalog
//F:\OOP_4_sem\Final_prject_ImageTurn\ImageProcessorFinal\x64\Debug

TEST(UoloaadTest, correctTest) {
	TextAligner a;
	ASSERT_EQ(a.upload("text0grad.bmp"), 0); 
}

TEST(UoloaadTest, noFile) {
	TextAligner a;
	ASSERT_EQ(a.upload("123.bmp"), 1);
}

TEST(SaveTest, correctSave) {
	TextAligner a;
	ASSERT_EQ(a.upload("text0grad.bmp"), 0);
	a.save("testSave.bmp");
	TextAligner b;
	ASSERT_EQ(b.upload("testSave.bmp"), 0);
	remove("testSave.bmp");
}

TEST(SaveTest, emptyFileSave) {
	TextAligner a;
	ASSERT_EQ(a.save("testSave.bmp"), 1);
}

TEST(AlignText, 0_grad) {

}

TEST(AlignText, 30_grad) {

}

TEST(AlignText, 60_grad) {

}

TEST(AlignText, 90_grad) {

}