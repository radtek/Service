
#ifdef  EXPORTDLL
#define CLIENTDLL __declspec(dllexport)
#else
#define CLIENTDLL __declspec(dllimport)
#endif

CLIENTDLL void sendFile(const char* endpoint, int& outResult);
CLIENTDLL void TempleMatch(const char* endpoint, unsigned char* imggray, int widthImg, int heightImg, float* costs, float* CenterCoordsX, float* CenterCoordsY, float* angles, float* tempScales, int* outNumber, int& outResult);
CLIENTDLL void sendAffineFile(const char* endpoint, const char* AffinePath, int& outResult);
CLIENTDLL void CCalibrationXYZNew(const char* endpoint, float* srcTriX, float* srcTriY, int number, float* CalibrationX, float* calibrationY, int& outResult);