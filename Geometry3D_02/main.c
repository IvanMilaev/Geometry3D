//
//  main.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 18/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "segment3d.h"
#include "plane3d.h"

int main(int argc, const char * argv[]) {
    
    Point *p =(Point*) malloc(sizeof(Point));
    Point *q =(Point*) malloc(sizeof(Point));
    Point *r =(Point*) malloc(sizeof(Point));
    LinePP *line = NULL;
    PlanePPP *plane = NULL;
    Vector *n = NULL;
    p->x = 11.0;
    p->y = - 3.0;
    p->z = 6.0;
    
    q->x = 2.0;
    q->y = - 4.0;
    q->z = 6.5;
    
    line = lineByPoints(p, q);
    
    r->x = 56.0;
    r->y = - 1.0;
    r->z = 2.9;
    
    plane = planeByPoints(p, q, r);
    n = planeGetNormalVector(plane);
    //bool is_on_line = lineIsPointOnLine(line, r);
    printf("Hello, World! %f %f %f\n", n->x, n->y, n->z);
    return 0;
}
