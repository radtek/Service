#include "soapserviceService.h"
#include "service.nsmap"
#include "fstream"
#include "iostream"
#include "export.h"
#include "time.h"
using namespace std;
int main(){
	serviceService service;
	return service.run(8089);
}

static bool WriteFile(BYTE* _ptr,int _size,const char* _filePath){
	fstream tempFile;
	tempFile.open(_filePath, ios::out | ios::out | ios::binary | ios::trunc);
	if (!tempFile.is_open())
	{
		tempFile.close();
		return false;
	}
	tempFile.write((char*)_ptr, _size);
	tempFile.close();
	return true;
}

int serviceService::getFileService(struct ns__TempleFiles in, int &result){
	if (WriteFile(in.image.__ptr, in.image.__size, "./ReceiveFile/0.bmp")&&
		WriteFile(in.image2.__ptr, in.image2.__size, "./ReceiveFile/1.bmp") &&
		WriteFile(in.image3.__ptr, in.image3.__size, "./ReceiveFile/2.bmp") &&
		WriteFile(in.matchTemPlate.__ptr, in.matchTemPlate.__size, "./ReceiveFile/matchTemPlate.xml") &&
		WriteFile(in.tplgray.__ptr, in.tplgray.__size, "./ReceiveFile/tplgray.jpg"))
	{
		result = 10086;
	}
	else result = 10010;
	return SOAP_OK;
}

int serviceService::TempleMatchService(struct ns__TempleMatchPARA inPara, struct ns__TempleMatchOUT &outPara){
	float costs[20];
	float CenterCoordsX[20];
	float CenterCoordsY[20];
	float angles[20];
	float tempScales[20];
	int outNumber = 0;
	time_t start = clock();

	TempleMatch("./ReceiveFile",
		inPara.imggray.__ptr,
		inPara.widthImg,
		inPara.heightImg,
		costs,
		CenterCoordsX,
		CenterCoordsY,
		angles,
		tempScales,
		&outNumber);
	time_t end = clock();

	for (int i = 0; i < outNumber;++i)
	{
		outPara.fcosts[i] = costs[i];
		outPara.fCenterCoordsX[i] = CenterCoordsX[i];
		outPara.fCenterCoordsY[i] = CenterCoordsY[i];
		outPara.fangles[i] = angles[i];
		outPara.ftempScales[i] = tempScales[i];		
	}
	outPara.ioutNumber = outNumber;

	std::cout << end - start << std::endl;
	return SOAP_OK;
}


int serviceService::getCCalibrationXYZFile(struct SOAP_ENC__base64 inFile, int &result){
	if (WriteFile(inFile.__ptr, inFile.__size, "./ReceiveFile/Affine.xml")){
		result = 10086;
	}
	else{
		result = 10010;
		std::cout << "write file failed!" << std::endl;
	}
		return SOAP_OK;	
}

int serviceService::CCalibrationXYZNewService(struct ns__CCalibrationXYZNewPARA inPara, struct ns__CCalibrationXYZNewOUT &outPara){
	try{
		CCalibrationXYZNew("./ReceiveFile/Affine.xml", inPara.srcTriX, inPara.srcTriY, inPara.number, outPara.CalibrationX, outPara.CalibrationY);
		return SOAP_OK;
	}
	catch(...) {
		return SOAP_FAULT;
	}
}