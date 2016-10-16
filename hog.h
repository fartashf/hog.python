#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>

static inline float min(float x, float y);
static inline float max(float x, float y);

static inline int min(int x, int y);
static inline int max(int x, int y);
float *computeHOG(double *im, int *dims, int *rdims, int sbin=8);

double* cv2c(const cv::Mat &img);
cv::Mat c2cv(const float *input, int *dims);
