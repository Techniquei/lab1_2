#include "array.h"
#include "kitchenfurniture.h"
#include <vector>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Array::Array()
{
this->array.push_back(KitchenFurniture());
this->size = 1;
vector<KitchenFurniture> A;
}

Array::Array(float heightSet, float lengthSet, float widthSet,
             float coordZSet, float coordYSet, float coordXSet,
             string nameSet, string materialSet)
{
this->array.push_back(KitchenFurniture(heightSet, lengthSet, widthSet,
                      coordZSet, coordYSet, coordXSet, nameSet, materialSet));
this->size = 1;
vector<KitchenFurniture> A;
}

Array::Array(const Array& Q) {
this->array = Q.array;
this->size = Q.size;
vector<KitchenFurniture> A;
}

void Array::addElement(KitchenFurniture i) {
    this->size++;
    this->array.push_back(i);
}

void Array::addElement(float heightSet, float lengthSet, float widthSet,
                  float coordZSet, float coordYSet,float coordXSet, string nameSet, string materialSet){
    this->size++;
    this->array.push_back(KitchenFurniture(heightSet, lengthSet, widthSet,
                                           coordZSet, coordYSet, coordXSet, nameSet, materialSet));
}

void Array::deleteElement(int index) {
    if((index<this->size)&&(index>-1)) {
        this->size--;
        this->array.erase(this->array.begin()+index);
    }
}

void Array::cleanVector() {
    this->array.clear();
    this->size = 0;
}

int Array::getSize() {
    return this->size;
}

vector<KitchenFurniture> Array::getVector() {
    return this->array;
}

KitchenFurniture Array::indexSearch(int index) {
    return this->array[index];
}

bool Array::arrayCheckFinder() {
    cout<<"\n\nCHECK STARTED";
    int counter=0;
    for(int i=0; i<this->size; i++) {
        for(int j=i; j<this->size; j++) {
            cout<<"\n: "<<i<<j;
            if(this->indexSearch(j).getMaterial()==this->indexSearch(i).getMaterial()){

                if(((((this->indexSearch(j).getCoordX()-this->indexSearch(i).getCoordX()-
                       this->indexSearch(i).getWidth())<0)&&
                        ((this->indexSearch(j).getCoordY()>(this->indexSearch(i).getCoordY()-
                                                        this->indexSearch(j).getLength()))&&
                         (this->indexSearch(j).getCoordY()<(this->indexSearch(i).getCoordY()+
                                                        this->indexSearch(i).getLength())))&&
                        (this->indexSearch(j).getCoordX()>=this->indexSearch(i).getCoordX()))||
                        (((this->indexSearch(j).getCoordY()-this->indexSearch(i).getCoordY()-
                           this->indexSearch(i).getLength())<0)&&
                        ((this->indexSearch(j).getCoordX()>(this->indexSearch(i).getCoordX()-
                                                        this->indexSearch(j).getWidth()))&&
                         (this->indexSearch(j).getCoordX()<(this->indexSearch(i).getCoordX()+
                                                        this->indexSearch(i).getWidth())))&&
                         this->indexSearch(j).getCoordY()>=this->indexSearch(i).getCoordY()))&&(i!=j)){
                            counter++;
                            cout<<"\n\nError #"<<counter<<" with objects same material:\n";
                            this->indexSearch(i).showParametres();
                            this->indexSearch(j).showParametres();
            }

            }else{
            if(((((this->indexSearch(j).getCoordX()-this->indexSearch(i).getCoordX()-
                   this->indexSearch(i).getWidth()-2)<0)&&
                    ((this->indexSearch(j).getCoordY()>(this->indexSearch(i).getCoordY()-
                                                    this->indexSearch(j).getLength()-2))&&
                     (this->indexSearch(j).getCoordY()<(this->indexSearch(i).getCoordY()+
                                                    this->indexSearch(i).getLength()+2)))&&
                    (this->indexSearch(j).getCoordX()>=this->indexSearch(i).getCoordX()))||
                    (((this->indexSearch(j).getCoordY()-this->indexSearch(i).getCoordY()-
                       this->indexSearch(i).getLength()-2)<0)&&
                    ((this->indexSearch(j).getCoordX()>(this->indexSearch(i).getCoordX()-
                                                    this->indexSearch(j).getWidth()-2))&&
                     (this->indexSearch(j).getCoordX()<(this->indexSearch(i).getCoordX()+
                                                    this->indexSearch(i).getWidth()+2)))&&
                     this->indexSearch(j).getCoordY()>=this->indexSearch(i).getCoordY()))&&(i!=j)){
                        counter++;
                        cout<<"\n\nError #"<<counter<<" with objects  with different material:\n";
                        this->indexSearch(i).showParametres();
                        this->indexSearch(j).showParametres();

                }
            }
        }
    }
    cout<<"\n\nCHECK FINISHED\n";
    if(counter>0){
        return false;
    }else
        return true;
}

bool Array::compare(Array arr1, Array arr2) {
    if ((arr1.getSize()==arr2.getSize())) {
        int n = 0;
        for(int i=0; i<arr1.getSize(); i++) {
            if((arr1.indexSearch(i).getCoordX()==arr2.indexSearch(i).getCoordX())&&
                    (arr1.indexSearch(i).getCoordY()==arr2.indexSearch(i).getCoordY())&&
                    (arr1.indexSearch(i).getCoordZ()==arr2.indexSearch(i).getCoordZ())&&
                    (arr1.indexSearch(i).getLength()==arr2.indexSearch(i).getLength())&&
                    (arr1.indexSearch(i).getHeight()==arr2.indexSearch(i).getHeight())&&
                    (arr1.indexSearch(i).getWidth()==arr2.indexSearch(i).getWidth())&&
                    (arr1.indexSearch(i).getName()==arr2.indexSearch(i).getName())&&
                    (arr1.indexSearch(i).getMaterial()==arr2.indexSearch(i).getMaterial())){
                n++;
            }
        }
        if(n==arr1.getSize()) {
            return true;
        }else
            return false;

    }else
        return false;
}

int Array::toFile()
{
    QJsonArray array_j; // создаем массив Json обьектов

    for (int i=0; i<this->size; i++)
    {
        QString name = QString::fromUtf8(this->array[i].getName().c_str());
        QString material = QString::fromUtf8(this->array[i].getMaterial().c_str());
        QJsonObject obj {
            {"name", name},
            {"material", material},
            {"coord z", this->array[i].getCoordZ()},
            {"coord y", this->array[i].getCoordY()},
            {"coord x", this->array[i].getCoordX()},
            {"height", this->array[i].getHeight()},
            {"length", this->array[i].getLength()},
            {"width", this->array[i].getWidth()},
        };
        array_j.append(obj);
    }
    QJsonDocument stack_doc(array_j);
    ofstream out("D:/lab_out.txt");
    if (out.is_open())
    {
        out << stack_doc.toJson().toStdString() << endl;
    }
    out.close();
    return 0;
}





