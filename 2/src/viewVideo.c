/*
 * viewVideo.c
 *
 *  Created on: 2009/11/10
 *      Author: tryout
 */

#include "highgui.h"

int main(int argc, char** argv){
	// Example2という名前のウィンドウを作成する
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	// ビデオファイルからフレームを扱えるように準備する
	CvCapture *capture = cvCreateFileCapture(argv[1]);
	IplImage *frame;
	// ビデオファイルをループして表示する
	while(1){
		// ビデオファイルからフレームを読み出す
		frame = cvQueryFrame(capture);
		if(!frame){
			break;
		}
		// Example2のウィンドウにフレームを表示する
		cvShowImage("Example2", frame);
		// 33ミリ秒キー入力を待つ
		char c = cvWaitKey(33);
		// エスケープキーが押されればループを抜ける
		if(c == 27){
			break;
		}
	}
	// CvCapture変数を解放する
	cvReleaseCapture(&capture);
	// ウィンドウを閉じる
	cvDestroyWindow("Example2");
	return 0;
}
