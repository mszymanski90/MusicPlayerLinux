#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton* getLoadFileBt();
    QPushButton* getPlayPauseBt();
    QPushButton* getStopBt();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
