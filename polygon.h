#ifndef POLYGON_H
#define POLYGON_H

#include "fillableshape.h"
#include "vector.h"

class Polygon : public fillableShape
{
public:
    Polygon(const std::vector<QPoint>&, unsigned int, fillProperties, borderProperties);

    void draw(QPainter&) override;
    std::string toString() override;
    void moveOffset(QPoint&) override;

    std::vector<QPoint> getPoints() const;

    void setPoints(const std::vector<QPoint>&);

    void addPoint(const QPoint&);
private:
    std::vector<QPoint> points; //used an std::vector because using myStd::vector created several issues and segfaults
};

#endif // POLYGON_H
