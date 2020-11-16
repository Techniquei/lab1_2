#ifndef ARRAY_H
#define ARRAY_H
#include "kitchenfurniture.h"
#include <vector>

class Array
{
private:
    vector<KitchenFurniture> array;
    int size;
public:
    Array();
    ~Array() {
        array.clear();
    };
    Array(float heightSet, float lengthSet, float widthSet,
          float coordZSet, float coordYSet,float coordXSet, string nameSet, string materialSet);
    Array(const Array& A);
    void addElement(KitchenFurniture i);
    void addElement(float heightSet, float lengthSet, float widthSet,
               float coordZSet, float coordYSet,float coordXSet, string nameSet, string materialSet);
    void deleteElement(int index);
    void cleanVector();
    int getSize();
    vector<KitchenFurniture> getVector();
    KitchenFurniture indexSearch(int index);
    bool arrayCheckFinder();
    bool compare(Array arr1, Array arr2);
    int toFile();
    int intoFile();
};

#endif // ARRAY_H
