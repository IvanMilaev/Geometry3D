//
//  line3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "line3d.h"

LinePP *lineByPoints(const Point *p, const Point *q) {
    LinePP *tmp = (LinePP*) malloc(sizeof(LinePP));
    tmp->p = (Point*) malloc(sizeof(Point));
    tmp->q = (Point*) malloc(sizeof(Point));
    *(tmp->p) = *p;
    *(tmp->q) = *q;
    return tmp;
}

bool lineIsPointOnLine(LinePP *line, Point *p)
{
    // finding directional vector coords for
    Vector *d = (Vector*) malloc(sizeof(Vector));
    d->x = line->q->x - line->p->x;
    d->y = line->q->y - line->p->y;
    d->z = line->q->z - line->p->z;
    
    // check is point
    
    float X, Y, Z;
    
    if (fabsf(d->x) >= FLT_EPSILON)
    {
        X = (p->x - line->p->x)/d->x;
    }
    else if(fabsf(p->x - line->p->x) >= FLT_EPSILON) return false;
    
    if (fabsf(d->y) >= FLT_EPSILON)
    {
        Y = (p->y - line->p->y)/d->y;
    }
    else if(fabsf(p->y - line->p->y) >= FLT_EPSILON) return false;
    
    if (fabsf(d->z) >= FLT_EPSILON)
    {
        Z = (p->z - line->p->z)/d->z;
    }
    else if(fabsf(p->z - line->p->z) >= FLT_EPSILON) return false;
    
    return fabsf(X - Y) < FLT_EPSILON && fabsf(Y - Z) < FLT_EPSILON;
    
}

void freeLinePP(LinePP **line) {
    free((*line)->p);
    free((*line)->q);
    free(*line);
    *line = NULL;
}
