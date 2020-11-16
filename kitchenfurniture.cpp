#include "kitchenfurniture.h"
using namespace std;
KitchenFurniture::KitchenFurniture(float heightSet, float lengthSet, float widthSet,
                                 float coordZSet, float coordYSet, float coordXSet, string nameSet, string materialSet)
{
    setData(heightSet, lengthSet, widthSet, coordZSet, coordYSet, coordXSet, nameSet, materialSet);
}

void KitchenFurniture::setData(float heightSet, float lengthSet, float widthSet,
                               float coordZSet, float coordYSet, float coordXSet, string nameSet, string materialSet)
{
    if((coordXSet < 0)||(coordYSet<0)||(coordXSet<0)||(heightSet<=0)||(lengthSet<=0)||(widthSet<=0))
        {
            cout<<"\nError! Coordinates must be >=0, gabarites must be>0. Default values are set\n";
            height = 1;
            length = 1;
            width = 1;
            coordZ = 0;
            coordY = 0;
            coordX = 0;
            name = "untitled";
            material = "empty";
        }else{
            height = heightSet;
            length = lengthSet;
            width = widthSet;
            coordZ = coordZSet;
            coordY = coordYSet;
            coordX = coordXSet;
            name = nameSet;
            material = materialSet;
            cout<<"\nObject created.\n";
        }
}

void KitchenFurniture::setHeight(float valueHeight)
{
    if(valueHeight>0)
    {
        height = valueHeight;
    }else
        cout<<"Error! Height must be >0";
}

void KitchenFurniture::setLength(float valueLength)
{
    if(valueLength>0)
    {
        length = valueLength;
    }else
        cout<<"\nError! Lenght must be >0\n";
}

void KitchenFurniture::setWidth(float valueWidth)
{
    if(valueWidth>0)
    {
        width = valueWidth;
    }else
        cout<<"Error! Width must be >0";
}

void KitchenFurniture::setCoordZ(float valueCoordZ)
{
    if(valueCoordZ>=0)
    {
        coordZ = valueCoordZ;
    }else
        cout<<"Error! Z-coordinate must be >=0";
}

void KitchenFurniture::setCoordY(float valueCoordY)
{
    if(valueCoordY>=0)
    {
        coordY = valueCoordY;
    }else
        cout<<"Error! Y-coordinate must be >=0";
}

void KitchenFurniture::setCoordX(float valueCoordX)
{
    if(valueCoordX>=0)
    {
        coordY = valueCoordX;
    }else
        cout<<"\nError! X-coordinate must be >=0";
}

void KitchenFurniture::setName(const string& objectName)
{
    if(objectName!=" ")
    {
        name = objectName;
    }else
        cout<<"\nError! The name can not be empty";
}

void KitchenFurniture::setMaterial(const string &objectMaterial)
{
    if(objectMaterial!=" ")
    {
        material = objectMaterial;
    }else
        cout<<"\nError! The material can not be empty";
}

KitchenFurniture::KitchenFurniture(const KitchenFurniture& i){
    this->height = i.height;
    this->length = i.length;
    this->width = i.width;
    this->coordZ = i.coordZ;
    this->coordY = i.coordY;
    this->coordX = i.coordX;
    this->name = i.name;
    this->material = i.material;
    //cout<<"\nCopy object created\n";

}

KitchenFurniture::KitchenFurniture(){
    this->height = 1;
    this->length = 1;
    this->width = 1;
    this->coordZ = 0;
    this->coordY = 0;
    this->coordX = 0;
    this->name = "untitled";
    this->material = "empty";
    cout<<"\nDefault object is created. Cordinates by default 0,0,0. dimensions 1,1,1 by default.";
}
void KitchenFurniture::showParametres(){
    cout<<"\nName:  "<<this->name<<"\nMaterial:  "<<this->material<<"\nHeight:  "<<this->height<<"\nLength:  "<<this->length<<"\nWidth:  "<<this->width<<"\nThe position on the Z-axis:  "<<this->coordZ<<"\n"<<"The position on the Y-axis:  "
       <<this->coordY<<"\n"<<"The position on the X-axis:  "<<this->coordX<<"\n";
}
