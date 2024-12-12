/**
 * @file FaceDetector.h
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <opencv2/opencv.hpp>
#include "ModelInput.h"


/**
 * @file FaceDetector.h
 * @brief Offers functionalities for face detection and emotion annotation in images.
 *
 * This class uses OpenCV's cascade classifiers to detect human faces  and
 * provides methods to draw boxes aroundfaces, prepare images for emotion detection
 */


// Path to the cascade classifier for face detection.
extern const std::string CASCADECLASSIFIERPATH;


class FaceDetector {
private:
    // Classifier for detecting faces.
    cv::CascadeClassifier cascade;

    /**
     * @brief Prepares the image by converting it to grayscale and normalizing its histogram.
     * @details This function prepares the image for detection analysis by converting the image from colour to grayscale, then equalizing the histogram of the image.
     * 
     * @param image The unprocessed image.
     * @return cv::Mat The equalized image.
     */
    cv::Mat prepareFrameForDetection(const cv::Mat& image);

    // Stores the locations of detected faces as rectangles.
    std::vector<cv::Rect> detectedFaces;

public:
    /**
     * @brief Construct a new Face Detector object
     * @details This constructor initializes the FaceDetector object by loading the cascade classifier.
     * 
     */
    FaceDetector();

    /**
     * @brief Detects faces in the given image and annotates them with bounding boxes.
     * @details The drawFrame function receives the frame and draws a rectangle around detected faces. The region of interest (ROI) of the image is set in the image.
     * 
     * @param image The frame from which the faces will be detected.
     * @return ModelInput The annotated frame.
     */
    ModelInput drawFrame(cv::Mat& image);

    /**
     * @brief Draws bounding boxes around detected faces in the image.
     * @details This function first prepares the received frame for facial detection, then detects faces present in the prepared frame using cascade classifer.
     * 
     * @param image The captured frame.
     */
    void drawBox(cv::Mat& image);

    /**
     * @brief Overlays emotion prediction text on the image near detected faces.
     * @details If a face was detected in the frame, displayEmotion will write the emotion that was predicted by the EmotionDetection class onto the screen.
     * 
     * @param annotatedFrame The frame on which a face was detected and a rectangle was drawn around the face.
     * @param expressionLabel The predicted expression.
     * @return ModelInput The annotated frame with a label indicating the expression shown on the detected face.
     */
    ModelInput displayEmotion(ModelInput& annotatedFrame, std::vector<std::string>& expressionLabel);
};

#endif // FACEDETECTOR_H
