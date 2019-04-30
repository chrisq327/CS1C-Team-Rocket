#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "fillableshape.h"

class Ellipse : public fillableShape //determine box that ellipse lies in, then call drawEllipse
{
public:
    Ellipse(const QPoint&, const QPoint&, unsigned int, fillProperties, borderProperties);
    Ellipse(const QPoint&, int, int, unsigned int, fillProperties, borderProperties);

    void draw(QPainter&) override;

    int getWidth();
    int getHeight();

    void setWidth(int);
    void setHeight(int);
private:
    int width; //of box
    int height;//of box
};


#endif // ELLIPSE_H
