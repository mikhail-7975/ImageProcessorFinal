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
	TextAligner a;
	a.upload("0.bmp");
	a.alignText();
	a.save("testResult0.bmp");
}

TEST(AlignText, 10_grad) {
	TextAligner a;
	a.upload("10.bmp");
	a.alignText();
	a.save("testResult10.bmp");
}

TEST(AlignText, 20_grad) {
	TextAligner a;
	a.upload("20.bmp");
	a.alignText();
	a.save("testResult20.bmp");
}

TEST(AlignText, 30_grad) {
	TextAligner a;
	a.upload("30.bmp");
	a.alignText();
	a.save("testResult30.bmp");
}

TEST(AlignText, 40_grad) {
	TextAligner a;
	a.upload("40.bmp");
	a.alignText();
	a.save("testResult40.bmp");
}

TEST(AlignText, 50_grad) {
	TextAligner a;
	a.upload("50.bmp");
	a.alignText();
	a.save("testResult50.bmp");
}

TEST(AlignText, 60_grad) {
	TextAligner a;
	a.upload("60.bmp");
	a.alignText();
	a.save("testResult60.bmp");
}

TEST(AlignText, 70_grad) {
	TextAligner a;
	a.upload("70.bmp");
	a.alignText();
	a.save("testResult70.bmp");
}
