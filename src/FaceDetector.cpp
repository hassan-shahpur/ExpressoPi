#include "FaceDetector.h"
#include "ModelInput.h"
#include "ConvertToGrayScale.h" // Include the ConvertToGrayScale header

FaceDetector::FaceDetector() {
    // Load the cascade classifier
    cascade.load(CASCADECLASSIFIERPATH);
}

cv::Mat FaceDetector::prepareFrameForDetection(const cv::Mat& frame) {
    // Convert the frame to grayscale using the ConvertToGrayScale class
    cv::Mat grayImage = ConvertToGrayScale::toGray(frame);
    // Equalize the histogram of the grayscale image
    cv::Mat equalizedImage;
    cv::equalizeHist(grayImage, equalizedImage);
    return equalizedImage;
}

ModelInput FaceDetector::drawFrame(cv::Mat& frame) {
    ModelInput annotatedFrame;
    annotatedFrame.setFrame(frame); // Set the frame once for the Image object

    if (!detectedFaces.empty()) {
        // Draw a rectangle around the first detected face
        cv::rectangle(frame, detectedFaces[0], cv::Scalar(0, 165, 255), 5);

        // Extract ROI and set it in the Image object
        cv::Mat afImage = frame(detectedFaces[0]);
        annotatedFrame.setIMG(afImage);
    }

    return annotatedFrame;
}

ModelInput FaceDetector::displayEmotion(ModelInput& annotatedFrame, std::vector<std::string>& expressionLabel) {
    cv::Mat img = annotatedFrame.getFrame();

    if (!detectedFaces.empty()) {
        for (size_t i = 0; i < detectedFaces.size(); ++i) {
            const cv::Rect& r = detectedFaces[i];

            // Debug print statements
            std::cout << "i: " << i << ", expressionLabel.size(): " << expressionLabel.size() << std::endl;
            if (i < expressionLabel.size()) {
                std::cout << "expressionLabel[i]: " << expressionLabel[i] << std::endl;
            }

            // Check for out-of-bounds access and non-empty strings
            if (i < expressionLabel.size() && !expressionLabel[i].empty()) {
                int baseline = 0;
                cv::Size textSize = cv::getTextSize(expressionLabel[i], cv::FONT_HERSHEY_DUPLEX, 1.0, 2, &baseline);

                // Position the text in the middle of the top edge of the bounding box
                cv::Point textOrg((r.x + r.width / 2) - (textSize.width / 2),
                                  r.y - baseline); // Adjusted to position text on top

                // Check for text going above the image bounds and adjust
                if (textOrg.y < textSize.height) {
                    textOrg.y = r.y + r.height + textSize.height; // Move text inside the box if it goes above the image
                }

                // Write text prediction centered on the top of the bounding box
                cv::putText(img, expressionLabel[i], textOrg, cv::FONT_HERSHEY_DUPLEX, 
                            1.0, CV_RGB(118, 185, 0), 2);
            }
        }
    }

    annotatedFrame.setFrame(img);
    return annotatedFrame;
}


void FaceDetector::drawBox(cv::Mat& frame) {
    // Prepare the frame for face detection by converting to grayscale and equalizing histogram
    cv::Mat preparedFrame = prepareFrameForDetection(frame);

    // Detect faces with the prepared frame
    cascade.detectMultiScale(preparedFrame, this->detectedFaces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(100, 100));

    // Keep only the first detected face
    if (!detectedFaces.empty()) {
        detectedFaces.resize(1);
    }
}
