#include "parser.h"

/*! @file parser.cpp
 *  @verbinclude parser.cpp
 */

/*  Functions */


/**
 * @brief Parser function to read in shapes from the file shapes.txt
 * @param ourShapes a pointer to a vector of pointers that derive from the shape class
 */
void parser(myStd::vector<Shape*> *ourShapes)
{
	ifstream inFile;
	enum ShapeType{line, polyline, polygon, rectangle, square, ellipse, circle, text};


	inFile.open("shapes.txt");
	if(!inFile)
	{
		cout << "problem opening input file";
	}

	int id;
	int d1, d2, d3, d4, d5, d6, d7, d8;
	string penColor;
	int penWidth;
	string penStyle;
	string penCapStyle;
	string penJoinStyle;
	string brushColor;
	string brushStyle;

	string textString;
	string textColor;
	string textAlign;
	int textSize;
	string textFontFamily;
	string textFontStyle;
	string textFontWeight;

	string shapeType;
	string trash;
	int enumPos;
	char eater;

    while(inFile >> trash)
	{



        //inFile >> trash;
		inFile >> id;
		inFile >> trash;
		inFile >> shapeType;

		enumPos = convert(shapeType);

		switch(enumPos){
			case 0 :
			case 1 :
			{
				if(enumPos == 0)
				{
					inFile >> trash;
					inFile >> d1;
					inFile >> eater;
					inFile >> d2;
					inFile >> eater;
					inFile >> d3;
					inFile >> eater;
					inFile >> d4;
				}
				else
				{
					inFile >> trash;
					inFile >> d1;
					inFile >> eater;
					inFile >> d2;
					inFile >> eater;
					inFile >> d3;
					inFile >> eater;
					inFile >> d4;
					inFile >> eater;
					inFile >> d5;
					inFile >> eater;
					inFile >> d6;
					inFile >> eater;
					inFile >> d7;
					inFile >> eater;
					inFile >> d8;
				}

				inFile >> trash;
				inFile >> penColor;
				inFile >> trash;
				inFile >> penWidth;
				inFile >> trash;
				inFile >> penStyle;
				inFile >> trash;
				inFile >> penCapStyle;
				inFile >> trash;
				inFile >> penJoinStyle;

				break;
			}
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			{
				if(enumPos == 2)
				{
					inFile >> trash;
					inFile >> d1;
					inFile >> eater;
					inFile >> d2;
					inFile >> eater;
					inFile >> d3;
					inFile >> eater;
					inFile >> d4;
					inFile >> eater;
					inFile >> d5;
					inFile >> eater;
					inFile >> d6;
					inFile >> eater;
					inFile >> d7;
					inFile >> eater;
					inFile >> d8;
				}
				else if (enumPos == 5 || enumPos == 3)
				{
					inFile >> trash;
					inFile >> d1;
					inFile >> eater;
					inFile >> d2;
					inFile >> eater;
					inFile >> d3;
					inFile >> eater;
					inFile >> d4;
				}
				else
				{
					inFile >> trash;
					inFile >> d1;
					inFile >> eater;
					inFile >> d2;
					inFile >> eater;
					inFile >> d3;
				}
				inFile >> trash;
				inFile >> penColor;
				inFile >> trash;
				inFile >> penWidth;
				inFile >> trash;
				inFile >> penStyle;
				inFile >> trash;
				inFile >> penCapStyle;
				inFile >> trash;
				inFile >> penJoinStyle;
				inFile >> trash;
				inFile >> brushColor;
				inFile >> trash;
				inFile >> brushStyle;

				break;
			}
			case 7:
			{
				inFile >> trash;
				inFile >> d1;
				inFile >> eater;
				inFile >> d2;
				inFile >> eater;
				inFile >> d3;
				inFile >> eater;
				inFile >> d4;


				inFile >> trash;
				inFile.ignore(1, ' ');
				getline(inFile, textString);



				inFile >> trash;
				inFile >> textColor;
				inFile >> trash;
				inFile >> textAlign;
				inFile >> trash;
				inFile >> textSize;
				inFile >> trash;
				inFile.ignore(1, ' ');
				getline(inFile, textFontFamily);
				inFile >> trash;
				inFile >> textFontStyle;
				inFile >> trash;
				inFile >> textFontWeight;

				break;
			}

			default:
				break;
		}

        if(enumPos == 0)
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            QPoint p1(d1, d2);
            QPoint p2(d3, d4);

            Shape *newLine = new Line(p1, p2, id, bProp);
            ourShapes->push_back(newLine);
        }
        else if(enumPos == 1)
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            QPoint p1(d1, d2);
            QPoint p2(d3, d4);
            QPoint p3(d5, d6);
            QPoint p4(d7, d8);

            std::vector<QPoint> *polylinePoints = new std::vector<QPoint>;
            polylinePoints->push_back(p1);
            polylinePoints->push_back(p2);
            polylinePoints->push_back(p3);
            polylinePoints->push_back(p4);

            Shape *newPolyline = new class Polyline(*polylinePoints, id, bProp);
            ourShapes->push_back(newPolyline);
        }
        else if(enumPos == 2)
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            fillProperties fProp;

            setBrushColor(fProp, brushColor);
            setBrushStyle(fProp, brushStyle);

            QPoint p1(d1, d2);
            QPoint p2(d3, d4);
            QPoint p3(d5, d6);
            QPoint p4(d7, d8);

            std::vector<QPoint> *polygonPoints = new std::vector<QPoint>;
            polygonPoints->push_back(p1);
            polygonPoints->push_back(p2);
            polygonPoints->push_back(p3);
            polygonPoints->push_back(p4);

            Shape *newPolygon = new class Polygon(*polygonPoints, id, fProp, bProp);
            ourShapes->push_back(newPolygon);
        }
        else if(enumPos == 3 )
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            fillProperties fProp;

            setBrushColor(fProp, brushColor);
            setBrushStyle(fProp, brushStyle);

            QPoint p1(d1, d2);

            Shape *newRectangle = new class Rectangle(p1, d3, d4, id, fProp, bProp);
            ourShapes->push_back(newRectangle);
        }
        else if(enumPos == 4)
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            fillProperties fProp;

            setBrushColor(fProp, brushColor);
            setBrushStyle(fProp, brushStyle);

            QPoint p1(d1, d2);

            Shape *newSquare = new class Rectangle(p1, d3, d3, id, fProp, bProp);
            ourShapes->push_back(newSquare);
        }
        else if(enumPos == 5)
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            fillProperties fProp;

            setBrushColor(fProp, brushColor);
            setBrushStyle(fProp, brushStyle);

            QPoint p1(d1, d2);

            Shape *newEllipse = new class Ellipse(p1, d3, d4, id, fProp, bProp);
            ourShapes->push_back(newEllipse);
        }
        else if (enumPos == 6)
        {
            borderProperties bProp;

            setPenColor(bProp, penColor);
            bProp.penWidth = penWidth;
            setPenStyle(bProp, penStyle);
            setPenCapStyle(bProp, penCapStyle);
            setPenJoinStlye(bProp, penJoinStyle);

            fillProperties fProp;

            setBrushColor(fProp, brushColor);
            setBrushStyle(fProp, brushStyle);

            QPoint p1(d1, d2);

            Shape *newCircle = new class Ellipse(p1, d3, d3, id, fProp, bProp);
            ourShapes->push_back(newCircle);
        }
        else if(enumPos == 7)
        {
            textProperties tProp;

            setTextColor(tProp, textColor);
            setTextAlignment(tProp, textAlign);
            tProp.textSize = textSize;
            tProp.textFontFamily = QString::fromStdString(textFontFamily);
            setTextStyle(tProp, textFontStyle);
            setTextWeight(tProp, textFontWeight);

            QString qTextString = QString::fromStdString(textString);
            QPoint p1(d1, d2);
            Shape *newText = new Text(p1, d3, d4, id, qTextString, tProp);
            ourShapes->push_back(newText);
        }
		cout << endl;
    }
	inFile.close();
}


/**
 * @brief Convert function converts shapeType to a number for the enum
 * @param s shapeType string
 * @return number for enum shape type
 */
int convert(string s)
{

	if(s == "Line")
		return 0;
	else if(s == "Polyline")
			return 1;
	else if(s == "Polygon")
			return 2;
	else if(s == "Rectangle")
			return 3;
	else if(s == "Square")
			return 4;
	else if(s == "Ellipse")
			return 5;
	else if(s == "Circle")
			return 6;
	else
		return 7;
}

/**
 * @brief setPenColor converts the string color to change the pen color in borderProperties
 * @param bProp borderProperties holds the properties for borders
 * @param penColor string that is the color of the pen
 */
void setPenColor(borderProperties &bProp, string penColor)
{
    if(penColor == "white")
    {
        bProp.penColor = Qt::GlobalColor::white;
    }
    else if(penColor == "black")
    {
        bProp.penColor = Qt::GlobalColor::black;
    }
    else if(penColor == "red")
    {
        bProp.penColor = Qt::GlobalColor::red;
    }
    else if(penColor == "green")
    {
        bProp.penColor = Qt::GlobalColor::green;
    }
    else if(penColor == "blue")
    {
        bProp.penColor = Qt::GlobalColor::blue;
    }
    else if(penColor == "cyan")
    {
        bProp.penColor = Qt::GlobalColor::cyan;
    }
    else if(penColor == "magenta")
    {
        bProp.penColor = Qt::GlobalColor::magenta;
    }
    else if(penColor == "yellow")
    {
        bProp.penColor = Qt::GlobalColor::yellow;
    }
    else if(penColor == "gray")
    {
        bProp.penColor = Qt::GlobalColor::gray;
    }

}

/**
 * @brief setPenStyle converts the string style to change the pen style in borderProperties
 * @param bProp borderProperties holds the properties for borders
 * @param penStyle string that is the style of the pen
 */
void setPenStyle(borderProperties &bProp, string penStyle)
{
    if(penStyle == "NoPen")
    {
        bProp.penStyle = Qt::PenStyle::NoPen;
    }
    else if(penStyle == "SolidLine")
    {
        bProp.penStyle = Qt::PenStyle::SolidLine;
    }
    else if(penStyle == "DashLine")
    {
        bProp.penStyle = Qt::PenStyle::DashLine;
    }
    else if(penStyle == "DotLine")
    {
        bProp.penStyle = Qt::PenStyle::DotLine;
    }
    else if(penStyle == "DashDotLine")
    {
        bProp.penStyle = Qt::PenStyle::DashDotLine;
    }
    else if(penStyle == "DashDotDotLine")
    {
        bProp.penStyle = Qt::PenStyle::DashDotDotLine;
    }

}

/**
 * @brief setPenCapStyle converts the string cap to change the pen cap style in borderProperties
 * @param bProp borderProperties holds the properties for borders
 * @param penCap string that is the cap style of pen
 */
void setPenCapStyle(borderProperties &bProp, string penCap)
{
    if(penCap == "FlatCap")
    {
        bProp.penCapStyle = Qt::PenCapStyle::FlatCap;
    }
    else if(penCap == "SquareCap")
    {
        bProp.penCapStyle = Qt::PenCapStyle::SquareCap;
    }
    else if(penCap == "RoundCap")
    {
        bProp.penCapStyle = Qt::PenCapStyle::RoundCap;
    }


}

/**
 * @brief setPenJoinStlye converts the string join style to change the pen join stlye in borderProperties
 * @param bProp borderProperties holds the properties for borders
 * @param joinStyle string that is the join style of the pen
 */
void setPenJoinStlye(borderProperties &bProp, string joinStyle)
{
    if(joinStyle == "MiterJoin")
    {
        bProp.penJoinStyle = Qt::PenJoinStyle::MiterJoin;
    }
    else if(joinStyle == "BevelJoin")
    {
        bProp.penJoinStyle = Qt::PenJoinStyle::BevelJoin;
    }
    else if(joinStyle == "RoundJoin")
    {
        bProp.penJoinStyle = Qt::PenJoinStyle::RoundJoin;
    }
}

/**
 * @brief setBrushColor converst the string brush color to change the brush color in fillProperties
 * @param fProp fillProperties holds the properties for filling shapes
 * @param brushColor string that is the color of the brush
 */
void setBrushColor(fillProperties &fProp, string brushColor)
{
    if(brushColor == "white")
    {
        fProp.brushColor = Qt::GlobalColor::white;
    }
    else if(brushColor == "black")
    {
        fProp.brushColor = Qt::GlobalColor::black;
    }
    else if(brushColor == "red")
    {
        fProp.brushColor = Qt::GlobalColor::red;
    }
    else if(brushColor == "green")
    {
        fProp.brushColor = Qt::GlobalColor::green;
    }
    else if(brushColor == "blue")
    {
        fProp.brushColor = Qt::GlobalColor::blue;
    }
    else if(brushColor == "cyan")
    {
        fProp.brushColor = Qt::GlobalColor::cyan;
    }
    else if(brushColor == "magenta")
    {
        fProp.brushColor = Qt::GlobalColor::magenta;
    }
    else if(brushColor == "yellow")
    {
        fProp.brushColor = Qt::GlobalColor::yellow;
    }
    else if(brushColor == "gray")
    {
        fProp.brushColor = Qt::GlobalColor::gray;
    }
}

/**
 * @brief setBrushStyle converts the string brush style to change the brush style in fillProperites
 * @param fProp fillProperties holds the properties for filling shapes
 * @param brushStyle string that is the brush style
 */
void setBrushStyle(fillProperties &fProp, string brushStyle)
{
    if(brushStyle == "SolidPattern")
    {
        fProp.brushStyle = Qt::BrushStyle::SolidPattern;
    }
    else if(brushStyle == "HorPattern")
    {
        fProp.brushStyle = Qt::BrushStyle::HorPattern;
    }
    else if(brushStyle == "VerPattern")
    {
        fProp.brushStyle = Qt::BrushStyle::VerPattern;
    }
    else if(brushStyle == "NoBrush")
    {
        fProp.brushStyle = Qt::BrushStyle::NoBrush;
    }
}

/**
 * @brief setTextColor converts the string text color to change the color of changes in textproperties
 * @param tProp textProperties holds the properties for text
 * @param textColor string that is the color of the text
 */
void setTextColor(textProperties &tProp, string textColor)
{
    if(textColor == "white")
    {
        tProp.textColor = Qt::GlobalColor::white;
    }
    else if(textColor == "black")
    {
        tProp.textColor = Qt::GlobalColor::black;
    }
    else if(textColor == "red")
    {
        tProp.textColor = Qt::GlobalColor::red;
    }
    else if(textColor == "green")
    {
        tProp.textColor = Qt::GlobalColor::green;
    }
    else if(textColor == "blue")
    {
        tProp.textColor = Qt::GlobalColor::blue;
    }
    else if(textColor == "cyan")
    {
        tProp.textColor = Qt::GlobalColor::cyan;
    }
    else if(textColor == "magenta")
    {
        tProp.textColor = Qt::GlobalColor::magenta;
    }
    else if(textColor == "yellow")
    {
        tProp.textColor = Qt::GlobalColor::yellow;
    }
    else if(textColor == "gray")
    {
        tProp.textColor = Qt::GlobalColor::gray;
    }
}

/**
 * @brief setTextAlignment convert the string text align to change the text alignment in textProperties
 * @param tProp textProperties holds the properties for text
 * @param textAlign string that is the text alignment
 */
void setTextAlignment(textProperties &tProp, string textAlign)
{
    if(textAlign == "AlignLeft")
    {
        tProp.textAlignment = Qt::AlignmentFlag::AlignLeft;
    }
    else if(textAlign == "AlignRight")
    {
        tProp.textAlignment = Qt::AlignmentFlag::AlignRight;
    }
    else if(textAlign == "AlrightTop")
    {
        tProp.textAlignment = Qt::AlignmentFlag::AlignTop;
    }
    else if(textAlign == "AlignBottom")
    {
        tProp.textAlignment = Qt::AlignmentFlag::AlignBottom;
    }
    else if(textAlign == "AlignCenter")
    {
        tProp.textAlignment = Qt::AlignmentFlag::AlignCenter;
    }
}

/**
 * @brief setTextFontFamily converts the string text font family to change the font family in textProperties
 * @param tProp textProperties holds the properties for text
 * @param textFont string that is the text font family.
 */
void setTextFontFamily(textProperties &tProp, string textFont)
{
    if(textFont == "Comic Sans MS")
    {
        tProp.textFontFamily = "Comic Sans MS";
    }
    else if(textFont == "Courier")
    {
        tProp.textFontFamily = "Courier";
    }
    else if (textFont == "Helvetica")
    {
        tProp.textFontFamily = "Helvetica";
    }
    else if(textFont == "Times New Roman")
    {
        tProp.textFontFamily = "Times New Roman";
    }
}

/**
 * @brief setTextStyle converts the string to change the font style in textProperties
 * @param tProp textProperties holds the properties for text
 * @param textStyle string that is the text style
 */
void setTextStyle(textProperties &tProp, string textStyle)
{
    if(textStyle == "StyleNormal")
    {
        tProp.textFontStyle = QFont::Style::StyleNormal;
    }
    else if(textStyle == "StyleItalic")
    {
        tProp.textFontStyle = QFont::Style::StyleItalic;
    }
    else if(textStyle == "StyleOblique")
    {
        tProp.textFontStyle = QFont::Style::StyleOblique;
    }
}

/**
 * @brief setTextWeight converts the string text weight to change the text weight in textProperites
 * @param tProp textProperties holds the properties for text
 * @param textWeight string that is the text weight
 */
void setTextWeight(textProperties &tProp, string textWeight)
{
    if(textWeight == "Thin")
    {
        tProp.textFontWeight = QFont::Weight::Thin;
    }
    else if(textWeight == "Light")
    {
        tProp.textFontWeight = QFont::Weight::Light;
    }
    else if(textWeight == "Normal")
    {
        tProp.textFontWeight = QFont::Weight::Normal;
    }
    else if(textWeight == "Bold")
    {
        tProp.textFontWeight = QFont::Weight::Bold;
    }
}

/**
 * @brief fileSave out puts the vector of pointers of shapes to save it into the original text file
 * @param ourShapes pointer to a vector of pointers of shapes that derive from the shape base class
 */
void fileSave(myStd::vector<Shape*> *ourShapes)
{
    ofstream outFile;
    outFile.open("shapes.txt");
    for(int i = 0; i < ourShapes->size(); i++)
    {
        outFile << (*ourShapes)[i]->toString();
        outFile << endl;
    }
    outFile.close();
}


