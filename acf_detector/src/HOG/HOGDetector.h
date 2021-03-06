#ifndef _H_HOGDETECTOR
#define _H_HOGDETECTOR

#include <vector>
#include <string>
#include <iostream>

#include "detection.h"

#include "DetectionList.h"
#include "detector.h"

class HOGDetector: public Detector {
public:
    HOGDetector();
    std::string getName() const {
        return "HOG";
    }

    DetectionList applyDetector(const cv::Mat &Frame) const;
private:
    cv::HOGDescriptor hog;


};


#endif
