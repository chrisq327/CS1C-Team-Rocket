

//using namespace myStd;

#include "parser.h"



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







