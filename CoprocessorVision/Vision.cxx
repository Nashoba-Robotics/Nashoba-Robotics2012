#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>

#define BUFFERSIZE		1024

#define GUI                      // Normal case
//#define PROCESS_CAM            // Normal case
//#define CRIO_NETWORK           // Normal case

//#define GUIALL                 // For debugging
#define WPI_IMAGES               // For debugging with WPI images

using namespace cv;
using namespace std;

#define BLUE_PLANE 0
#define GREEN_PLANE 1
#define RED_PLANE 2

Mat src;
int thresh = 40;                   // Defines the threshold level to apply to image
int max_thresh = 255;              // Max threshold for the trackbar
int poly_epsilon = 10;             // Epsilon to determine reduce number of poly sides
int max_poly_epsilon = 50;         // Max epsilon for the trackbar

int minsize = 500;                 // Polygons below this size are rejected
int max_minsize = 10000;           // Max polygon size for the trackbar

int dilation_elem = 0;             // The element type dilate/erode with
int const max_elem = 2;            // Max trackbar element type
int dilation_size = 4;             // The size of the element to dilate/erode with
int const max_kernel_size = 21;    // Max trackbar kernel dialation size

int erode_count = 1;               // The number of times to erode the image
int erode_max = 20;                // Max number of times to erode on trackbar

int target_width_inches = 24;      // Width of a physical target in inches
int target_height_inches = 16;     // Height of a physical target in inches

 /// Function header
void processImageCallback(int, void* );

// This function is used to calculate and display histogram of an image
void calcHistogram(Mat &src) {
/// Separate the image in 3 places ( R, G and B )
 vector<Mat> rgb_planes;
 split( src, rgb_planes );

 /// Establish the number of bins
 int histSize = 255;

 /// Set the ranges ( for R,G,B) )
 float range[] = { 0, 255 } ;
 const float* histRange = { range };

 bool uniform = true; bool accumulate = false;

 Mat r_hist, g_hist, b_hist;

 /// Compute the histograms:
 calcHist( &rgb_planes[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
 calcHist( &rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
 calcHist( &rgb_planes[2], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );

 // Draw the histograms for R, G and B
 int hist_w = 400; int hist_h = 400;
 int bin_w = cvRound( (double) hist_w/histSize );

 Mat histImage( hist_w, hist_h, CV_8UC3, Scalar( 0,0,0) );

 /// Normalize the result to [ 0, histImage.rows ]
 normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
 normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
 normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

 /// Draw for each channel
 for( int i = 1; i < histSize; i++ )
   {
     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                      Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                      Scalar( 255, 0, 0), 2, 8, 0  );
     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                      Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                      Scalar( 0, 255, 0), 2, 8, 0  );
     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                      Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                      Scalar( 0, 0, 255), 2, 8, 0  );
    }

 /// Display
 namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
 imshow("calcHist Demo", histImage );
}


void createGuiWindows() {
  /// Create Window
#ifdef GUIALL
  namedWindow( "Source", CV_WINDOW_AUTOSIZE );
  namedWindow("Color", CV_WINDOW_AUTOSIZE );
  namedWindow("Dilate", CV_WINDOW_AUTOSIZE );
  namedWindow("Threshold Raw", CV_WINDOW_AUTOSIZE );
  namedWindow("Contours", CV_WINDOW_AUTOSIZE );
  namedWindow("Polygon", CV_WINDOW_AUTOSIZE );
  namedWindow("PrunedPolygon", CV_WINDOW_AUTOSIZE );
  namedWindow("Targets", CV_WINDOW_AUTOSIZE );
  namedWindow( "Final", CV_WINDOW_AUTOSIZE );

  createTrackbar("minsize", "PrunedPolygon", &minsize, max_minsize, processImageCallback);
  createTrackbar("threshold", "Threshold Raw", &thresh, max_thresh, processImageCallback);
  createTrackbar("Poly epsilon", "Polygon", &poly_epsilon, max_poly_epsilon, processImageCallback);
  createTrackbar("Element: 0:Rect 1:Cross 2:Ellipse", "Dilate", &dilation_elem, max_elem, processImageCallback);
  createTrackbar("Kernel size:\n 2n+1", "Dilate", &dilation_size, max_kernel_size, processImageCallback);
  createTrackbar("Erode", "Dilate", &erode_count, erode_max, processImageCallback);
#endif
}

// Determine if a polygon contains another polygon
// These are targets (Outer rectangle is the outer part of the reflective tape
// inner rectangle is the inner part of the reflective tape).
bool rectContainsRect(int i, const vector<vector<Point> > &prunedPoly) {
  for (int j =0; j < prunedPoly.size(); j++) {
    // Don't check against yourself
    if (i == j) continue;
    if (pointPolygonTest(prunedPoly[i], prunedPoly[j][0], false) > 0) {
      return true;
    }
  }
  return false;
}

// Struct containing information about the vision targets
struct TargetData {
  vector<Point> points;
  float centerX;
  float centerY;
  float sizeX;
  float sizeY;
  float distanceX;
  float distanceY;
  float angleX;
};

float computeLowYOffset(float distance) {
  return 0.0;
}

// For each of target compute size, distance, angle
void getTargetData(Mat &image, const vector<vector<Point> > &targetQuads, vector<TargetData> &targets) {
  for (int i=0; i < targetQuads.size(); i++) {
    TargetData target;
    target.points = targetQuads[i];
    float centerX = 0;
    float centerY = 0;
    for (int j=0; j < target.points.size(); j++) {
      int x = target.points[j].x;
      int y = target.points[j].y;
      centerX += x;
      centerY += y;
    }
    target.centerX = centerX/4.0;
    target.centerY = centerY/4.0;
    float x1 = (abs(target.points[0].x - target.points[1].x) +
	      abs(target.points[2].x - target.points[3].x))/2.0;
    float x2 = (abs(target.points[1].x - target.points[2].x) +
	      abs(target.points[3].x - target.points[0].x))/2.0;
    float sizeX = max(x1, x2);

    float y1 = (abs(target.points[0].y - target.points[1].y) +
	      abs(target.points[2].y - target.points[3].y))/2.0;
    float y2 = (abs(target.points[1].y - target.points[2].y) +
	      abs(target.points[3].y - target.points[0].y))/2.0;
    float sizeY = max(y1, y2);

    target.sizeX = sizeX;
    target.sizeY = sizeY;
    target.distanceX = 9952.5956566118 * pow(sizeX, -1.0154997664);
    target.distanceY = 7560.3188994048 * pow(sizeY, -1.0190855673);
    target.angleX = .1105 * ((image.cols / 2) - target.centerX);

    targets.push_back(target);
  }
}

// Print out information about the targets to the console
void printTargets(vector<TargetData> &targets) {
  printf("----------------------------------------------------------------\n");
  for (int i=0; i < targets.size(); i++) {
    printf("Poly Points[");
    for (int j=0; j < targets[i].points.size(); j++) {
      printf("(%d, %d) ", targets[i].points[j].x, targets[i].points[j].y);
    }
    printf("] ");
    printf("Center (%f, %f) ", targets[i].centerX, targets[i].centerY);
    printf("Size (%f, %f) \n", targets[i].sizeX, targets[i].sizeY);
  }
}

// Send a message about the targets to the crio
int sendMessage(float distance, float angle) {
  char buffer[BUFFERSIZE];
  char sendbuffer[BUFFERSIZE];
  struct sockaddr_in addr;
  int sd;
  unsigned int addr_size;
  
  if ( (sd = socket(PF_INET, SOCK_DGRAM, 0)) < 0 ) {
    perror("Socket");
    return -1;
  }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(9999);
  if ( inet_aton("10.17.68.2", &addr.sin_addr) == 0 ) {
    perror("10.17.68.2");
    return -1;
  }
  sprintf(sendbuffer, "Distance=%f:Angle=%f", distance, angle);
  sendto(sd, sendbuffer, strlen(sendbuffer)+1, 0, (struct sockaddr*)&addr, sizeof(addr));
  bzero(buffer, BUFFERSIZE);
  addr_size = sizeof(addr);
  if ( recvfrom(sd, buffer, BUFFERSIZE, 0, (struct sockaddr*)&addr, &addr_size) < 0 )
    perror("server reply");
  else
    printf("Reply: %s:%d \"%s\"\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), buffer);
  close(sd);
}

// This is called every time that we get a new image to process the image, get target data,
// and send the information to the crio
void processImageCallback(int, void* ) {
  vector<Mat> planes;
  Mat src_color;
  split(src, planes);
  
  // Keep the color that we are intested in and substract off the other planes
  // RED - .5 * BLUE - .5 * GREEN
  #ifdef WPI_IMAGES
  // This is for working with WPI sample images
  addWeighted(planes[RED_PLANE], 1, planes[GREEN_PLANE], -.5, 0, src_color);
  addWeighted(src_color, 1, planes[BLUE_PLANE], -.5, 0, src_color);
  #else
  // This is the normal case
  addWeighted(planes[GREEN_PLANE], 1, planes[RED_PLANE], -.5, 0, src_color);
  addWeighted(src_color, 1, planes[BLUE_PLANE], -.5, 0, src_color);
  #endif
  
  // Dilation + Erosion = Close
  int dilation_type;
  if( dilation_elem == 0 ) { dilation_type = MORPH_RECT; }
  else if( dilation_elem == 1 ) { dilation_type = MORPH_CROSS; }
  else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
  
  Mat element = getStructuringElement(dilation_type,
				      Size( 2*dilation_size + 1, 2*dilation_size+1 ),
				      Point( dilation_size, dilation_size ) );
  Mat src_gray = src_color.clone();
  // This now does a close
  dilate(src_gray, src_gray, element );
  for (int i=0; i < erode_count; i++) {
    erode(src_gray, src_gray, element);
  }
  
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  
  /// Detect edges using Threshold
  threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );

  /// Find contours
  findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
  
  /// Find the convex hull object for each contour
  vector<vector<Point> >hull( contours.size() );
  for( int i = 0; i < contours.size(); i++ ) {
    convexHull( Mat(contours[i]), hull[i], false ); }
  
  /// Draw contours + hull results
#ifdef GUIALL
  Mat drawingContours = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ ) {
    Scalar color = Scalar( 255, 255, 255 );
    drawContours( drawingContours, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  }
#endif 
  
  // Approximate the convect hulls with pologons
  // This reduces the number of edges and makes the contours
  // into quads
  vector<vector<Point> >poly( contours.size() );
  for (int i=0; i < contours.size(); i++) {
    approxPolyDP(hull[i], poly[i], poly_epsilon, true);
  }
  
  // Prune the polygons into only the ones that we are intestered in.
  vector<vector<Point> >prunedPoly(0);
  for (int i=0; i < poly.size(); i++) {
    // Only 4 sized figures
    if (poly[i].size() == 4) {
      Rect bRect = boundingRect(poly[i]);
      // Remove polygons that are too small
      if (bRect.width * bRect.height > minsize) {
	prunedPoly.push_back(poly[i]);
      }
    }
  }
  
  // Prune to targets (Rectangles that contain an inner rectangle
  vector<vector<Point> >targetQuads(0);
  for (int i=0; i < prunedPoly.size(); i++) {
    // Keep only polygons that contain other polygons
    if (rectContainsRect(i, prunedPoly)) {
      targetQuads.push_back(prunedPoly[i]);
    }
  }
  
  vector<TargetData> targets;
  getTargetData(src, targetQuads, targets);
  //  printTargets(targets);
  
#ifdef GUIALL
  // Draw the contours in a window
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ ) {
    Scalar color = Scalar( 255, 255, 255 );
    drawContours( drawing, poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  }
  
  // Draw the pruned Poloygons in a window
  Mat prunedDrawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for (int i=0; i < prunedPoly.size(); i++) {
    Scalar color = Scalar( 255, 255, 255 );
    drawContours(prunedDrawing, prunedPoly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  }
  
  // Draw the targets
  Mat targetsDrawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for (int i=0; i < targetQuads.size(); i++) {
    Scalar color = Scalar( 255, 255, 255 );
    drawContours(targetsDrawing, targetQuads, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  }
  imshow("Source", src);
  imshow("Color", src_color);
  imshow("Dilate", src_gray);
  imshow("Threshold Raw", threshold_output);
  imshow("Contours", drawingContours);
  imshow("Polygon", drawing );
  imshow("PrunedPolygon", prunedDrawing);
  imshow("Targets", targetsDrawing);
#endif

  // Output the final image
  Mat finalDrawing = src.clone();
  for (int i=0; i < targetQuads.size(); i++) {
    Scalar color = Scalar( 255, 255, 255 );
    drawContours(finalDrawing, targetQuads, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  }
  for (int i = 0; i < targets.size(); i++ ) {
    Point center( targets[i].centerX, targets[i].centerY );
    Scalar color = Scalar( 255, 255, 255 );
    circle( finalDrawing, center, 10, color );
    Point textAlign( targets[i].centerX - 50, targets[i].centerY + 35 );
    Point sizeAlign( targets[i].centerX - 50, targets[i].centerY + 55 );
    Point distanceAlign( targets[i].centerX - 50, targets[i].centerY + 75 );
    Point angleXAlign( targets[i].centerX - 50, targets[i].centerY + 95 );
    ostringstream text, size, distance, angle;
    text << "Center: X: " << targets[i].centerX << " Y: " << targets[i].centerY;
    distance << "Distance: X: " << targets[i].distanceX << " Y: " << targets[i].distanceY;
    size << "Size: X: " << targets[i].sizeX << " Y: " << targets[i].sizeY;
    angle << "Angle: X: " << targets[i].angleX;
    putText( finalDrawing, text.str(), textAlign, CV_FONT_HERSHEY_PLAIN, .7, color );
    putText( finalDrawing, size.str(), sizeAlign, CV_FONT_HERSHEY_PLAIN, .7, color );
    putText( finalDrawing, distance.str(), distanceAlign, CV_FONT_HERSHEY_PLAIN, .7, color );
    putText( finalDrawing, angle.str(), angleXAlign, CV_FONT_HERSHEY_PLAIN, .7, color );
  }
  // If we have a target then send it to the cRio
  #ifdef CRIO_NETWORK
  if (targets.size()) {
   sendMessage(targets[0].distanceY, targets[0].angleX);
  }
  #endif
  
  imshow( "Final", finalDrawing );
}

int main( int argc, char** argv ) {
  time_t start, end;      // start and end times
  double fps;             // fps calculated using number of frames / seconds
  int counter = 0;        // frame counter
  double sec;             // floating point seconds elapsed since start
  
  time(&start);           // start the clock

#ifdef PROCESS_CAM
  VideoCapture cap("http://10.17.68.90/axis-cgi/mjpg/video.cgi?resolution=320x240&req_fps=30&.mjpg"); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
    return -1;
  cap >> src;
#else
  // Load an image from a file
  src = imread( argv[1], 1 );
#endif

#ifdef GUI
  createGuiWindows();
#endif
  
  //  dilation_callback(0,0);
  while (1) {
#ifdef PROCESS_CAM
    //cap.set(CV_CAP_PROP_POS_AVI_RATIO, 1);
    cap.grab();
    cap >> src;
#endif

    processImageCallback( 0, 0 );

#ifdef PROCESS_CAM
    char c = waitKey(1);
#else
    // Non realtime images
    char c = waitKey(1000);
#endif

    if (c == 'q') return 0;
    // see how much time has elapsed
    time(&end);
    
    // calculate current FPS
    ++counter;       
    sec = difftime (end, start);     
    fps = counter / sec;
    // will print out Inf until sec is greater than 0
    printf("FPS = %.2f\n", fps);
    
  }
  return 0;
}



