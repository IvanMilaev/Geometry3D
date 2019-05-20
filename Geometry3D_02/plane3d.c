//
//  plane3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "plane3d.h"

Plane *planeByPoints(const Point *p, const Point *q, const Point *r)
{
    Plane *plane = (Plane*) malloc(sizeof(Plane));
    
    // find normal vector of plane 𝑛⃗ = v1 x v2,  v1 v2 - directional vector of two lines from three points
    // Set the first point p as M(x0,y0,z0);
    Line *l1 = lineByPoints(p, q);
    Line *l2 = lineByPoints(p, r);
    Vector *v1 = lineGetDirectionalVector(l1);
    Vector *v2 = lineGetDirectionalVector(l2);
    Vector *n = vectorMultiplyCross(v1, v2);
    
    // equation of plane => n * (x-x0, y-y0, z-z0) = 0  -->  ax + by + cz + d = 0
    plane->a = n->x;
    plane->b = n->y;
    plane->c = n->z;
    plane->d = -1.0 * (n->x * p->x + n->y * p->y + n->z * p->z);
    return plane;
}

Vector *planeGetNormalVector( const Plane *plane)
{
    Vector *n = (Vector*) malloc(sizeof(Vector));
    n->x = plane->a;
    n->y = plane->b;
    n->z = plane->c;
    
    return n;
}

void freePlane(Plane **plane) {
    free(*plane);
    *plane = NULL;
}
