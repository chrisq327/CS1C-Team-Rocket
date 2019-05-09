#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "fillableshape.h"

class Rectangle : public fillableShape //a square is a rectangle
{
public:
    Rectangle(const QPoint&, const QPoint&, unsigned int, fillProperties, borderProperties);
    Rectangle(const QPoint&, int, int, unsigned int, fillProperties, borderProperties);

    void draw(QPainter&) override;
    std::string toString() override;
    void moveOffset(QPoint&) override;

    int getWidth() const;
    int getHeight() const;

    void setWidth(int);
    void setHeight(int);
private:
    int width;
    int height;
};

#endif // RECTANGLE_H
