

//#define DllExport _declspec(dllexport)


//函数目的:模板匹配
//输入：xmlName：XML路径(文件路径（文件名不需要，里面写死了，为：matchTemPlate.xml）)；imggray：被检测灰度图；widthImg：图像宽度； heightImg：图象高度
//输出：costs：分数；CenterCoordsX：中心坐标X；CenterCoordsY：中心坐标Y；angles：旋转角度；tempScales：缩放尺寸；outNumber：目标数目
void  TempleMatch(char* xmlName, unsigned char* imggray, int widthImg, int heightImg, float* costs, float* CenterCoordsX, float* CenterCoordsY, float* angles, float* tempScales, int *outNumber);

//函数目的:计算坐标
//输入：Path:仿射矩阵路径（文件路径+文件名）；srcTriX：图像坐标X；srcTriY：图像坐标Y；number：目标个数
//输出：CalibrationX：实际坐标X;CalibrationY：实际坐标Y
void  CCalibrationXYZNew(char* Path, float*srcTriX, float*srcTriY, int number, float*CalibrationX, float*CalibrationY);

//总体流程：ReadconfgXml,ReadPic和ReadAffineMatXml初始化模板和仿射变换信息后，可一直循环调用ChamerMatching和CCalibrationXYZ来计算实际坐标


