#include <math.h>
#include <iostream>
#include "qvolumeslider.h"

QVolumeSlider::QVolumeSlider(QWidget *parent) :
    QSlider(parent)
{
    setRange(0,1000);
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(updateVolume(int)));
    setValue(1000);
    setSliderPosition(1000);
}

void QVolumeSlider::updateVolume(int value)
{
    double volumeInDB = (static_cast<double>(value)) / 10;
    volumeInDB = 50*log10(volumeInDB) - 100;
    double volumeInPower = pow(10, (volumeInDB)/(20));
    emit volumeChanged(volumeInPower);
}
