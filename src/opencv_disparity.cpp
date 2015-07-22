#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"

using namespace cv;

int main()
{
	Mat imgL =cv::imread("../img/piano/im0.png");
	Mat imgR =cv::imread("../img/piano/im1.png");

	Mat grayL, grayR;
	cvtColor(imgL, grayL, CV_BGR2GRAY);
	cvtColor(imgR, grayR, CV_BGR2GRAY);

	// See http://www.jayrambhia.com/blog/disparity-maps/ for further adjusting
	StereoBM sbm;
	sbm.state->SADWindowSize = 9;
	sbm.state->numberOfDisparities = 112;
	sbm.state->preFilterSize = 5;
	sbm.state->preFilterCap = 61;
	sbm.state->minDisparity = -39;
	sbm.state->textureThreshold = 507;
	sbm.state->uniquenessRatio = 0;
	sbm.state->speckleWindowSize = 0;
	sbm.state->speckleRange = 8;
	sbm.state->disp12MaxDiff = 1;

	Mat disp, disp8;
	sbm(grayL, grayR, disp);
	normalize(disp, disp8, 0, 255, CV_MINMAX, CV_8U);	

	Size size(564,384);
	resize(disp8,disp8,size);
	imshow("disp", disp8);
	waitKey();

	return 0;
}
