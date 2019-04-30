#ifndef POLYGON_H
#define POLYGON_H

#include "fillableshape.h"
#include "vector.h"

class Polygon : public fillableShape
{
public:
    Polygon(const myStd::vector<QPoint>&, unsigned int, fillProperties, borderProperties);

    void draw(QPainter&) override;

    myStd::vector<QPoint> getPoints() const;

    void setPoints(const myStd::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    myStd::vector<QPoint> points;
};

#endif // POLYGON_H
