//
//  point3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "point3d.h"

Point *createPoint(float x, float y, float z)
{
    Point *point = (Point*) malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    point->z = z;
    
    return point;
}

void freePoint(Point **point) {
    free(*point);
    *point = NULL;
}
