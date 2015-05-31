#ifndef QVOLUMESLIDER_H
#define QVOLUMESLIDER_H

#include <QSlider>

class QVolumeSlider : public QSlider
{
    Q_OBJECT
public:
    explicit QVolumeSlider(QWidget *parent = 0);

signals:
    void volumeChanged(double volume);

public slots:

private slots:
    void updateVolume(int value);

};

#endif // QVOLUMESLIDER_H
