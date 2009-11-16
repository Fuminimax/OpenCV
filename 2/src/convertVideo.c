/*
 * convertVideo.c
 *
 *  Created on: 2009/11/14
 *      Author: tryout
 */

#include "cv.h"
#include "highgui.h"

void example2_4(IplImage *image){
	// 入力画像と出力画像を表示するウィンドウを作成する
	cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");

	// 入力画像を表示する
	cvShowImage("Example4-in", image);

	// 平滑化した出力を保持する画像を作成する
	IplImage *out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);
}
