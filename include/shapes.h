#pragma once
#include "tetris.h"

enum shape_enum {
    O,
    I,
    T,
    L,
    J,
    S,
    Z
};

extern int current_shape;
extern int current_rotation;

void GenerateO(int x, int y);
void GenerateI(int x, int y);
void RandomShape(int x, int y);
int GetShapeRotationCount(int shape);
void RotateShape();

