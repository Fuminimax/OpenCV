/*
 * convertVideo.c
 *
 *  Created on: 2009/11/14
 *      Author: tryout
 */

#include "cv.h"
#include "highgui.h"

void example2_4(IplImage *image){
	// ���͉摜�Əo�͉摜��\������E�B���h�E���쐬����
	cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");

	// ���͉摜��\������E�B���h�E���쐬����
	cvShowImage("Example4-in", image);


}
