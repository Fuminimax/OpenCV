#include "cv.h"
#include "highgui.h"

int			g_slider_position = 0;
CvCapture	*g_capture = NULL;

// スライドバーが動かされるとコールバックされる関数
// 引数posはスライドバーが動かされたフレーム位置
void onTrackbarSlide(int pos){
	// ビデオファイルを動かされたフレーム位置まで動かす
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char **argv){
	// Example3という名前のウィンドウを作成する
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	// ビデオファイルからフレームを扱えるように準備する
	g_capture = cvCreateFileCapture(argv[1]);
	// このビデオファイルのフレーム数を取得
	int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

	// フレームが0で無ければ
	if(frames != 0){
		// Example3というウィンドウにPositionという名前でスライドバーを作成し、
		// スライドバーに紐付いた変数のポインタを渡し、最大のフレーム数、スライドバーが動かされた時のコールバック変数を指定する
		cvCreateTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
	}

	IplImage *frame;
	while(1){
		// ビデオファイルからフレームを読み出す
		frame = cvQueryFrame(g_capture);
		if(!frame){
			break;
		}
		// Example2のウィンドウにフレームを表示する
		cvShowImage("Example3", frame);
		// 33ミリ秒キー入力を待つ
		char c = cvWaitKey(33);
		// エスケープキーが押されればループを抜ける
		if(c == 27){
			break;
		}
	}
	// CvCapture変数を解放する
	cvReleaseCapture(&g_capture);
	// ウィンドウを閉じる
	cvDestroyWindow("Example3");

	return 0;
}
