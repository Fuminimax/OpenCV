/*
 * viewVideo.c
 *
 *  Created on: 2009/11/10
 *      Author: tryout
 */

#include "highgui.h"

int main(int argc, char** argv){
	// Example2�Ƃ������O�̃E�B���h�E���쐬����
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	// �r�f�I�t�@�C������t���[����������悤�ɏ�������
	CvCapture *capture = cvCreateFileCapture(argv[1]);
	IplImage *frame;
	// �r�f�I�t�@�C�������[�v���ĕ\������
	while(1){
		// �r�f�I�t�@�C������t���[����ǂݏo��
		frame = cvQueryFrame(capture);
		if(!frame){
			break;
		}
		// Example2�̃E�B���h�E�Ƀt���[����\������
		cvShowImage("Example2", frame);
		// 33�~���b�L�[���͂�҂�
		char c = cvWaitKey(33);
		// �G�X�P�[�v�L�[���������΃��[�v�𔲂���
		if(c == 27){
			break;
		}
	}
	// CvCapture�ϐ����������
	cvReleaseCapture(&capture);
	// �E�B���h�E�����
	cvDestroyWindow("Example2");
	return 0;
}
