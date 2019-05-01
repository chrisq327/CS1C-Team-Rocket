

//using namespace myStd;

#include "parser.h"
#include "properties.h"
#include "line.h"

void setPenColor(borderProperties &bProp, string color);
void setPenStyle(borderProperties &bProp, string penStyle);
void setPenCapStyle(borderProperties &bProp, string penCap);
void setPenJoinStlye(borderProperties &bProp, string joinStyle);

void setBrushColor(fillProperties &fProp, string color);
void setBrushStyle(fillProperties &fProp, string brushStyle);

void setTextColor(textProperties &tProp, string textColor);
void setTextAlignment(textProperties &tProp, string textAlign);
void setTextStyle(textProperties &tProp, string textStyle);
void setTextWeight(textProperties &tProp, string textWeight);


void parser()
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

	while(!(inFile.eof()))
	{

		inFile >> trash;
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

		if(enumPos == 7)
			{
				cout << id << endl;
				cout << shapeType << endl;
				cout << d1 << ", " << d2 << ", " << d3 << ", " << d4 << endl;
				cout << textString << endl;
				cout << textColor << endl;
				cout << textAlign << endl;
				cout << textSize << endl;
				cout << textFontFamily << endl;
				cout << textFontStyle << endl;
				cout << textFontWeight << endl;
			}
			else if(enumPos == 1)
			{
				cout << id << endl;
				cout << shapeType << endl;
				cout << d1 << ", " << d2 << ", " << d3 << ", " << d4 <<
						d5 << ", " << d6 << ", " << d7 << ", " << d8 << endl;
				cout << penColor << endl;
				cout << penWidth << endl;
				cout << penStyle << endl;
				cout << penCapStyle << endl;
				cout << penJoinStyle << endl;

			}
			else if(enumPos > 1 && enumPos < 3)
			{
				cout << id << endl;
				cout << shapeType << endl;
				cout << d1 << ", " << d2 << ", " << d3 << ", " << d4 <<
						d5 << ", " << d6 << ", " << d7 << ", " << d8 << endl;
				cout << penColor << endl;
				cout << penWidth << endl;
				cout << penStyle << endl;
				cout << penCapStyle << endl;
				cout << penJoinStyle << endl;
				cout << brushColor << endl;
				cout << brushStyle << endl;
			}
			else if(enumPos == 4 || enumPos == 6)
			{
				cout << id << endl;
				cout << shapeType << endl;
				cout << d1 << ", " << d2 << ", " << d3 << endl;
				cout << penColor << endl;
				cout << penWidth << endl;
				cout << penStyle << endl;
				cout << penCapStyle << endl;
				cout << penJoinStyle << endl;
				cout << brushColor << endl;
				cout << brushStyle << endl;
			}
			else
			{
				cout << id << endl;
				cout << shapeType << endl;
				cout << d1 << ", " << d2 << ", " << d3 << ", " << d4 << endl;
				cout << penColor << endl;
				cout << penWidth << endl;
				cout << penStyle << endl;
				cout << penCapStyle << endl;
				cout << penJoinStyle << endl;
				cout << brushColor << endl;
				cout << brushStyle << endl;
			}
		cout << endl;
	}
	inFile.close();
	//vector<shape> shapes(8);

}



int convert(string s)
{
	//enum ShapeType{line, polyline, polygon, rectangle, square, ellipse, circle, text};

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
        bProp.penColor = Qt::GlobalColor::black;
    }

}
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
        fProp.brushColor = Qt::GlobalColor::black;
    }
}
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
        tProp.textColor = Qt::GlobalColor::black;
    }
}
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




