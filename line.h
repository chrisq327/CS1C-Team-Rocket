#ifndef LINE_H
#define LINE_H

#include "nonfillableshape.h"

class Line : public nonfillableShape
{
public:
    Line(QPoint, QPoint, borderProperties);
    Line(int, int, int, int);

    void draw() override;

    QPoint getStart();
    QPoint getEnd();

    void setStart(QPoint);
    void setEnd(QPoint);
private:
    QPoint start;
    QPoint end;
};


#endif // LINE_H
