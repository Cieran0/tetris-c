#include "shapes.h"
#include "tetris.h"


int current_shape = O;

void GenerateO(int x, int y) {
    selected_position_t top_left = {.x = x, .y = y};
    selected_position_t top_right = {.x = x+1, .y = y};

    selected_position_t bottom_left = {.x = x, .y = y+1};
    selected_position_t bottom_right = {.x = x+1, .y = y+1};

    current_block[0] = top_left;
    current_block[1] = top_right;
    current_block[2] = bottom_left;
    current_block[3] = bottom_right;

}

void GenerateI(int x, int y) {
    selected_position_t top = {.x = x, .y = y};
    selected_position_t top_middle = {.x = x, .y = y+1};

    selected_position_t bottom_middle = {.x = x, .y = y+2};
    selected_position_t bottom = {.x = x, .y = y+3};

    current_block[0] = top;
    current_block[1] = top_middle;
    current_block[2] = bottom_middle;
    current_block[3] = bottom;

}

void GenerateT(int x, int y) {
    selected_position_t top = {.x = x, .y = y};

    selected_position_t bottom_left = {.x = x-1, .y = y+1};
    selected_position_t bottom_right = {.x = x+1, .y = y+1};
    selected_position_t bottom = {.x = x, .y = y+1};

    current_block[0] = top;
    current_block[1] = bottom_left;
    current_block[2] = bottom;
    current_block[3] = bottom_right;

}

void GenerateL(int x, int y) {
    selected_position_t top = {.x = x+1, .y = y};

    selected_position_t bottom_left = {.x = x-1, .y = y+1};
    selected_position_t bottom = {.x = x, .y = y+1};
    selected_position_t bottom_right = {.x = x+1, .y = y+1};

    current_block[0] = top;
    current_block[1] = bottom_left;
    current_block[2] = bottom;
    current_block[3] = bottom_right;

}

void GenerateJ(int x, int y) {
    selected_position_t top = {.x = x-1, .y = y};

    selected_position_t bottom_left = {.x = x-1, .y = y+1};
    selected_position_t bottom_right = {.x = x+1, .y = y+1};
    selected_position_t bottom = {.x = x, .y = y+1};

    current_block[0] = top;
    current_block[1] = bottom_left;
    current_block[2] = bottom;
    current_block[3] = bottom_right;

}

void GenerateS(int x, int y) {
    selected_position_t top = {.x = x, .y = y};
    selected_position_t top_right = {.x = x+1, .y = y};

    selected_position_t bottom_left = {.x = x-1, .y = y+1};
    selected_position_t bottom = {.x = x, .y = y+1};

    current_block[0] = top;
    current_block[1] = top_right;
    current_block[2] = bottom;
    current_block[3] = bottom_left;

}

void GenerateZ(int x, int y) {
    selected_position_t top = {.x = x, .y = y};
    selected_position_t top_left = {.x = x-1, .y = y};

    selected_position_t bottom_right = {.x = x+1, .y = y+1};
    selected_position_t bottom = {.x = x, .y = y+1};

    current_block[0] = top;
    current_block[1] = top_left;
    current_block[2] = bottom;
    current_block[3] = bottom_right;

}

void RandomShape(int x, int y) {
    current_shape = GetRandomValue(0,4);

    current_colour = colours[GetRandomValue(0,5)];

    switch (current_shape)
    {
    case Z:
    case O:
        GenerateO(x,y);
        break;
    case I:
        GenerateI(x,y);
        break;
    case T:
        GenerateT(x,y);
        break;
    case L:
        GenerateL(x,y);
        break;
    case J:
        GenerateJ(x,y);
        break;
    case S:
        GenerateS(x,y);
        break;
        GenerateZ(x,y);
        break;
    default:
        break;
    }

    current_rotation = 0;
}