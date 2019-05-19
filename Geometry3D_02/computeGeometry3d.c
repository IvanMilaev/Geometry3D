//
//  computeGeometry3d.c
//  Geometry3D_02
//
//  Created by Иван Милаев on 19/05/2019.
//  Copyright © 2019 IvanMilaev. All rights reserved.
//

#include "computeGeometry3d.h"


//  is point r lies on line segment 'pq'

bool isPointOnSegment(Segment *segment, Point *r)
{
    if (r->x <= fmax(segment->p->x, segment->q->x) && r->x >= fmin(segment->p->x, segment->q->x) &&
        r->y <= fmax(segment->p->y, segment->q->y) && r->y >= fmin(segment->p->y, segment->q->y) &&
        r->z <= fmax(segment->p->z, segment->q->z) && r->z >= fmin(segment->p->z, segment->q->z)
        )
        return true;
    
    return false;
}

/*
 To find orientation of ordered triplet (p, q, r).
 The function returns following values
 0 --> p, q and r are colinear
 1 --> Clockwise
 2 --> Counterclockwise
 
 https://math.stackexchange.com/questions/2386810/orientation-of-three-points-in-3d-space
 three points are 𝑝⃗ 1=(𝑥1,𝑦1,𝑧1), 𝑝⃗2=(𝑥2,𝑦2,𝑧2), and 𝑝⃗3=(𝑥3,𝑦3,𝑧3).
 
 Let
 𝑛⃗ =(𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)
 i.e.
 𝑥𝑛=(𝑦2−𝑦1)(𝑧3−𝑧1)−(𝑧2−𝑧1)(𝑦3−𝑦1)
 𝑦𝑛=(𝑧2−𝑧1)(𝑥3−𝑥1)−(𝑥2−𝑥1)(𝑧3−𝑧1)
 𝑧𝑛=(𝑥2−𝑥1)(𝑦3−𝑦1)−(𝑦2−𝑦1)(𝑥3−𝑥1)
 
 If the three points are collinear, then 𝑛⃗ =(0,0,0)=0. Otherwise, the three points are on a plane,
 with 𝑛⃗  being normal (perpendicular) to the plane.
 
 As mentioned in a comment, if we look at the triangle from the side the normal vector 𝑛⃗  points to,
 the points are in counterclockwise order; but, if we look at the triangle from the other side, they
 are in clockwise order.
 
 If we know that the three points are on a plane with normal vector 𝑘⃗ , then
 
 𝑘⃗ ⋅𝑛⃗ =𝑘⃗ ⋅((𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)) > 0, counterclockwise
 𝑘⃗ ⋅𝑛⃗ =𝑘⃗ ⋅((𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)) < 0, clockwise
 𝑘⃗ ⋅𝑛⃗ =𝑘⃗ ⋅((𝑝⃗2 − 𝑝⃗1)×(𝑝⃗3 − 𝑝⃗1)) = 0, oops
 
 The "oops" case covers several possible situations. For example, if the three points are collinear,
 then 𝑛⃗ =0. Or, if the three points are on a plane parallel to 𝑘⃗ , the result is zero also.
 */

int orientationOfThreePoints(Point *p, Point *q, Point *r)
{
    
    
    int val = (q->y - p->y) * (r->x - q->x) - (q->x - p->x) * (r->y - q->y);
    
    if (val == 0) return 0;  // colinear
    
    return (val > 0)? 1: 2; // clock or counterclock wise
}

