#ifndef POLYLINE_H
#define POLYLINE_H

#include "nonfillableshape.h"
#include "vector.h"

class Polyline : public nonfillableShape
{
public:
    Polyline(const myStd::vector<QPoint>&, unsigned int, borderProperties);

    void draw(QPainter&) override;
    std::string toString() override;

    myStd::vector<QPoint> getPoints() const;

    void setPoints(const myStd::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    myStd::vector<QPoint> points;
};

#endif // POLYLINE_H
