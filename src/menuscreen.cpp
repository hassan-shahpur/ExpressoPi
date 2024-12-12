// MenuScreen.cpp
#include "MenuScreen.h"
#include "ui_MenuScreen.h"

MenuScreen::MenuScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuScreen)
{
    ui->setupUi(this);
}

MenuScreen::~MenuScreen()
{
    delete ui;
}

void MenuScreen::on_pushButtonGetStarted_2_clicked() {
    emit getStartedClicked();
}
