/**
 * @file ConvertToGrayScale.h
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CONVERTTOGRAYSCALE_H
#define CONVERTTOGRAYSCALE_H

#include <opencv2/opencv.hpp>

/**
 * @brief This file defines a ConvertToGrayscale class, which provides a utility method for converting color images to grayscale.
 * @details the ConvertToGrayScale method takes the captured frame and converts it from a colour frame to grayscale for further analysis.
 */


class ConvertToGrayScale {
public:
    /**
     * @brief Function to convert a colour frame to grayscale
     * @details This function takes the provided frame and converts it from a colour frame to grayscale.
     * 
     * @param frame The original captured frame
     * @return cv::Mat The converted grayscale frame
     */
    static cv::Mat toGray(const cv::Mat& frame);
};

#endif // CONVERTTOGRAYSCALE_H
