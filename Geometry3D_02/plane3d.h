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

typedef struct Plane3DThreePoints {
    // p,q,r no-collinear
    Point *p;
    Point *q;
    Point *r;
} PlanePPP;

typedef struct Plane3DLinePoint {
    // p is not lies on line
    LinePP *line;
    Point *p;
} PlaneLP;

typedef struct Plane3DTwoIntersectLines {
    // two intersected lines
    LinePP *line0;
    LinePP *line1;
} PlaneLL;

PlanePPP *planeByPoints(const Point *p, const Point *q, const Point *r);
Vector *planeGetNormalVector( const PlanePPP *plane);
bool isPointOnPlane(PlanePPP *plane, Point *p);
void freePlanePPP(PlanePPP **plane);

#endif /* plane3d_h */
