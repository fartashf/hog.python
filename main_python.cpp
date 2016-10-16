#include <time.h>
#include <iostream>
#include <stdio.h>
#include "Python.h"
#include <stdio.h>
#include "NPtoCV.h"
#include "hog.h"
#include "boost/python.hpp"
#include <string.h>
using namespace boost::python;

class HOGWrapper
{
private:
	cv::Mat ProcessImageInternal(cv::Mat img);

public:
	// .ctor
    HOGWrapper();

	// .dtor
    virtual ~HOGWrapper();

	// function to compute features
	PyObject* ProcessImage(PyObject* image); 
};

HOGWrapper::HOGWrapper()
{
	import_array(); // This is a function from NumPy that MUST be called.
}
HOGWrapper::~HOGWrapper()
{
}
cv::Mat HOGWrapper::ProcessImageInternal(cv::Mat img)
{
	if(img.type()!=CV_8UC3){
		fprintf(stderr, "Bad data type");
		return cv::Mat();
	}
    // size = (height, width)
	int idims[3]={img.size[0], img.size[1], img.channels()};
	int odims[3]={};
	double * cimg = cv2c(img);
	float * cret = computeHOG(cimg, idims, odims);
	cv::Mat ret = c2cv(cret, odims);
	delete[] cimg;
	delete[] cret;
	return ret;
}

// The conversions functions above are taken from OpenCV. The following function is 
// what we define to access the C++ code we are interested in.
PyObject* HOGWrapper::ProcessImage(PyObject* image)
{
	cv::Mat cvImage;
    pyopencv_to(image, cvImage); // From OpenCV's source
	cv::Mat cvRet = ProcessImageInternal(cvImage);
	PyObject* result = pyopencv_from(cvRet);
	
	return result;
}

BOOST_PYTHON_MODULE(hog)
{
    class_<HOGWrapper>("HOGWrapper", init<>())
      .def(init<>())
      .def("ProcessImage", &HOGWrapper::ProcessImage)
    ;
}
