#include "mainwindow.h"
#include <QApplication>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/tracking.hpp>
#include "opencv2/objdetect.hpp"




using namespace std;
using namespace cv;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Mat img;




    return a.exec();
}



void facedetection()
{
   
}
