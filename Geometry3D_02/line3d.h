//
//  line3d.h
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef line3d_h
#define line3d_h

#include <stdio.h>
#include "point3d.h"
#include "vector3d.h"


typedef struct Line3DTwoPoints {
    // p != q
    Point *p;
    Point *q;
} LinePP;

typedef struct Line3DPointVector {
    Point *p;
    Vector *v;
} LinePV;


bool lineIsPointOnLine(LinePP *line, Point *p);
LinePP *lineByPoints(const Point* p, const Point *q);
void freeLinePP(LinePP **line);
#endif /* line3d_h */
