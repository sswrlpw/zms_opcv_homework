#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 图像路径
    string imagePath = "D:/text_for_c++/封面.jpg";

    // 加载图像
    Mat image = imread(imagePath);
    if (image.empty()) {
        cout << "无法加载图像！" << endl;
        return -1;
    }

    // 将图像转换为灰度图
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    cout << "gray" << endl;

    // 二值化灰度图像
    Mat binaryImage;
    threshold(grayImage, binaryImage, 127, 255, THRESH_BINARY);
    cout << "binary" << endl;

    // 高斯模糊处理
    Mat blurredImage;
    GaussianBlur(grayImage, blurredImage, Size(5, 5), 0);
    cout << "blurred" << endl;

    // 显示原始图像和处理后的图像
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("Processed Image", WINDOW_NORMAL);
    imshow("Original Image", image);
    imshow("Processed Image", blurredImage);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
