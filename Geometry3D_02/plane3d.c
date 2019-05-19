//
//  plane3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "plane3d.h"

PlanePPP *planeByPoints(const Point *p, const Point *q, const Point *r)
{
    PlanePPP *tmp = (PlanePPP*) malloc(sizeof(PlanePPP));
    tmp->p = (Point*) malloc(sizeof(Point));
    tmp->q = (Point*) malloc(sizeof(Point));
    tmp->r = (Point*) malloc(sizeof(Point));
    *(tmp->p) = *p;
    *(tmp->q) = *q;
    *(tmp->r) = *r;
    return tmp;
}

Vector *planeGetNormalVector( const PlanePPP *plane)
{
    // normal vector = cross(v1,v2) where v1 v2 - vectors from three points of plane
    Vector *v1 = (Vector*) malloc(sizeof(Vector));
    Vector *v2 = (Vector*) malloc(sizeof(Vector));
    
    v1 = vectorFromTwoPoints(plane->q, plane->p);
    v2 = vectorFromTwoPoints(plane->r, plane->q);
    
    return vectorMultiplyCross(v1, v2);
}

void freePlanePPP(PlanePPP **plane) {
    free((*plane)->p);
    free((*plane)->q);
    free((*plane)->r);
    free(*plane);
    *plane = NULL;
}
