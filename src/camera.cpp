
#include "camera.h"

// Constructor: Initializes a Camera object with a specified device ID.
Camera::Camera(int deviceID) : deviceID(deviceID) {}

// Initializes the camera for capturing video.

bool Camera::initialize() {
    cap.open(deviceID); // Attempt to open the camera device.
    return cap.isOpened(); // Check if the camera was successfully opened.
}

// Captures a single frame from the initialized camera.
cv::Mat Camera::captureFrame() {
    cv::Mat frame; 
    if (cap.isOpened()) { // Check if the camera has been initialized and opened.
        cap.read(frame); 
    }
    return frame; 
}


void Camera::release() {
    if (cap.isOpened()) { // Check if the camera is currently opened.
        cap.release(); 
    }
}


