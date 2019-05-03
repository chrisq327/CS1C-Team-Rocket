#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "fillableshape.h"

class Rectangle : public fillableShape
{
public:
    Rectangle(QPoint&, QPoint&, unsigned int, fillProperties, borderProperties);
    Rectangle(QPoint&, int, int, unsigned int, fillProperties, borderProperties);

    void draw(QPainter&) override;

    int getWidth() const;
    int getHeight() const;

    void setWidth(int);
    void setHeight(int);
private:
    int width;
    int height;
};

#endif // RECTANGLE_H
