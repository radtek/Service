#include "ClientDll.h"

#include "include/SCUImage2/SCUImage.hpp"
#include "time.h"
using namespace cv;

//#if DEBUG
//#pragma comment(lib,"clientDLLd.lib")
//#else
//#pragma comment(lib,"clientDLL.lib")
//#endif
int main(){
	int i = 0;
	clock_t start_time = clock();
	//sendFile("http://202.115.52.117:8089", i);
	//clock_t end_time = clock();
	//std::cout << end_time - start_time << std::endl;

	///start_time = clock();
	sendAffineFile("http://127.0.0.1:8089", "./ReceiveFile/ThreePoint.xml", i);
	clock_t start_time2 = clock();
// 	float costs[20];
// 	float CenterCoordsX[20];
// 	float CenterCoordsY[20];
// 	float angles[20];
// 	float tempScales[20];
// 	int outNumber = 0;
// 	int result = 0;

	//Mat img = imread("./skew1.bmp", CV_8UC1);
	//uchar *data = img.data;
	//imshow("2", img);
	//cv::waitKey(0);
	float srcTrix[20] = { 176, 236, 579, 166, 352, 633, 428, 466, 270, 135 };
	float srcTriy[20] = { 114, 258, 671, 676, 407, 190, 178, 492, 532, 414 };
	int num = 10;
	float CalibrationX[20];
	float CalibrationY[20];
	int result;
	CCalibrationXYZNew("http://127.0.0.1:8089", srcTrix, srcTriy, num, CalibrationX, CalibrationY, result);
	//TempleMatch("http://202.115.52.117:8089",data, img.cols, img.rows, costs, CenterCoordsX, CenterCoordsY, angles, tempScales, &outNumber, result);
	clock_t start_time3 = clock();
	for (int i = 0; i < num; i++)
	{
		std::cout << srcTrix[i] << " "
			<< srcTriy[i] << " "
			<< num << " "
			<< CalibrationX[i] << " "
			<< CalibrationY[i] << " "
			<< result << std::endl;
	}	
	std::cout << start_time2 - start_time << std::endl;
	std::cout << start_time3 - start_time2 << std::endl;
	system("pause");
	return 0;
}