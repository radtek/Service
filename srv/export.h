

//#define DllExport _declspec(dllexport)


//����Ŀ��:ģ��ƥ��
//���룺xmlName��XML·��(�ļ�·�����ļ�������Ҫ������д���ˣ�Ϊ��matchTemPlate.xml��)��imggray�������Ҷ�ͼ��widthImg��ͼ���ȣ� heightImg��ͼ��߶�
//�����costs��������CenterCoordsX����������X��CenterCoordsY����������Y��angles����ת�Ƕȣ�tempScales�����ųߴ磻outNumber��Ŀ����Ŀ
void  TempleMatch(char* xmlName, unsigned char* imggray, int widthImg, int heightImg, float* costs, float* CenterCoordsX, float* CenterCoordsY, float* angles, float* tempScales, int *outNumber);

//����Ŀ��:��������
//���룺Path:�������·�����ļ�·��+�ļ�������srcTriX��ͼ������X��srcTriY��ͼ������Y��number��Ŀ�����
//�����CalibrationX��ʵ������X;CalibrationY��ʵ������Y
void  CCalibrationXYZNew(char* Path, float*srcTriX, float*srcTriY, int number, float*CalibrationX, float*CalibrationY);

//�������̣�ReadconfgXml,ReadPic��ReadAffineMatXml��ʼ��ģ��ͷ���任��Ϣ�󣬿�һֱѭ������ChamerMatching��CCalibrationXYZ������ʵ������


