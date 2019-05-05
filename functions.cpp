#include "functions.h"

void addShape(vector<Shape*> *ourShapes)
{

}

void removeShape(vector<Shape*> &ourShapes)
{
    //get ID of shape to be removed
    int ID = 0;

    for (int i=0; i<ourShapes.size(); i++)
    {
        if (ourShapes[i]->getId() == ID)
        {
            delete ourShapes[i];
            ourShapes[i] = nullptr;
        }
    }

}

void moveShape(vector<Shape*> &ourShapes)
{
    //get id of shape to be moved
    int ID = 0;

    //get new coordinates
    QPoint newTopL;


    for (int i=0; i<ourShapes.size(); i++)
    {
        if (ourShapes[i]->getId() == ID)
        {
            ourShapes[i]->setPosition(newTopL);
        }
    }
}
