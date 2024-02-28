#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <time.h>
#include <math.h>

#include <gl/gl.h>
#include <GL/glut.h>

#include <windows.h>

#define ATTACK_R 0.2f


typedef struct {

    float x;
    float y;

}point;

typedef struct {

    point topLeft;
    point bottomRight;

}boundBox;

#endif // COMMON_H
