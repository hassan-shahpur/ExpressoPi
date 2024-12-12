#include <opencv2/opencv.hpp> 

#include "EmotionDetection.h" 

// Constructor: Initializes an EmotionDetection object with a TensorFlow model file.
EmotionDetection::EmotionDetection(const std::string& TFfile) 
    : neuralNetwork(cv::dnn::readNet(TFfile)), // Load the TensorFlow model
      idLabel([]() { //lambda function
          std::map<int, std::string> labels; // Create a map to hold the label IDs and their corresponding string labels.
          labels[0] = "Angry"; 
          labels[1] = "Disgust";
          labels[2] = "Fear";
          labels[3] = "Happy"; 
          labels[4] = "Sad";   
          labels[5] = "Surprise";
          labels[6] = "Neutral"; 
          return labels; // Return the populated map.
      }()) 
{}

// Analyzes the emotion
std::vector<std::string> EmotionDetection::emotionANL(ModelInput& image) {
    std::vector<cv::Mat> afImage = image.getInput(); // Get preprocessed images ready
    std::vector<std::string> expressionLabel; // Vector to store the predicted emotion labels.

    for (const auto& img : afImage) { // Loop through each preprocessed image.
        // Convert the image to a blob that can be fed into the neural network.
        cv::Mat blob = cv::dnn::blobFromImage(img, 1.0, cv::Size(), cv::Scalar(), false, false);
        neuralNetwork.setInput(blob); // Set the neural network's input to the blob.
        cv::Mat prob = neuralNetwork.forward(); // Perform forward pass to get prediction probabilities.

        // Find the class with the highest probability.
        cv::Point classIdPoint;
        double confidence;
        cv::minMaxLoc(prob, nullptr, &confidence, nullptr, &classIdPoint);
        int top_class_id = classIdPoint.x; 

        auto it = idLabel.find(top_class_id); // Find the class ID in the idLabel map to get the corresponding emotion label.
        if (it != idLabel.end()) { // If the class ID is found in the map,
            expressionLabel.push_back(it->second); // Add the corresponding emotion label to the vector.
        }
    }

    return expressionLabel; // Return the vector of emotion labels predicted for the image.
}
