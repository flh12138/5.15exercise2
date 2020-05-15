#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{

	cv::Mat srcMat = imread("E:\\PIC\\etest.jpg"); //读取图像
	
	//把3通道图像转换成3个单通道图像
	cv::Mat R_Mat, G_Mat, B_Mat;
	vector<Mat>channels;
	split(srcMat, channels);
	B_Mat = channels.at(0);
	G_Mat = channels.at(1);
	R_Mat = channels.at(2);

	//将3个通道图像分别进行直方图均衡化
	cv::Mat dst_R_Mat;
	cv::Mat dst_G_Mat;
	cv::Mat dst_B_Mat;
	equalizeHist(B_Mat, dst_B_Mat);
	equalizeHist(G_Mat, dst_G_Mat);
	equalizeHist(R_Mat, dst_R_Mat);

	//进行通道图像的合并
	cv::Mat dstMat;
    channels.at(0)= dst_B_Mat;
	channels.at(1)= dst_G_Mat;
    channels.at(2)= dst_R_Mat;
	merge(channels,dstMat);
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
}