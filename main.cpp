#include "mainwindow.h"
#include <QApplication>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/tracking.hpp>
#include "opencv2/objdetect.hpp"




using namespace std;
using namespace cv;



static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';'){
    std::ifstream file(filename.c_str(), ifstream::in);
    if(!file){
        string error = "no input file make no work did a  bad bad !!!";
    }

    string line, path, classlabel;
    while(getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}


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
