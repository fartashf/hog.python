hog.python
==========

A python wrapper for HOG implemented in 
[`voc-release5`](https://github.com/rbgirshick/voc-dpm/blob/master/features/features.cc).

#### Installation
* OpenCV
* PythonLibs
* Lib Boost Python

```Bash
mkdir build
cd build
cmake ..
make
cp libhog.so hog.so
```

#### Usage
```python
import hog
img = io.imread('image.jpg')
feat = hogw.ProcessImage(img)
```
