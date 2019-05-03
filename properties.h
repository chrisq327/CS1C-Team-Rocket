#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QPainter>
#include <QPen>
#include <QFont>
#include <QBrush>

struct borderProperties
{
    Qt::GlobalColor penColor = Qt::GlobalColor::black;
    int penWidth = 5;
    Qt::PenStyle penStyle = Qt::PenStyle::DashDotLine; //Was no pen before?
    Qt::PenCapStyle penCapStyle = Qt::PenCapStyle::FlatCap;
    Qt::PenJoinStyle penJoinStyle = Qt::PenJoinStyle::MiterJoin;
};

struct fillProperties
{
    Qt::GlobalColor brushColor = Qt::GlobalColor::black;
    Qt::BrushStyle brushStyle = Qt::BrushStyle::NoBrush;
};

struct textProperties
{
    Qt::GlobalColor textColor = Qt::GlobalColor::black;
    Qt::AlignmentFlag textAlignment = Qt::AlignmentFlag::AlignLeft;
    int textSize = 0;
    QString textFont = "Times New Roman";
    QFont::Style textFontStyle = QFont::Style::StyleNormal;
    QFont::Weight textFontWeight = QFont::Weight::Normal;
};


#endif // PROPERTIES_H
