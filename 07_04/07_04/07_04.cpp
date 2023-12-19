#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 全局变量用于保存图像和参数
Mat image;
int brightness = 50; // 初始亮度值
int contrast = 50;   // 初始对比度值

// 回调函数，根据滑动条值调整图像亮度和对比度
void onTrackbar(int, void*) {
    // 调整图像的亮度和对比度
    Mat newImage = Mat::zeros(image.size(), image.type());
    image.convertTo(newImage, -1, contrast / 50.0, brightness - 50);

    // 显示调整后的图像
    imshow("Adjusted Image", newImage);
}

int main() {
    // 读取图像
    string imagePath = "D:/text_for_c++/封面.jpg";
    image = imread(imagePath);
    if (image.empty()) {
        cout << "无法加载图像！" << endl;
        return -1;
    }

    //// 创建窗口并显示原始图像
    //namedWindow("Original Image", WINDOW_NORMAL);
    //imshow("Original Image", image);

    // 创建调整后的图像显示窗口
    namedWindow("Adjusted Image", WINDOW_NORMAL);
    imshow("Adjusted Image", image);

    // 创建亮度和对比度的滑动条
    createTrackbar("亮度", "Adjusted Image", &brightness, 100, onTrackbar);
    createTrackbar("对比度", "Adjusted Image", &contrast, 100, onTrackbar);

    // 调用一次回调函数，显示初始图像
    onTrackbar(0, 0);

    // 等待键盘输入
    waitKey(0);
    destroyAllWindows();

    return 0;
}
