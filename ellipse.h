#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "fillableshape.h"

class Ellipse : public fillableShape
{
public:
    Ellipse(const QPoint, const QPoint, fillProperties, borderProperties);
    Ellipse(QPoint, int, int, fillProperties, borderProperties);

    void draw() override;

    int getWidth();
    int getHeight();

    void setWidth(int);
    void setHeight(int);
private:
    int width;
    int height;
};


#endif // ELLIPSE_H
