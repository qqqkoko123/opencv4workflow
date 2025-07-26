# 编译环境
Qt5.14.2 + Visual Studio 2022，C++语言标准 C++ 14 （旧版）
请将项目下载至英文目录，防止出现打不开源文件的报错

# 新增YoloV13
下载ONNX Runtime v1.22，将lib放至.\QPlugins\YoloV13\YoloV13目录下，并将lib目录里的所有文件放至.\QSoftExe\Debug或者\QSoftExe\Release下

# 新增OCR识别
下载ONNX Runtime v1.22，将lib放至.\QPlugins\OCR\OCR\onnxruntime目录下，并将lib目录里的所有文件放至.\QSoftExe\Debug或者\QSoftExe\Release下

# 新增海康工业摄像头
对接海康工业摄像头MVS4.5.1.2，请从海康开放平台下载对应sdk

# 新增对接汇川PLC
下载并编译libmodbus库3.1.11，将lib文件引入到项目中，将dll文件放至debug/release下
