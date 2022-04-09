__ ____ ____ __ _    ____ ____  __  _  _ ____ _  _  __ ____ __ _                                                                                   
 /  (  _ (  __(  ( \  (  __(  _ \/ _\( \/ (  __/ )( \/  (  _ (  / )                                                                                  
(  O ) __/) _)/    /   ) _) )   /    / \/ \) _)\ /\ (  O )   /)  (                                                                                   
 \__(__) (____\_)__)  (__) (__\_\_/\_\_)(_(____(_/\_)\__(__\_(__\_)                                                                                  
 ____ __ ____     ___ __  _  _ ____ __ __ _ ____ ____    ____ ____ ____ ____ ____ ____ ____ __  __  __ _    ____ ____ ____ ____ ___ ____ __ __  __ _ 
(  __/  (  _ \   / __/  \( \/ (  _ (  (  ( (  __(    \  (  _ (  __(    (  __/ ___(_  _(  _ (  )/ _\(  ( \  (    (  __(_  _(  __/ __(_  _(  /  \(  ( \
 ) _(  O )   /  ( (_(  O / \/ \) _ ()(/    /) _) ) D (   ) __/) _) ) D () _)\___ \ )(  )   /)(/    /    /   ) D () _)  )(  ) _( (__  )(  )(  O /    /
(__) \__(__\_)   \___\__/\_)(_(____(__\_)__(____(____/  (__) (____(____(____(____/(__)(__\_(__\_/\_\_)__)  (____(____)(__)(____\___)(__)(__\__/\_)__)

What is this ?
==============

This is the 2th release of the Open Framework for Combined pedestrian detection. This repository is a refactored version of the code used for 

 * 	Open Framework for combined pedestrian detection
	F. De Smedt and T. Goedemé, VISAPP 2015, Berlin, Germany

 *	On-board real-time tracking of pedestrians on a UAV
	F. De Smedt, D. Hulens and T. Goedemé, EVW 2015, Boston, USA

This work is an extention of 

 * 	The Combinator: optimal combination of multiple pedestrian detectors
	F. De Smedt*, K. Van Beeck*, T. Tuytelaars and T. Goedemé, ICPR 2014, Stockholm

An other version of the DPM detector from the same codebase was also used in
 *	Pedestrian Detection at Warp Speed: Exceeding 500 Detections per Second
	F. De Smedt*, K. Van Beeck*, T. Tuytelaars and T. Goedemé, EVW workhop (CVPR) 2013, Portland
 *	Is the game worth the candle? Evaluation of OpenCL for object detection algotithm optimization
	F. De Smedt, L. Struyf, S. Beckers, J. Vennekens, G. De Samblanx and T. Goedemé, PECCS 2012, Rome
 *	Faster and more intelligent object detection by combining OpenCL and KR
	F. De Smedt, L. Struyf, S. Beckers, J. Vennekens, G. De Samblanx and T. Goedemé, Journal of Ambient Intelligence and Humanized Computing, 2014
	 
The main authors of this work are

* [Floris De Smedt]

and the code is owned by the EAVISE research group (http://www.eavise.be).

The detections code is based on existing matlab (with partly mex-files) implementations of the papers
 * 	Discriminatively trained deformable part models, release 4.0
	P. Felzenszwalb, R. Girshick and D. McAllester, CVPR 2010

 * 	Integral Channel Features
	P. Dollar, Z. Tu, P. Perona and S. Belongie, BMCV 2009

 *      Fast feature pyramids for object detection
        P. Dollar, R. Appel, S. Belongie and P. Perona, PAMI 2014


the code is released with a _research only_ license (see license.text),  
the license is _not_ [OSI compatible](http://opensource.org/docs/osd) (due, at least, to term 6 since we do discriminate against "fields of endeavor").

Changes from V1 to V2
=====================
 * Added new detectors
	* OpenCV HOG
	* ACF
 * New DPM-version
	Experiments have chown the presence of a bug in the first version (currently available as DPMOld) which shows slows down the processing when big black regions are present (to high gradients?). This new version does not have this problem but does not contain the same parallellisation capabilities yet, so average speed will be lower on multi-core CPUs.


Quickstart
==========

Retrieve the code
-----------------

$ mkdir TargetDir
$ cd TargetDir
$ git clone https://bitbucket.org/fdesmedt/openframework/
$ cd openframework

Install:
-------
Compile the code: 
$ make -j4

NOTE: Due to a bug in the channel code of the Dollar ACF Matlab SSE-implementations (of which our channel code is based), 
different compiler versions lead to different feature values. We tested with g++4.6 USE THIS VERSION FOR OPTIMAL RESULTS! 

Running the code:
----------------
$ ./CombinationFramework Directory2Process

This runs the code, shows the detections and writes them to a file ("Output.txt") in XML-format

Broader overview
================

Filestructure:
 * CombinationFramework.cpp: the code for the default application
 * src: all remaining source-files
 * Models: Possible models to use with the detectors

Important files:
 * CombinationFramework.cpp: Steers the complete application:
	* Where to take frames from?
	* Wich file to write the results to?
	* Show the detections?
 * DetectorManager.cpp: the constructor handles the detector to be used. As commented in this function, the detector can easely be changed (requires recompilation)
 * dpmdetector.cpp: changing upscale factor, combination-parameters (normalisation, and confidence) model-file and detection threshold for the DPM-detector
 * chnftrsdetector.cpp: changing upscale factor, combination-parameters (normalisation, and confidence) model-file and detection threshold for the ICF-detector

Todo
=====
The detection code is still a work in progress. The current code is very alike the detection code used for the papers, and obtains the same accuracy-results. 
This still leaves some things to do:
 * Documenting all the functions
 * Extending the Combination-capability to all detectors (work for the weeks/month to come)
 * Add configuration options from file and command-line
	* Version based on boost available in private versions, not yet integrated here
 * Encapsulate free functions into the corresponding classes
 * Add the combination rules for more as 2 detectors.
 * Add wrappers for detectors which where not written inside the research group (interfaces for FFLD, Doppia,...) 
 * Add training code, or scripts to convert Matlab-trained models into useable format

How to cite:
============

When using this framework, of part of this framework, please cite the following papers:
 *  Open Framework for combined pedestrian detection
    F. De Smedt and T. Goedemé, VISAPP 2015, Berlin

When using the ACF implementation, make an additional citation to 

 * On-board real-time tracking of pedestrians on a UAV
   F. De Smedt, D. Hulens and T. Goedemé, EVW 2015, Boston, USA