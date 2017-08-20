#include "soapserviceProxy.h"
#include "service.nsmap"

#include "fstream"
#include "iostream"
//#include "include/SCUImage2/SCUImage.hpp"
#include "ClientDll.h"


using namespace std;

void sendFile(const char* endpoint, int& outResult){
	serviceProxy proxy;
	proxy.soap_endpoint = endpoint;
	ns__TempleFiles _inPutFile;

	fstream img;
	img.open("./test3/0.bmp", std::ios::in | ios::binary);
	img.seekg(0, std::ios_base::end);
	int imgsize = img.tellg();
	img.seekg(0, std::ios_base::beg);
	_inPutFile.image.__size = imgsize;
	_inPutFile.image.__ptr = new UCHAR[imgsize];
	img.read((char*)_inPutFile.image.__ptr, imgsize);
	img.close();

	fstream img1;
	img1.open("./test3/1.bmp", std::ios::in|ios::binary);
	img1.seekg(0, std::ios_base::end);
	int img1size = img1.tellg();
	img1.seekg(0, std::ios_base::beg);
	_inPutFile.image2.__size = img1size;
	_inPutFile.image2.__ptr = new UCHAR[img1size];
	img1.read((char*)_inPutFile.image2.__ptr, img1size);
	img1.close();

	fstream img2;
	img2.open("./test3/2.bmp", std::ios::in | ios::binary);
	img2.seekg(0, std::ios_base::end);
	int img2size = img2.tellg();
	img2.seekg(0, std::ios_base::beg);
	_inPutFile.image3.__size = img2size;
	_inPutFile.image3.__ptr = new UCHAR[img2size];
	img2.read((char*)_inPutFile.image3.__ptr, img2size);
	img2.close();

	fstream matchTemPlate;
	matchTemPlate.open("./test3/matchTemPlate.xml", std::ios::in | ios::binary);
	matchTemPlate.seekg(0, std::ios_base::end);
	int matchTemPlateSize = matchTemPlate.tellg();
	matchTemPlate.seekg(0, std::ios_base::beg);
	_inPutFile.matchTemPlate.__size = matchTemPlateSize;
	_inPutFile.matchTemPlate.__ptr = new UCHAR[matchTemPlateSize];
	matchTemPlate.read((char*)_inPutFile.matchTemPlate.__ptr, matchTemPlateSize);
	matchTemPlate.close();

	fstream tplgray;
	tplgray.open("./test3/tplgray.jpg", std::ios::in | ios::binary);
	tplgray.seekg(0, std::ios_base::end);
	int tplgraySize = tplgray.tellg();
	tplgray.seekg(0, std::ios_base::beg);
	_inPutFile.tplgray.__size = tplgraySize;
	_inPutFile.tplgray.__ptr = new UCHAR[tplgraySize];
	tplgray.read((char*)_inPutFile.tplgray.__ptr, tplgraySize);
	tplgray.close();

	int i = 0;
	outResult = 0;
	if (proxy.getFileService(_inPutFile, i) == SOAP_OK)
	{		
		proxy.destroy();	
		if (i ==10086)
		{
			cout << "successful" << endl;
			outResult = 1;
		}
		else if (i == 10010){
			cout << "upLoad Failed" << endl;			
		}
		else{
			cout << "Connect Failed" << endl;			
		}

	}
	else if (proxy.error)
	{
		proxy.soap_stream_fault(std::cerr);
		proxy.destroy();
	}
	delete[] _inPutFile.image.__ptr;
	delete[] _inPutFile.image2.__ptr;
	delete[] _inPutFile.image3.__ptr;
	delete[] _inPutFile.matchTemPlate.__ptr;
	delete[] _inPutFile.tplgray.__ptr;
	return;
}

void TempleMatch(const char* endpoint, unsigned char* imggray, int widthImg, int heightImg, float* costs, float* CenterCoordsX, float* CenterCoordsY, float* angles, float* tempScales, int* outNumber, int& outResult){
	serviceProxy proxy;
	proxy.soap_endpoint = endpoint;
	ns__TempleMatchPARA TempleMatchPARA;
	TempleMatchPARA.heightImg = heightImg;
	TempleMatchPARA.widthImg = widthImg;
	TempleMatchPARA.imggray.__size = heightImg*widthImg;
	TempleMatchPARA.imggray.__ptr = new unsigned char[TempleMatchPARA.imggray.__size];
	memcpy(TempleMatchPARA.imggray.__ptr, imggray, widthImg*heightImg);
	ns__TempleMatchOUT result;

	if (proxy.TempleMatchService(TempleMatchPARA, result) == SOAP_OK)
	{
		proxy.destroy();
		memcpy(costs, &result.fcosts, sizeof(result.fcosts));
		memcpy(CenterCoordsX, &result.fCenterCoordsX, sizeof(result.fCenterCoordsX));
		memcpy(CenterCoordsY, &result.fCenterCoordsY, sizeof(result.fCenterCoordsY));
		memcpy(angles, &result.fangles, sizeof(result.fangles));
		memcpy(tempScales, &result.ftempScales, sizeof(result.ftempScales));
		*outNumber = result.ioutNumber;
		outResult = 1;
	}
	else if (proxy.error)
	{
		proxy.soap_stream_fault(std::cerr);
		proxy.destroy();
		outResult = 0;
	}
}

void getAffine(const char* endpoint, const char* AffinePath, int& outResult){
	serviceProxy proxy;
	proxy.soap_endpoint = endpoint;
	SOAP_ENC__base64 _inPutFile;

	fstream AffineFile;
	AffineFile.open(AffinePath, std::ios::in | ios::binary);
	AffineFile.seekg(0, std::ios_base::end);
	int AffineFileSize = AffineFile.tellg();
	AffineFile.seekg(0, std::ios_base::beg);
	_inPutFile.__size = AffineFileSize;
	_inPutFile.__ptr = new UCHAR[AffineFileSize];
	AffineFile.read((char*)_inPutFile.__ptr, AffineFileSize);
	AffineFile.close();
	int i = 0;
	outResult = 0;
	if (proxy.getCCalibrationXYZFile(_inPutFile,i)==SOAP_OK)
	{
		proxy.destroy();
		if (i == 10086)
		{
			cout << "successful" << endl;
			outResult = 1;
		}
		else if (i == 10010){
			cout << "upLoad Failed" << endl;			
		}
		else{
			cout << "Connect Failed" << endl;
		}
	}
	else if (proxy.error)
	{
		proxy.soap_stream_fault(std::cerr);
		proxy.destroy();
	}
	delete[] _inPutFile.__ptr;
	return;
}

void CCalibrationXYZNew(const char* endpoint, float* srcTriX, float* srcTriY, int number, float* CalibrationX, float* calibrationY,int& outResult){
	serviceProxy proxy;
	proxy.soap_endpoint = endpoint;
	ns__CCalibrationXYZNewPARA _inPutPara;
	ns__CCalibrationXYZNewOUT _outPara;

	_inPutPara.number = number;
	for (int i = 0; i < number;++i)
	{
		_inPutPara.srcTriX[i] = srcTriX[i];
		_inPutPara.srcTriY[i] = srcTriY[i];
	}
	outResult = 0;
	if (proxy.CCalibrationXYZNewService(_inPutPara,_outPara)==SOAP_OK)
	{
		proxy.destroy();
		memcpy(CalibrationX, _outPara.CalibrationX, sizeof(_outPara.CalibrationX));
		memcpy(calibrationY, _outPara.CalibrationY, sizeof(_outPara.CalibrationY));
		outResult = 1;
	}
	else if (proxy.error){
		proxy.soap_stream_fault(std::cerr);
		proxy.destroy();
	}
	return ;
}


//int main(){
//	int i = 0;
//	//getFile(i);
//	float costs[20];
//	float CenterCoordsX[20];
//	float CenterCoordsY[20];
//	float angles[20];
//	float tempScales[20];
//	int outNumber = 0;
//	int result = 0;
//
//	Mat img = imread("../Debug/skew1.bmp", CV_8UC1);
//	uchar *data = img.data;
//
//
//	TempleMatch(data,img.cols,img.rows,costs,CenterCoordsX,CenterCoordsY,angles,tempScales,&outNumber,result);
//	system("pause");
//	return 0;
//}

