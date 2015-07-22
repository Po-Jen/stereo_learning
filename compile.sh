g++ draw_point.cpp -o draw_point -lGL -lGLU -lglut
 g++ src/opencv_disparity.cpp -o src/opencv_disparity `pkg-config opencv --libs --cflags opencv`;
