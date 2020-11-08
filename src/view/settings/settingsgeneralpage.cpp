#include "settingsgeneralpage.hpp"
#include "ui_settingsgeneralpage.h"
#include "view/misc/displayhelper.hpp"
#include <QFileDialog>

SettingsGeneralPage::SettingsGeneralPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsGeneralPage)
{
    ui->setupUi(this);
    DisplayHelper::setIcon(ui->buttonPosesPath, DisplayHelper::FOLDEROPEN, 20);
    DisplayHelper::setIcon(ui->buttonImagesPath, DisplayHelper::FOLDEROPEN, 20);
    DisplayHelper::setIcon(ui->buttonObjectModelsPath, DisplayHelper::FOLDEROPEN, 20);
    DisplayHelper::setIcon(ui->buttonSegmentationImages, DisplayHelper::FOLDEROPEN, 20);
}

SettingsGeneralPage::~SettingsGeneralPage()
{
    delete ui;
}

void SettingsGeneralPage::setPreferences(Settings *preferences) {
    this->preferences = preferences;
    ui->editImagesPath->setText(preferences->getImagesPath());
    ui->editObjectModelsPath->setText(preferences->getObjectModelsPath());
    ui->editPosesPath->setText(preferences->getPosesFilePath());
    ui->editSegmentationImagesPath->setText(preferences->getSegmentationImagesPath());
}

QString SettingsGeneralPage::openFolderDialogForPath(QString path) {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                path,
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    return dir;
}

QString SettingsGeneralPage::openFileDialogForPath(QString path) {
    QString dir = QFileDialog::getOpenFileName(this,
                                               tr("Open JSON File"),
                                               path,
                                               tr("JSON Files (*.json)"));
    return dir;
}

//! Public slots
void SettingsGeneralPage::buttonImagesPathClicked() {
    QString newPath = openFolderDialogForPath(ui->editImagesPath->text());
    if (newPath.compare("") != 0) {
        ui->editImagesPath->setText(newPath);
        preferences->setImagesPath(newPath);
    }
}

void SettingsGeneralPage::buttonSegmentationImagesPathClicked() {
    QString newPath = openFolderDialogForPath(ui->editSegmentationImagesPath->text());
    if (newPath.compare("") != 0) {
        ui->editSegmentationImagesPath->setText(newPath);
        preferences->setSegmentationImagePath(newPath);
    }
}

void SettingsGeneralPage::buttonObjectModelsPathClicked() {
    QString newPath = openFolderDialogForPath(ui->editObjectModelsPath->text());
    if (newPath.compare("") != 0) {
        ui->editObjectModelsPath->setText(newPath);
        preferences->setObjectModelsPath(newPath);
    }
}

void SettingsGeneralPage::buttonPosesPathClicked() {
    QString newPath = openFileDialogForPath(ui->editPosesPath->text());
    if (newPath.compare("") != 0) {
        ui->editPosesPath->setText(newPath);
        preferences->setPosesFilePath(newPath);
    }
}

