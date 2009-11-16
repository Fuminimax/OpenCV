#include "cv.h"
#include "highgui.h"

int			g_slider_position = 0;
CvCapture	*g_capture = NULL;

// �X���C�h�o�[�����������ƃR�[���o�b�N�����֐�
// ����pos�̓X���C�h�o�[���������ꂽ�t���[���ʒu
void onTrackbarSlide(int pos){
	// �r�f�I�t�@�C���𓮂����ꂽ�t���[���ʒu�܂œ�����
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char **argv){
	// Example3�Ƃ������O�̃E�B���h�E���쐬����
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	// �r�f�I�t�@�C������t���[����������悤�ɏ�������
	g_capture = cvCreateFileCapture(argv[1]);
	// ���̃r�f�I�t�@�C���̃t���[�������擾
	int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

	// �t���[����0�Ŗ������
	if(frames != 0){
		// Example3�Ƃ����E�B���h�E��Position�Ƃ������O�ŃX���C�h�o�[���쐬���A
		// �X���C�h�o�[�ɕR�t�����ϐ��̃|�C���^��n���A�ő�̃t���[�����A�X���C�h�o�[���������ꂽ���̃R�[���o�b�N�ϐ����w�肷��
		cvCreateTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
	}

	IplImage *frame;
	while(1){
		// �r�f�I�t�@�C������t���[����ǂݏo��
		frame = cvQueryFrame(g_capture);
		if(!frame){
			break;
		}
		// Example2�̃E�B���h�E�Ƀt���[����\������
		cvShowImage("Example3", frame);
		// 33�~���b�L�[���͂�҂�
		char c = cvWaitKey(33);
		// �G�X�P�[�v�L�[���������΃��[�v�𔲂���
		if(c == 27){
			break;
		}
	}
	// CvCapture�ϐ����������
	cvReleaseCapture(&g_capture);
	// �E�B���h�E�����
	cvDestroyWindow("Example3");

	return 0;
}
