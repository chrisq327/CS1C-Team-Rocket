#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "fillableshape.h"

class Ellipse : public fillableShape // a circle is an ellipse with the same width and height
{
public:
    Ellipse(const QPoint&, const QPoint&, unsigned int, fillProperties, borderProperties);
    Ellipse(const QPoint&, int, int, unsigned int, fillProperties, borderProperties);

    void draw(QPainter&) override;
    std::string toString() override;
    void moveOffset(QPoint&) override;

    int getWidth();
    int getHeight();

    void setWidth(int);
    void setHeight(int);
private:
    int width; //of box
    int height;//of box
};


#endif // ELLIPSE_H
