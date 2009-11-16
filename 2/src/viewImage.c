/*
 * viewImage.c
 *
 *  Created on: 2009/11/10
 *      Author: tryout
 */

#include "highgui.h"

int main(int argc, char** argv){
	// 第１引数の画像をロード
	IplImage *img = cvLoadImage(argv[1], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	// Example1という名前のウィンドウを作成する
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	// Example1のウィンドウにイメージを読み込む
	cvShowImage("Example1", img);
	// 何かキーが押下されるまで待つ
	cvWaitKey(0);
	// イメージをリリースする
	cvReleaseImage(&img);
	// ウィンドウを閉じる
	cvDestroyWindow("Example1");
	return 0;
}
