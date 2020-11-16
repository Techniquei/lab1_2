#ifndef KITCHENFURNITURE_H
#define KITCHENFURNITURE_H
#include <iostream>
using namespace std;


class KitchenFurniture
{
public:
   KitchenFurniture(float heightSet, float lengthSet, float widthSet,
                    float coordZSet, float coordYSet,float coordXSet, string nameSet, string material);
   KitchenFurniture(const KitchenFurniture& i);
   KitchenFurniture();
   void showParametres();
   void setData(float height, float length, float width,
                float coordZ, float coordY, float coordX, string name, string material);
   void setHeight(float valueHeight);
   float getHeight() const
   {
       return height;
   }
   void setLength(float valueLength);
   float getLength() const
   {
       return length;
   }
   void setWidth(float valueWidth);
   float getWidth() const
   {
       return width;
   }
   void setCoordZ(float valueCoordZ);
   float getCoordZ() const
   {
       return coordZ;
   }
   void setCoordY(float valueCoordY);
   float getCoordY() const
   {
       return coordY;
   }
   void setCoordX(float valueCoordX);
   float getCoordX() const
   {
       return coordX;
   }
   void setName(const string& objectName);
   string getName() const
   {
       return name;
   }
   void setMaterial(const string& objectMaterial);
   string getMaterial() const
   {
       return material;
   }


private:
   float height;
   float length;
   float width;
   float coordZ;
   float coordY;
   float coordX;
   string name;
   string material;
};

#endif // KITCHENFURNITURE_H
