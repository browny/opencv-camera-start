
#include "capture.h"
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

	// --- read frome file --- //
	//Capture capture("test.wmv", windowSize, windowSize);

	// --- read from camera --- //
	CvSize windowSize = cvSize(640, 480);
	Capture capture(2, windowSize, windowSize);

	while (1) {

		capture.captureNext();

		for (int i = 0; i < capture.channelNum; ++i) {

			ostringstream oss;
			oss << i;
			string winName = "WINDOW-" + (oss.str());

			cvShowImage(winName.c_str(), capture.channelImgList[i]);

		}

		int c = cvWaitKey(30);
		if ( (char) c == 27 ) { // 'Esc' to terminate

			break;
		}

	}

	return 0;

}

