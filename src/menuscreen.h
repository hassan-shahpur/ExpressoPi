/**
 * @file menuscreen.h
 * @author Hussein Fahd, Kishor Loganathan, Hassan Shahpurwala, Rishyanth Varma Thotakura, Delicia Wong
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <QWidget>

/**
 * @brief The MenuScreen class provides a UI for the application.
 * @details The MenuScreen class provides a user interface for the application, where users can navigate and perform actions. 
 * 
 */
namespace Ui {
class MenuScreen;
}

class MenuScreen : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Construct a new MenuScreen object
     * @details The constructor constructs a MenuScreen object which points to a QWidget widget parent.
     * @param parent Pointer to the parent widget; Default is nullptr.
     */
    explicit MenuScreen(QWidget *parent = nullptr);
    
    /**
     * @brief Destroy the MenuScreen object
     * @details This destructor destroys the MenuScreen object, deallocating the memory associated with the object.
     * 
     */
    ~MenuScreen();

signals:
    /**
     * @brief Emits signal when "Get Started" button is clicked
     * @details This signal will be emitted when the user clicks on the "Get Started" button on the MenuScreen.
     * 
     */
    void getStartedClicked();

    /**
     * @brief Signal emitted to process frame
     * @details This signal will be emitted when frames begin to be processed.
     * 
     */
    void processFrameSignal();

private slots:
    /**
     * @brief Invoked when "Get Started" button is clicked.
     * @details This slot is invoked when the user clicks on the "Get Started" button, and will emit the getStartedClicked() signal.
     * 
     */
    void on_pushButtonGetStarted_2_clicked();

private:
    Ui::MenuScreen *ui; //pointer to UI object
};

#endif // MENUSCREEN_H
