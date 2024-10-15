#include "shapes.h"
#include "tetris.h"


shape_t current_shape;
int current_rotation;
int delta_top_x = 0;
int delta_top_y = 0;
int last_rotation = 0;

void RotateShape(int x, int y) {
    last_rotation = current_rotation;
    current_rotation = (current_rotation + 1) % 4;
    GenerateShape(x+delta_top_x,y+delta_top_y);
}


void GenerateShape(int x, int y) {
    int temp_delta_top_x = 0;
    int temp_delta_top_y = 0;
    int k = 0;
    selected_position_t new_block[4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(current_shape.rotations[current_rotation][i][j]) {
                if(k==0) {
                    temp_delta_top_x = -j;
                    temp_delta_top_y = -i;
                }

                if(j+x >= BOARD_WIDTH || j+x <= 0 || i+y >= BOARD_HEIGHT || i+y < 0) {
                    current_rotation = last_rotation;
                    return; //FALIED
                }

                new_block[k] = (selected_position_t){.x = j+x, .y = i+y};
                k++;
            }

            if(k == 4)
                break;
        }
    }

    delta_top_x = temp_delta_top_x;
    delta_top_y = temp_delta_top_y;

    for (int i = 0; i < 4; i++)
    {
        current_block[i] = new_block[i];
    }
    
}

void RandomShape(int x, int y) {
    int shape = GetRandomValue(0,4);

    current_colour = colours[GetRandomValue(0,5)];

    switch (shape)
    {
    case Z:
        current_shape = tetroid_Z;
        break;
    case O:
        current_shape = tetroid_O;
        break;
    case I:
        current_shape = tetroid_I;
        break;
    case T:
        current_shape = tetroid_T;
        break;
    case L:
        current_shape = tetroid_L;
        break;
    case J:
        current_shape = tetroid_J;
        break;
    case S:
        current_shape = tetroid_S;
        break;
    default:
        break;
    }

    current_rotation = 0;

    GenerateShape(x,y);
}