/**
 * @file main.cpp
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @brief The main class for the project
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <opencv2/opencv.hpp> 
#include <fstream> 
#include <iostream> 
#include <sstream> 
#include <thread> 
#include <algorithm> 
#include <mutex>

#include "FaceDetector.h"
#include "ModelInput.h"
#include "EmotionDetection.h"
#include "camera.h"
#include "menuscreen.h"
#include <QTimer>
#include <QApplication>


const std::string WINDOW = "ExpressoPI"; // Name of the GUI window
const std::string TF = "../cascades/tensorflow_model.pb"; // Path to the TensorFlow model
const std::string CASCADECLASSIFIERPATH = "../cascades/haarcascade_frontalface_alt2.xml"; // Path to Cascade classifier

Camera camera;
EmotionDetection model(TF);
FaceDetector face_detector;

/**
 * @brief Initializes the camera and other objects needed for the program to run
 * @details This function initializes all of the objects that will be necessary for the program to run, including the camera, emotion detection model, and facedetector
 * 
 * @param camera Camera object
 * @param model EmotionDetection model
 * @param face_detector FaceDetector object
 * @return true if the initialization was successful
 * @return false if the initialization failed
 */
bool initializeCameraAndObjects(Camera& camera, EmotionDetection& model, FaceDetector& face_detector) {
    if (!camera.initialize()) { // Initialize the camera
        std::cerr << "Camera initialization failed." << std::endl;
        return false; // Return false if initialization fails
    }
    cv::namedWindow(WINDOW); // Create a named window to display the video feed
    return true; // Return true if initialization is successful
}

/**
 * @brief Processes each frame of the video feed
 * @details If a frame is captured from the camera, the captured frame will be processed. A rectangle will be drawn around the detected face, and it will display the detected emotions.
 * 
 * @param camera Camera object
 * @param face_detector Face detector
 * @param model EmotionDetection model
 */
void processFrame(Camera& camera, FaceDetector& face_detector, EmotionDetection& model) {
    cv::Mat frame = camera.captureFrame(); // Capture a frame from the camera

    if (frame.empty()) { // Check if the frame is empty
        std::cerr << "Frame not captured. Exiting..." << std::endl;
        return; // Exit the function if no frame was captured
    }

    // Process the frame if it's not empty
    face_detector.drawBox(frame); // Draw bounding box around faces
    ModelInput annotatedFrame = face_detector.drawFrame(frame);

    std::vector<cv::Mat> afImage = annotatedFrame.getIMG();
    if (!afImage.empty()) { 
        annotatedFrame.IMGprocess(); // Process the images for model input
        std::vector<std::string> expressionLabel = model.emotionANL(annotatedFrame); // Analyze emotions
        annotatedFrame = face_detector.displayEmotion(annotatedFrame, expressionLabel); // Display detected emotions
    }

    cv::Mat output_frame = annotatedFrame.getFrame(); // Get the frame to be displayed
    imshow(WINDOW, output_frame.empty() ? frame : output_frame); 
}

/**
 * @brief Main function
 * @details The Main function displays the menuscreen and emits the signal to process the frames
 * 
 * @param argc 
 * @param argv 
 * @return int value representing the exit status of the application.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuScreen menuScreen;
    menuScreen.show();

    QObject::connect(&menuScreen, &MenuScreen::getStartedClicked, [&]() {
        menuScreen.hide(); // This will hide the menu screen
        if (!initializeCameraAndObjects(camera, model, face_detector)) {
            app.quit(); // Exit the application if initialization fails
            return;
        }

        // Start a QTimer to periodically emit the processFrameSignal
        QTimer *timer = new QTimer(&menuScreen);
        QObject::connect(timer, &QTimer::timeout, [&]() {
            emit menuScreen.processFrameSignal();
        });
        timer->start(33);


        QObject::connect(&menuScreen, &MenuScreen::processFrameSignal, [&]() {
            processFrame(camera, face_detector, model);
        });
    });

    return app.exec();
}

