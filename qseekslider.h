#ifndef QSEEKSLIDER_H
#define QSEEKSLIDER_H

#include <QSlider>

class QSeekSlider : public QSlider
{
    Q_OBJECT
public:
    explicit QSeekSlider(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void updateValue(int value);
    void valueChangedByUser(int value);

public slots:
    void updatePosition(int setPosition);
    void userSliderRelease();
    void resetToStoppedPos();

private:
    bool userDragsSlider;

};

#endif // QSEEKSLIDER_H
