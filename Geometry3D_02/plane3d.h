//
//  plane3d.h
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#ifndef plane3d_h
#define plane3d_h

#include <stdio.h>
#include "point3d.h"
#include "vector3d.h"
#include "line3d.h"
#include "matrix.h"

typedef struct Plane3D {
    // ax + by + cz + d = 0
    float a, b, c, d;
} Plane;


Plane *planeByPoints(const Point *p, const Point *q, const Point *r);
Vector *planeGetNormalVector( const Plane *plane);
bool isPointOnPlane(Plane *plane, Point *p);
void freePlanePPP(Plane **plane);

#endif /* plane3d_h */
