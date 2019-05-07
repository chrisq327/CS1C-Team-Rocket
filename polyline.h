#ifndef POLYLINE_H
#define POLYLINE_H

#include "nonfillableshape.h"
#include "vector.h"

class Polyline : public nonfillableShape
{
public:
    Polyline(const std::vector<QPoint>&, unsigned int, borderProperties);


    void draw(QPainter&) override;
    std::string toString() override;

    std::vector<QPoint> getPoints() const;

    void setPoints(const std::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    std::vector<QPoint> points;
};

#endif // POLYLINE_H
