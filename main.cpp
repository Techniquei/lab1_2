#include <QCoreApplication>
#include <iostream>
#include "kitchenfurniture.h"
#include "array.h"
#include <Windows.h>
#include <cassert>

void vectorShow(Array a){
    for(int i=0; i<a.getSize(); i++){
        cout<<"\nElement #"<<i<<":\n";
        a.indexSearch(i).showParametres();
    }
}


int main()
{
    setlocale(0, "");
  /*KitchenFurniture k1(1, 2, 3, 4, 5, 6, "k1");
    KitchenFurniture k3;
    k3.showParametres();
//проверка конструктора
    assert(k1.getCoordX()==6);
    assert(k1.getCoordY()==5);
    assert(k1.getCoordZ()==4);
    assert(k1.getHeight()==1);
    assert(k1.getLength()==2);
    assert(k1.getWidth()==3);
    assert(k1.getName()=="k1");
//проверка конструктора по умолчанию
    assert(k1.getCoordX()==6);
    assert(k1.getCoordY()==5);
    assert(k1.getCoordZ()==4);
    assert(k1.getHeight()==1);
    assert(k1.getLength()==2);
    assert(k1.getWidth()==3);
//проверка условия ввода длина>0
    k1.setLength(0);
    assert(k1.getLength()==2);
    k1.setLength(25);
    assert(k1.getLength()==25);
//проверка конструктора копирования
    KitchenFurniture k1Copy(k1);
    assert(k1Copy.getLength()==25);
    k1.showParametres();
    k1Copy.showParametres();
    cout<<"Finish";*/

    Array m2(1, 1, 3, 0, 2, 1, "test1", "wood");               //Создание коллекции
    Array m1(1, 1, 1, 0, 0, 0, "name1", "material1");
    KitchenFurniture z=m2.indexSearch(0);                      //Поиск по индексу
    z.showParametres();
    cout<<m2.getSize()<<"\n";
    KitchenFurniture k12(1, 3, 3, 0, 0, 3, "test2", "wood");
    m1.addElement(1, 1, 1, 0, 1, 2, "name2", "material1");     //Проверка добавления(высота, длина, ширина, расположение по высоте, по длине, по ширине, имя, материал)
    m1.addElement(1, 2, 1, 0, 0, 5, "name3", "material2");
    m2.addElement(k12);
    m2.addElement(1, 2, 3, 0, 2, 5, "test3", "wood");
    m2.addElement(1, 3, 1, 0, 3, 2, "test4", "wood");
    m2.addElement(1, 1, 2, 0, 3, 1, "test5", "wood");
    m2.addElement(1, 1, 1, 0, 5, 8, "test6", "metal");
    vectorShow(m2);                                             //Вывод коллекции на экран
    m2.arrayCheckFinder();                                      //Проверка условия задачи
    Array co1;
    Array co2(co1);                                             //Создание копии
    assert(co1.compare(co1,co2)==1);                            //Сравнение копии и оригинала
    assert(co1.compare(co1,m2)==0);                             //Сравнение разных коллекций
    assert(m2.getSize()==6);
    assert(m1.arrayCheckFinder()==1);                           //Проверка условия задачи(условие выполнено)
    assert(m2.arrayCheckFinder()==0);                           //Проверка условия задачи(условие не выполнено)
    m2.deleteElement(2);                                        //Проверка удаления
    assert(m2.getSize()==5);
    m2.toFile();
    cout<<"\n\n-----------------------\nSUCESSFUL COMPLETED\n";
}
