//
//  triangle3D.h
//  Geometry3D_02
//
//  Created by Иван Милаев on 21/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef triangle3D_h
#define triangle3D_h

#include <stdio.h>
#include "point3d.h"
#include "vector3d.h"
#include "plane3d.h"

typedef struct Triangle3D {
    Point *a;
    Point *b;
    Point *c;
} Triangle;

Triangle *triangleByPoints(Point *a, Point*b, Point *c);
Plane *trianglePlane(Triangle *triangle);
Vector *triangleGetNormal(Triangle *triangle);
float trianglePerimeter(Triangle *triangle);
float triangleSquare(Triangle *triangle);
void freeTriangle(Triangle **triangle);
#endif /* triangle3D_h */
