CC = g++
#CC = g++
FLAGS = -O3 -fopenmp -I src -I src/DPMOld -I src/Core -I src/Combinator -I src/ACF -I src/ICF -I src/Channel -I src/DPM -I src/HOG -I src/Tracking -I src/dlib-18.16
LINK = `pkg-config --libs opencv`  -L /usr/local/cuda-5.5/lib64 

#EXTERNOBJECTS = /home/dhu/src/lcm-read-only/lcm/.libs/*.o /usr/lib/x86_64-linux-gnu/libglib-2.0.a /usr/lib/x86_64-linux-gnu/libpcre.a /home/dhu/mavconn_mavlink_message_t.o /home/dhu/mavconn_mavlink_msg_container_t.o

CHANNELCODE =  channelOld.o LoadChannels.o LoadChannels2.o 
ICF = chnftrsfeaturelayer.o chnftrsdetector.o chnftrsmodel.o
DPMOLD = dpmdetectorOld.o NewCascadeModelOld.o CascadeModelOld.o ConvertToNewModelOld.o cascadeOld.o featpyramidOld.o featuresOld.o cascade_detectOld.o projectpyramideOld.o projectOld.o fconvOld.o matrixmultOld.o padarrayOld.o
ACF = ACFFeaturePyramid.o ChannelFeatures.o ColorChannel.o GradMagChannel.o  GradHistChannel.o ACFDetector.o Channel.o convConst.o Convert.o gradientMex.o wrappers.o
Combinator = HasOverlap.o Combinator.o
DPM = DPMPyramid.o DPMFeatures.o features.o padarray.o LoadCascadeModel.o cascade_detect.o DPMPcaFeatures.o DPMPCAPyramid.o project.o matrixmult.o fconv.o cascade.o model.o clipboxes.o bboxpred_get.o bboxpred_input.o dpmdetector.o
HOG = HOGDetector.o
Core = FileWriter.o detectormodel.o feature.o featurelayer.o  FrameProducer.o FrameFromDirectory.o filelocator.o FrameFromCamera.o FrameFromVideo.o detection.o DetectionList.o NonMaximumSuppression.o nms.o DetectorManager.o detector.o  ScaleSpacePyramid.o 



Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(SQRTICF) $(Combinator) CombinationFramework.o 
#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(SQRTICF) $(Combinator) WithTracking.o 
#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(SQRTICF) $(Combinator) GroundPlane.o 
#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(Combinator) CombinationFramework_Parallel.o 
#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(SQRTICF) $(Combinator) Evaluate.o 

TARGET = CombinationFramework
#TARGET = WithTracking 
#TARGET = GroundPlane 

#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(SQRTICF) $(Combinator) CombinationFramework.o 
#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(Combinator) CombinationFramework_Parallel.o 
#Objects = $(DPM) $(Core) $(DPMOLD) $(ICF) $(ACF) $(HOG) $(CHANNELCODE) $(SQRTICF) $(Combinator) Evaluate.o 

#TARGET = CombinationFramework
#TARGET = CombinationFramework_Parallel
#TARGET = Evaluate

all: $(TARGET)

$(TARGET): $(Objects)
	$(CC) $(Objects) $(LINK) $(SEARCH) $(EXTERNOBJECTS) $(FLAGS) -o $(TARGET)


Evaluate.o: Evaluate.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

CombinationFramework_Parallel.o: CombinationFramework_Parallel.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<


CombinationFramework.o: CombinationFramework.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<


WithTracking.o: WithTracking.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<
	



GroundPlane.o: GroundPlane.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<


%.o:  src/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

%.o:  src/Channel/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

%.o:  src/DPM/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

%.o:  src/DPMOld/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

%.o:  src/ICF/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

%.o:  src/Combinator/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

%.o:  src/Core/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<


%.o:  src/hungarian/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<


%.o:  src/HOG/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<


%.o:  src/ACF/%.cpp
	$(CC) -c $(FLAGS) $(SEARCH) $<

clean:
	rm -f *.o $(TARGET)
	
