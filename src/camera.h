/**
 * @file camera.h
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CAMERA_H
#define CAMERA_H


#include <opencv2/opencv.hpp>

/**
 * @brief This file defines a Camera class, which provides the functionality to interact with a camera device.
 * @details This file defines the Camera class, which provides the functionality to interact with a camera device, including initializing the camera, capturing frames, and releasing the camera resources
 */
class Camera {
public:

    /**
     * @brief Camera class constructor
     * @details A constructor to construct an object of type Camera with 0 as a default webcam ID
     * 
     * @param deviceID The ID of a webcam
     */
    Camera(int deviceID = 0);

    /**
     * @brief Function to initialize the camera
     * @details This function attempts to open the camera device, then checks to see if it has successfully been opened.
     * 
     * @return True if the camera was successfully opened.
     * @return False if the camera was not opened.
     */
    bool initialize();

    /**
     * @brief Function to capture a single frame from the webcam.
     * @details This function grabs and reads a single frame captured from the camera if it has been successfully opened.
     * 
     * @return cv::Mat The captured frame from the camera, or an empty cv::Mat if the camera was not successfully opened.
     */
    cv::Mat captureFrame();

    /**
     * @brief Release the video capture object.
     * @details This function will close the capturing device, deallocating the memory occupied by the object.
     * 
     */
    void release();

private:
    cv::VideoCapture cap; //VideoCapture object to interact with camera
    int deviceID; //ID for the camera device
};

#endif // CAMERA_H
