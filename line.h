#ifndef LINE_H
#define LINE_H

#include "nonfillableshape.h"

class Line : public nonfillableShape
{
public:
    Line(const QPoint&, const QPoint&, unsigned int, borderProperties);
    Line(const QPoint&, int, int, unsigned int, borderProperties);

    void draw(QPainter&) override;
    std::string toString() override;
    void moveOffset(QPoint&) override;

    QPoint getStart();
    QPoint getEnd();

    void setStart(const QPoint&);
    void setEnd(const QPoint&);
private:
    QPoint end;
    QString shapeType;
};


#endif // LINE_H
