//---------------------------------------------------------
// 概要      : 文字伝達実験（カメラ）
// File Name : code(hsv).cpp
// Library   : OpenCV 2.0
//---------------------------------------------------------

#include <stdio.h>
#include <highgui.h>
#include <cv.h>

#pragma comment (lib,"cv200d.lib")
#pragma comment (lib,"cxcore200d.lib")
#pragma comment (lib,"highgui200d.lib")

#define WIDTH	720	//	キャプチャ画像の横幅
#define HEIGHT	480	//	キャプチャ画像の縦幅


int main( int argc, char** argv ){ 
	int key;					//	キー入力用の変数
	CvCapture *capture;				//	カメラキャプチャ用の構造体
	IplImage *frameImage;				//	キャプチャ画像用IplImage
	IplImage *hsvImage = cvCreateImage( cvSize(WIDTH,HEIGHT), IPL_DEPTH_8U, 3 );			//	HSV画像用IplImage
	char windowNameCapture[] = "Capture";			//キャプチャした画像を表示するウィンドウの名前
	int x, y;
	int m,d,ss;
	uchar h0,s0,v0,h1,s1,v1,h2,s2,v2,h3,s3,v3,v;

	//	カメラを初期化する
	if ( ( capture = cvCreateCameraCapture( 0 ) ) == NULL ) {
		//	カメラが見つからなかった場合
		printf( "カメラが見つかりません\n" );
		key = cvWaitKey( 10 );
	}

	//	ウィンドウを生成する
    cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );
	m=0;
	d=0;
	ss=0;
	v=0;
	//	メインループ
	while ( 1 ) {
		//	カメラからの入力画像フレームをframeImageに格納する
		frameImage = cvQueryFrame( capture );
		cvCvtColor(frameImage,hsvImage,CV_BGR2HSV);
	
      /* 画素値を直接操作する*/   
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
		printf("コード　d= %c   \n",d);



			m=0;
			d=0;
			ss=0;
		}



		//	画像を表示する
		cvShowImage( windowNameCapture, frameImage );
	
		//	'q'キーが入力されたらループを抜ける
		key = cvWaitKey( 10 );
		if ( key == 'q' ) 
			break;

//		printf ("%d \n",s);

	}
	
	//	キャプチャを解放する
	cvReleaseCapture( &capture );
	//	ウィンドウを破棄する
	cvDestroyWindow( windowNameCapture );

	return 0;
}
