#pragma once
#ifndef PAINT_23
#define PAINT_23

#include "BMPfile.h"
#include "Arry.h"
#include "List.h"
#include "objects.h"
#include <cmath>
#include "BMPpainter.h"

enum Element {
    ET_POINT, ET_SECTION, ET_CIRCLE
};

struct ElementData {
    Element et;
    Arry<double> params;
};

class Paint {
    struct idxPoint {
        ID id;
        List<point>::iterator it;
    };
    struct idxSection {
        ID id;
        List<section>::iterator it;
    };
    struct idxCircle {
        ID id;
        List<circle>::iterator it;
    };

    Arry <idxPoint> m_pointIndex;
    Arry <idxSection> m_sectionIndex;
    Arry <idxCircle> m_circleIndex;
    ID maxID;
    List <point> m_pointStorage;
    List <section> m_sectionStorage;
    List <circle> m_circleStorage;
    BMPpainter filename;

public:
    // Добавление элементов с указанием их типа и необходимого набора параметров
    ID addElement(const ElementData &ed);

    // Получение информации об объекте    
    ElementData getElementInfo(ID id);

    // Сохранение данных в файл
    void saveToFile(const char *filename);

    // Экспорт в BMP файл
    void exportToBMP(const char *file);

    // Загрузка данных из файла
    void loadFromFile(const char *file);

    // Задает фон(изменяет filename файл)
    void changeBMP(const char* file);

    void paint();
};

#endif
