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
#include "computeGeometry3d.h"

int main(int argc, const char * argv[]) {
    
    Point *p =(Point*) malloc(sizeof(Point));
    Point *q =(Point*) malloc(sizeof(Point));
    Point *r =(Point*) malloc(sizeof(Point));
    Plane *plane = NULL;
    
    p->x = 2.0;
    p->y = 9.0;
    p->z = 7.0;
    
    q->x = 5.0;
    q->y = - 6.0;
    q->z = 32;
    
    r->x = 2.0;
    r->y = - 3.0;
    r->z = 6.0;
    
    plane = planeByPoints(p, q, r);
    
    printf("Hello, World! %f \n", plane->d);
    return 0;
}
