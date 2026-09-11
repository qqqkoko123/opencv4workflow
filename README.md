# 编译环境
Qt5.14.2 + Visual Studio 2022，C++语言标准 C++ 14 （旧版）
请将项目下载至英文目录，防止出现打不开源文件的报错

# 新增YoloV13
下载ONNX Runtime v1.22，将lib放至.\QPlugins\YoloV13\YoloV13目录下，并将lib目录里的所有文件放至.\QSoftExe\Debug或者\QSoftExe\Release下

# 新增OCR识别
下载ONNX Runtime v1.22，将lib放至.\QPlugins\OCR\OCR\onnxruntime目录下，并将lib目录里的所有文件放至.\QSoftExe\Debug或者\QSoftExe\Release下

# 新增车牌识别
基于 ONNX Runtime 的车牌检测与识别（CPU），模型放至.\QSoftExe\Release\models\plate 或.\QSoftExe\Debug\models\plate

# 新增海康工业摄像头
对接海康工业摄像头MVS4.5.1.2，请从海康开放平台下载对应sdk

# 新增对接汇川PLC
下载并编译libmodbus库3.1.11，将lib文件引入到项目中，将dll文件放至debug/release下

# 新增Data Matrix二维码扫描
将libdmtx.dll放至debug/release下

# 新增二维码生成
将qrencoded.dll放至debug下，将qrencode.dll放至release下

# 新增自动打印
自动打印输出到连接Windows的打印机
# 新增USB摄像头
新增USB摄像头以及遮挡摄像头和拍照行为检测

### 示例图片

# 海康摄像头
[![海康摄像头](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E6%B5%B7%E5%BA%B7%E6%91%84%E5%83%8F%E5%A4%B4.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E6%B5%B7%E5%BA%B7%E6%91%84%E5%83%8F%E5%A4%B4.png)
# 汇川PLC读写
[![汇川PLC读写](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E6%B1%87%E5%B7%9DPLC%E8%AF%BB%E5%86%99.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E6%B1%87%E5%B7%9DPLC%E8%AF%BB%E5%86%99.png)
# OCR
[![OCR](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/OCR.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/OCR.png)
# YOLOV13
[![YOLOV13](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/YOLOV13.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/YOLOV13.png)
# 车牌识别
[![车牌识别](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E8%BD%A6%E7%89%8C%E8%AF%86%E5%88%AB.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E8%BD%A6%E7%89%8C%E8%AF%86%E5%88%AB.png)
# 二维码（DataMatrix、QRCode）生成
[![二维码（DataMatrix、QRCode）生成](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E4%BA%8C%E7%BB%B4%E7%A0%81%EF%BC%88DataMatrix%E3%80%81QRCode%EF%BC%89%E7%94%9F%E6%88%90.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E4%BA%8C%E7%BB%B4%E7%A0%81%EF%BC%88DataMatrix%E3%80%81QRCode%EF%BC%89%E7%94%9F%E6%88%90.png)
# 米粒计数和检测
[![米粒计数和检测](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E7%B1%B3%E7%B2%92%E8%AE%A1%E6%95%B0%E5%92%8C%E6%A3%80%E6%B5%8B.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E7%B1%B3%E7%B2%92%E8%AE%A1%E6%95%B0%E5%92%8C%E6%A3%80%E6%B5%8B.png)
# 距离测量
[![距离测量](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E8%B7%9D%E7%A6%BB%E6%B5%8B%E9%87%8F.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E8%B7%9D%E7%A6%BB%E6%B5%8B%E9%87%8F.png)
# 自动打印
[![自动打印](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E8%87%AA%E5%8A%A8%E6%89%93%E5%8D%B0.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E8%87%AA%E5%8A%A8%E6%89%93%E5%8D%B0.png)
# 长度测量
[![长度测量](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E9%95%BF%E5%BA%A6%E6%B5%8B%E9%87%8F.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E9%95%BF%E5%BA%A6%E6%B5%8B%E9%87%8F.png)
# 软件著作权
[![软件著作权](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E8%BD%AF%E8%91%97.png)](https://github.com/qqqkoko123/opencv4workflow/blob/master/Images/%E8%BD%AF%E8%91%97.png)

# 觉得好，请打赏我~

![支付宝打赏](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E8%A7%89%E5%BE%97%E5%A5%BD%E8%AF%B7%E6%89%93%E8%B5%8F%E6%88%91alipay.jpg)     ![微信打赏](https://raw.githubusercontent.com/qqqkoko123/opencv4workflow/master/Images/%E8%A7%89%E5%BE%97%E5%A5%BD%E8%AF%B7%E6%89%93%E8%B5%8F%E6%88%91wechat_reward.jpg)
