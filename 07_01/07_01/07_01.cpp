#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // 加载并显示图像
    Mat image = imread("D:/text_for_c++/封面.jpg");
    if (image.empty()) {
        cout << "无法加载图像！" << endl;
        return -1;
    }
    imshow("Image", image);
    while (true) {
        int key = waitKey(0);
        if (key == 27) { // 按下 Esc 键 (ASCII码为27)
            break;
        }
    }
    destroyWindow("Image");

    // 加载视频并播放
    VideoCapture video("D:/text_for_c++/test.mp4");
    if (!video.isOpened()) {
        cout << "无法打开视频！" << endl;
        return -1;
    }
    while (true) {
        Mat frame;
        video >> frame;     //读取video一帧数据存到frame中
        double FrameRate = video.get(CAP_PROP_FPS);
        cout << "视频帧率为：" << FrameRate << endl;

        if (frame.empty()) {
            break;
        }
        imshow("Video", frame);
        int key = waitKey(1000 / FrameRate); // 帧间隔时间，单位为毫秒
        if (key == 27) {
            break;
        }
    }
    video.release();
    destroyWindow("Video");

    // 捕获实时视频
    VideoCapture camera(0); // 0 表示默认摄像头
    if (!camera.isOpened()) {
        cout << "无法打开摄像头！" << endl;
        return -1;
    }
    while (true) {
        Mat frame;
        camera >> frame;
        if (frame.empty()) {
            break;
        }
        imshow("Camera", frame);
        int key = waitKey(30);
        if (key == 27) {
            break;
        }
    }
    camera.release();
    destroyWindow("Camera");

    return 0;
}
