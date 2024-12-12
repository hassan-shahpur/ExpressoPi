#include "ConvertToGrayScale.h" 

// Converts a given color frame to a grayscale image.
cv::Mat ConvertToGrayScale::toGray(const cv::Mat& frame) {
    cv::Mat grayImage; // Declare a Mat object to store the grayscale image
    cv::cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY); // Convert the input frame to grayscale
    return grayImage; // Return the grayscale image
}
