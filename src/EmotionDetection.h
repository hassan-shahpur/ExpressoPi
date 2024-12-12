/**
 * @file EmotionDetection.h
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MODEL_H
#define MODEL_H

#include <opencv2/opencv.hpp>
#include <iostream>

#include "ModelInput.h"

/**
 * @file EmotionDetection.h
 * @brief Detects emotions using pre trained TensorFlow Model.
 * @details The EmotionDetection class utilizes a pre-trained TensorFlow Model to detect emotions from the pre-processed frame.
 */
class EmotionDetection {

private:
    // Neural network
    cv::dnn::Net neuralNetwork;

    // Mapping of the class id to the string label
    std::map<int, std::string> idLabel;


public:

    /**
     * @brief Construct a new EmotionDetection object
     * @details The EmotionDetection constructor constructs a new EmotionDetection object with a TensorFlow Model file.
     * 
     * @param TFfile The TensorFlow Model file.
     */
    EmotionDetection(const std::string& TFfile);

    /**
     * @brief Destroy the Emotion Detection object
     * @details The destructor for the EmotionDetection object, destroying the object and deallocating the memory associated with it.
     * 
     */
    ~EmotionDetection() {};

    /**
     * @brief Function to analyze the emotion
     * @details This function gets the pre-processed image and converts it into a blob which can be fed into the neural network.
     * The classID with the highest probability is determined, and the corresponding emotion label is added to a vector.
     * 
     * @param image The pre-processed image which will be analyzed to determine the emotions of the person in the image.
     * @return std::vector<std::string> The vector of emotion labels predicted for the image.
     */
    std::vector<std::string> emotionANL(ModelInput& image);



};


#endif