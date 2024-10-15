#pragma once
#include "tetris.h"

typedef bool rotations_t[4];

struct shape
{
    rotations_t rotations[4][4];
} typedef shape_t;

enum shape_enum {
    O,
    I,
    T,
    L,
    J,
    S,
    Z
};

extern shape_t current_shape;
extern int current_rotation;

void RandomShape(int x, int y);
void RotateShape(int x, int y);
void GenerateShape(int x, int y);

extern const shape_t tetroid_O;
extern const shape_t tetroid_I;
extern const shape_t tetroid_T;
extern const shape_t tetroid_L;
extern const shape_t tetroid_J;
extern const shape_t tetroid_S;
extern const shape_t tetroid_Z;
