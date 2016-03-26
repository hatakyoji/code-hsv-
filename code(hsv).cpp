//---------------------------------------------------------
// �T�v      : �����`�B�����i�J�����j
// File Name : code(hsv).cpp
// Library   : OpenCV 2.0
//---------------------------------------------------------

#include <stdio.h>
#include <highgui.h>
#include <cv.h>

#pragma comment (lib,"cv200d.lib")
#pragma comment (lib,"cxcore200d.lib")
#pragma comment (lib,"highgui200d.lib")

#define WIDTH	720	//	�L���v�`���摜�̉���
#define HEIGHT	480	//	�L���v�`���摜�̏c��


int main( int argc, char** argv ){ 
	int key;					//	�L�[���͗p�̕ϐ�
	CvCapture *capture;				//	�J�����L���v�`���p�̍\����
	IplImage *frameImage;				//	�L���v�`���摜�pIplImage
	IplImage *hsvImage = cvCreateImage( cvSize(WIDTH,HEIGHT), IPL_DEPTH_8U, 3 );			//	HSV�摜�pIplImage
	char windowNameCapture[] = "Capture";			//�L���v�`�������摜��\������E�B���h�E�̖��O
	int x, y;
	int m,d,ss;
	uchar h0,s0,v0,h1,s1,v1,h2,s2,v2,h3,s3,v3,v;

	//	�J����������������
	if ( ( capture = cvCreateCameraCapture( 0 ) ) == NULL ) {
		//	�J������������Ȃ������ꍇ
		printf( "�J������������܂���\n" );
		key = cvWaitKey( 10 );
	}

	//	�E�B���h�E�𐶐�����
    cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );
	m=0;
	d=0;
	ss=0;
	v=0;
	//	���C�����[�v
	while ( 1 ) {
		//	�J��������̓��͉摜�t���[����frameImage�Ɋi�[����
		frameImage = cvQueryFrame( capture );
		cvCvtColor(frameImage,hsvImage,CV_BGR2HSV);
	
      /* ��f�l�𒼐ڑ��삷��*/   
		x = 160;
		y = 120;

		h0 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s0 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];    // G      
		v0 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

    	     frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 161;
		y = 120;
		h1 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s1 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];    // G      
		v1 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 160;
		y = 121;

		h2 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s2= hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];     // G      
		v2 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

       	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;


		x = 161;
		y = 121;
		h3 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s3 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];    // G      
		v3 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
     	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		v=(v0+v1+v2+v3)/4;

		if (v<200) {
			
			if(m==0)
				ss=1;
		
			if(ss)
				m=m+1;	
			printf("0 m= %d,d=%02X  \n",m,d);
		}
		else {
//			printf("%d \n",m);			
	
			if(ss){
				d=d+(1<<(m-1));
				m=m+1;}
			printf("1 m= %d,d=%02X  \n",m,d);
			
			
		}

		if(m>8){
		printf("�R�[�h�@d= %c   \n",d);



			m=0;
			d=0;
			ss=0;
		}



		//	�摜��\������
		cvShowImage( windowNameCapture, frameImage );
	
		//	'q'�L�[�����͂��ꂽ�烋�[�v�𔲂���
		key = cvWaitKey( 10 );
		if ( key == 'q' ) 
			break;

//		printf ("%d \n",s);

	}
	
	//	�L���v�`�����������
	cvReleaseCapture( &capture );
	//	�E�B���h�E��j������
	cvDestroyWindow( windowNameCapture );

	return 0;
}
