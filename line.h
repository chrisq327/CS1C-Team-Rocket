#ifndef LINE_H
#define LINE_H

#include "nonfillableshape.h"

class Line : public nonfillableShape
{
public:
    Line(const QPoint&, const QPoint&, unsigned int, borderProperties);
    Line(int, int, int, int, unsigned int, borderProperties);

    void draw(QPainter&) override;

    QPoint getStart();
    QPoint getEnd();

    void setStart(const QPoint&);
    void setEnd(const QPoint&);
private:
    QPoint start;
    QPoint end;
};


#endif // LINE_H
