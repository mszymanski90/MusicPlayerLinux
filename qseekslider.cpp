#include <QStyleOptionSlider>
#include <QRect>
#include <QMouseEvent>
#include "qseekslider.h"

#include <iostream>

QSeekSlider::QSeekSlider(QWidget *parent) :
    QSlider(parent),
    userDragsSlider(false)
{
    connect(this, SIGNAL(updateValue(int)), this, SLOT(setValue(int)));

    //connect(this, SIGNAL(sliderReleased()), this, SLOT(userSliderRelease()));
}

void QSeekSlider::mousePressEvent(QMouseEvent *event)
{
    QStyleOptionSlider opt;
    initStyleOption(&opt);
    QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

    if(event->button() == Qt::LeftButton) userDragsSlider = true;

    if(event->button() == Qt::LeftButton)
    {
        int newPosition = QStyle::sliderValueFromPosition(minimum(), maximum(), event->x(), width());
        setSliderPosition(newPosition);
        event->accept();
    }
}

void QSeekSlider::mouseMoveEvent(QMouseEvent *event)
{
    int newPosition = QStyle::sliderValueFromPosition(minimum(), maximum(), event->x(), width());
    setSliderPosition(newPosition);
    event->accept();
}

void QSeekSlider::mouseReleaseEvent(QMouseEvent *event)
{
    int newValue = QStyle::sliderValueFromPosition(minimum(), maximum(), event->x(), width());
    setValue(newValue);
    emit valueChangedByUser(QSlider::value());
    QSlider::mouseReleaseEvent(event);
    userDragsSlider = false;
}

void QSeekSlider::updatePosition(int setPosition)
{
    if(!userDragsSlider)
    {
        emit updateValue(setPosition);
    }
}

void QSeekSlider::userSliderRelease()
{
    if(userDragsSlider) emit valueChangedByUser(QSlider::value());
}
