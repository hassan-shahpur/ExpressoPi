#include <opencv2/opencv.hpp>
#include "ModelInput.h"
#include "ConvertToGrayScale.h"


void ModelInput::IMGprocess() {
    if (!faceinframe.empty()) {
        for (const auto& interestpoints : faceinframe) {
            // Declare processed_image within the loop to ensure it's scoped correctly.
            cv::Mat processed_image;

            // Convert to grayscale using ConvertToGrayScale class
            cv::Mat gray_image = ConvertToGrayScale::toGray(interestpoints);

            // Resize the grayscale image to the model input size
            cv::resize(gray_image, processed_image, cv::Size(48,48));

            // Normalize the pixel values of the resized image
            processed_image.convertTo(processed_image, CV_32FC3, 1.f/255);

            // Store the processed image in the input vector
            input.push_back(processed_image);
        }
    }
}


// Sets the current frame for the ModelInput instance.
void ModelInput::setFrame(cv::Mat& frame) {
    this->_frame = frame;
}

// Returns a collection of images or regions of interest (ROIs) within the current frame.

std::vector<cv::Mat> ModelInput::getIMG() {
    return this->faceinframe;
}

// Retrieves the current frame stored in the ModelInput instance.

cv::Mat ModelInput::getFrame() {
    return this->_frame;
}

// Adds a single region of interest..

void ModelInput::setIMG(cv::Mat& interestpoints) {
    this->faceinframe.push_back(interestpoints);
}

// Returns a collection of images that have been processed and are ready to be used as input for a model.

std::vector<cv::Mat> ModelInput::getInput() {
    return this->input;
}




