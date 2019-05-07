#ifndef PARSER_H_
#define PARSER_H_


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vector.h"
#include "properties.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "ellipse.h"
#include "text.h"




using namespace std;

void parser(myStd::vector<Shape*> *ourShape);
int convert(string shapeType);

void setPenColor(borderProperties &bProp, string color);
void setPenStyle(borderProperties &bProp, string penStyle);
void setPenCapStyle(borderProperties &bProp, string penCap);
void setPenJoinStlye(borderProperties &bProp, string joinStyle);

void setBrushColor(fillProperties &fProp, string color);
void setBrushStyle(fillProperties &fProp, string brushStyle);

void setTextColor(textProperties &tProp, string textColor);
void setTextAlignment(textProperties &tProp, string textAlign);
void setTextFontFamily(textProperties &tProp, string textFont);
void setTextStyle(textProperties &tProp, string textStyle);
void setTextWeight(textProperties &tProp, string textWeight);

void fileSave(myStd::vector<Shape*> *ourShapes);

#endif /* PARSER_H_ */
