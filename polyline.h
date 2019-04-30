#ifndef POLYLINE_H
#define POLYLINE_H

#include "nonfillableshape.h"
#include "vector.h"

class Polyline : public nonfillableShape
{
public:
    Polyline(myStd::vector<QPoint>, borderProperties);

    void draw(QPainter&) override;

    myStd::vector<QPoint> getPoints() const;

    void setPoints(const myStd::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    myStd::vector<QPoint> points;
};

#endif // POLYLINE_H
