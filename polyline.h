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
    void moveOffset(QPoint&) override;

    std::vector<QPoint> getPoints() const;

    void setPoints(const std::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    std::vector<QPoint> points; //used an std::vector because using myStd::vector created several issues and segfaults
};

#endif // POLYLINE_H
