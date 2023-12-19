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

    // 检测图像边缘
    Mat edges;
    Canny(image, edges, 100, 200);

    // 进行膨胀操作
    Mat dilated;
    dilate(edges, dilated, Mat(), Point(-1, -1), 2);

    // 进行侵蚀操作
    Mat eroded;
    erode(dilated, eroded, Mat(), Point(-1, -1), 2);

    // 改变图像大小，缩放为50%
    Mat resized;
    resize(eroded, resized, Size(), 0.5, 0.5);

    // 显示原始图像和处理后的图像
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("Processed Image", WINDOW_NORMAL);
    imshow("Original Image", image);
    imshow("Processed Image", resized);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
