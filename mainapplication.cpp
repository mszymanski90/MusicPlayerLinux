#include "mainapplication.h"

MainApplication::MainApplication(QObject *parent) :
    QObject(parent)
{

}

void MainApplication::init()
{
    window.show();
    core.init(&logger);

    connect(window.getLoadFileBt(), SIGNAL(clicked()), this, SLOT(loadFile()));
    connect(window.getPlayPauseBt(), SIGNAL(clicked()), this, SLOT(play()));
}

std::string MainApplication::getPathFromFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(&window,
         tr("Open file"), "/home/jana", tr("Image Files (*.mp3 *.m4a *.ogg)"));

    //return fileName.toStdString();
    return std::string("./test_mp3.mp3");
}

void MainApplication::loadFile()
{
    core.loadFile(getPathFromFileDialog());
}

void MainApplication::play()
{
    core.play();
}
