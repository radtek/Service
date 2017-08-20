#include "ClientDll.h"

#include "include/SCUImage2/SCUImage.hpp"
#include "time.h"
using namespace cv;

#if DEBUG
#pragma comment(lib,"clientDLLd.lib")
#else
#pragma comment(lib,"clientDLL.lib")
#endif
int main(){
	int i = 0;
	clock_t start_time = clock();
	sendFile("http://202.115.52.117:8089", i);

	clock_t start_time2 = clock();

	float costs[20];
	float CenterCoordsX[20];
	float CenterCoordsY[20];
	float angles[20];
	float tempScales[20];
	int outNumber = 0;
	int result = 0;

	Mat img = imread("./skew1.bmp", CV_8UC1);
	uchar *data = img.data;
	//imshow("2", img);
	//cv::waitKey(0);

	TempleMatch("http://202.115.52.117:8089",data, img.cols, img.rows, costs, CenterCoordsX, CenterCoordsY, angles, tempScales, &outNumber, result);
	clock_t start_time3 = clock();
	for (int i = 0; i < outNumber;i++)
	{
		std::cout << costs[0] << " "
			<< CenterCoordsX[0] << " "
			<< CenterCoordsY[0] << " "
			<< angles[0] << " "
			<< tempScales[0] << " "
			<< outNumber << " " << result << std::endl;
	}	
	std::cout << start_time2 - start_time << std::endl;
	std::cout << start_time3 - start_time2 << std::endl;
	system("pause");
	return 0;
}