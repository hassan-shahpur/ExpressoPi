/**
 * @file ModelInput.h
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ModelInput_H
#define ModelInput_H

#include <opencv2/opencv.hpp>
#include <iostream>


/**
 * @brief Manages frame preprocessing for emotion detection analysis.
 * @details The ModelInput class handles the preprocessing of input frames for emotion detection analysis.
 * It provides methods to process input images, set and retrieve frames, and manage regions of interest.
 */
class ModelInput {


private:
    // the full video frame
    cv::Mat _frame;
    // region of interest within the bounding box
    std::vector<cv::Mat> faceinframe;
    // preprocessed image ready for model
    std::vector<cv::Mat>  input;


public: 
    /**
     * @brief Construct a new Model Input object
     * @details The constructor constructs a new Model Input object to process the images from the camera.
     * 
     */
    ModelInput() {};
    
    /**
     * @brief Destroy the Model Input object
     * @details The destructor destroys the Model Input object, deallocating the memory associated with it.
     * 
     */
    ~ModelInput() {};

    /**
     * @brief Processes input images for further analysis
     * @details The ModelInput class processes the input frames stored in the faceinframe vector by performing the following:
     * - Convert the image to grayscale using the ConvertToGrayscale class
     * - Resize the grayscale image to model input size
     * - Normalize pixel values of the resized image
     * - Store the processed images in the input vector.
     * 
     */
    void IMGprocess();

    /**
     * @brief Get the Frame object
     * @details This retrieves the current frame that is stored in the ModelInput instance.
     * 
     * @return cv::Mat The frame retrieved from the ModelInput instance.
     */
    cv::Mat getFrame();
    
    /**
     * @brief Retrieves regions of interest within the current frame.
     * @details The getIMG function retrieves a collection of images or regions of interest from within the current frame.
     * 
     * @return std::vector<cv::Mat> A copy of the faceinframe variable, which contains images or regions of interest from the current frame.
     */
    std::vector<cv::Mat> getIMG();
    
    /**
     * @brief Get the Input object
     * @details getInput retrieved a collection of processed images that can be used as input for the emotion detection model
     * @return std::vector<cv::Mat> A copy of the input variable, which contains processed images to be used as input for the model.
     */
    std::vector<cv::Mat> getInput();


    /**
     * @brief Set current frame
     * @details This function sets the current frame for the ModelInput instance
     * 
     * @param frame The current frame.
     */
    void setFrame(cv::Mat& frame);

    /**
     * @brief Set a single region of interest
     * @details setIMG adds a single region of interest to the faceinframe vector
     * 
     * @param interestpoints Region of interest to be added to faceinframe.
     */
    void setIMG(cv::Mat& interestpoints);
    
        











};

#endif