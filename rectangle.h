#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "fillableshape.h"

class Rectangle : public fillableShape
{
public:
    Rectangle(QPoint, QPoint, fillProperties, borderProperties);
    Rectangle(QPoint, int, int, fillProperties, borderProperties);

    void draw() override;

    int getWidth() const;
    int getHeight() const;

    void setWidth(int);
    void setHeight(int);
private:
    int width;
    int height;
};

#endif // RECTANGLE_H
