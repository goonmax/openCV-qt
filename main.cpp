#include "mainwindow.h"
#include <QApplication>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Mat img;
    VideoCapture cam(0);
    namedWindow("CameraObjectTrace");


    while(1){
        cam >> img;
        imshow("CameraObjectTrace", img);


        if(waitKey(1) == 27)
            break;
    }

    return a.exec();
}
