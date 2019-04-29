#ifndef POLYLINE_H
#define POLYLINE_H

#include "nonfillableshape.h"
#include "vector.h"

class Polyline : public nonfillableShape
{
public:
    Polyline(myStd::vector<QPoint>, borderProperties);

    void draw() override;

    myStd::vector<QPoint> getPoints() const;

    void setPoints(const myStd::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    myStd::vector<QPoint> points;
};s

#endif // POLYLINE_H
