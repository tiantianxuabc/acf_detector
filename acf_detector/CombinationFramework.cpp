//============================================================================
// Name        : CombinationFramework.cpp
// Author      : F. De Smedt @ EAVISE
// Version     :
// Copyright   : This code is written for the publication of  "Open Framework for Combined Pedestrian detection". This code is for research and educational purposes only. For a different license, please contact the contributors directly. More information about the license can be fount in license.txt
// Description : Source for the default application
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <iomanip>

// for input possibilities
#include "FrameFromDirectory.h"
#include "FrameFromCamera.h"
#include "FrameFromVideo.h"

// detection includes
//#include "src/detection.h"
#include "DetectionList.h"
#include "NonMaximumSuppression.h"

#include "DetectorManager.h"

#include "FileWriter.h"

#include "DPMPyramid.h"
//#include "CModel.h"
#include "DPMFunctions.h"

//HOG
#include "opencv2/objdetect/objdetect.hpp"

// namespaces
using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	FrameProducer * FP = new FrameFromDirectory(argv[1]);

	FileWriter *FW;
	DetectorManager DM;

	NonMaximumSuppression NMS;

	FW = new FileWriter("Output.txt");

	while(!FP->isend()){

		// retrieve frame
		cv::Mat Frame = FP->giveFrame();
		
		//Apply detector
		DetectionList DL = DM.applyDetector(Frame);

		//NMS
		DetectionList NMax = NMS.dollarNMS(DL);
		
		// Show scores
		NMax.PrintList();

		//Write detections to file
                NMax.WriteDetections(FW,FP->getFilename());

		// Draw the detections and show them
		NMax.Draw(Frame);
		cv::imshow("Frame", Frame);
		cv::waitKey(5);

	}


	delete FP;
	return EXIT_SUCCESS;
}
