//
//  segment3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//


#include "segment3d.h"

Segment *segmentByCoords(float x0, float y0, float z0, float x1, float y1, float z1)
{
    Segment *segm = (Segment*) malloc(sizeof(Segment));
    segm->p = (Point*) malloc(sizeof(Point));
    segm->q = (Point*) malloc(sizeof(Point));
    segm->p->x = x0;
    segm->p->y = y0;
    segm->p->z = z0;
    segm->q->x = x1;
    segm->q->y = y1;
    segm->q->z = z1;
    return segm;
}


Segment *segmentByPoints(const Point *p, const Point *q) {
    Segment *segm = (Segment*) malloc(sizeof(Segment));
    segm->p = (Point*) malloc(sizeof(Point));
    segm->q   = (Point*) malloc(sizeof(Point));
    *(segm->p) = *p;
    *(segm->q) = *q;
    return segm;
}



void removeSegment(Segment **segment)
{
    free((*segment)->p);
    free((*segment)->q);
    free(*segment);
    *segment = NULL;
}

