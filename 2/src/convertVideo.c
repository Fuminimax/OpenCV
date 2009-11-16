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

	// 入力画像を表示するウィンドウを作成する
	cvShowImage("Example4-in", image);


}
