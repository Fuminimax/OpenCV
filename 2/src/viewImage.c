/*
 * viewImage.c
 *
 *  Created on: 2009/11/10
 *      Author: tryout
 */

#include "highgui.h"

int main(int argc, char** argv){
	// ��P�����̉摜�����[�h
	IplImage *img = cvLoadImage(argv[1], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	// Example1�Ƃ������O�̃E�B���h�E���쐬����
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	// Example1�̃E�B���h�E�ɃC���[�W��ǂݍ���
	cvShowImage("Example1", img);
	// �����L�[�����������܂ő҂�
	cvWaitKey(0);
	// �C���[�W�������[�X����
	cvReleaseImage(&img);
	// �E�B���h�E�����
	cvDestroyWindow("Example1");
	return 0;
}
