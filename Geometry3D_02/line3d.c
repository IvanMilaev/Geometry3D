//
//  line3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "line3d.h"

Line *lineByPoints(const Point *p, const Point *q) {
    
    Line *line = (Line*) malloc(sizeof(Line));
    line->p = (Point*) malloc(sizeof(Point));
    line->v = (Vector*) malloc(sizeof(Vector));
    
    // x - x0/a = y - y0/b = z - z0/c  p - point p(x0,y0,z0)  directional vector v(a, b, c)
    line->p->x = p->x;
    line->p->y = p->y;
    line->p->z = p->z;
    
    line->v->x = q->x - p->x;
    line->v->y = q->y - p->y;
    line->v->z = q->z - p->z;

    return line;
}

Line *lineByVectorPoint(const Vector *v, const Point *p) {
    Line *line = (Line*) malloc(sizeof(Line));
    line->p = (Point*) malloc(sizeof(Point));
    line->v = (Vector*) malloc(sizeof(Vector));
    
    line->p->x = p->x;
    line->p->y = p->y;
    line->p->z = p->z;
    
    line->v->x = v->x;
    line->v->y = v->y;
    line->v->z = v->z;
    
    return line;
}

Vector *lineGetDirectionalVector(Line *line)
{
    Vector *d = (Vector*) malloc(sizeof(Vector));
    d->x = line->v->x;
    d->y = line->v->y;
    d->z = line->v->z;
    
    return d;
}
bool lineIsPointOnLine(Line *line, Point *p)
{
    float X, Y, Z;
    
    
    // X = (x-x0)/a a!=0 :
    if (fabsf(line->v->x) >= FLT_EPSILON)
    {
        X = (p->x - line->p->x)/line->v->x;
    }
    //a==0 : x-x0 == 0
    else if(fabsf(p->x - line->p->x) >= FLT_EPSILON) return false;
    
    // Y = (y-y0)/b b!=0 :
    if (fabsf(line->v->y) >= FLT_EPSILON)
    {
         Y = (p->y - line->p->y)/line->v->y;
    }
    //b==0 : y-y0 == 0
    else if(fabsf(p->y - line->p->y) >= FLT_EPSILON) return false;
    
    // Z = (z-z0)/c c!=0 :
    if (fabsf(line->v->z) >= FLT_EPSILON)
    {
        Z = (p->z - line->p->z)/line->v->z;
    }
    //c==0 : z-z0 == 0
    else if(fabsf(p->z - line->p->z) >= FLT_EPSILON) return false;
    
    // X == Y == Z
    return fabsf(X - Y) < FLT_EPSILON && fabsf(Y - Z) < FLT_EPSILON;
    
}

void freeLine(Line **line) {
    free(*line);
    *line = NULL;
}
