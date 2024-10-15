#include "tetris.h"
#include "shapes.h"

struct x_y
{
    int x;
    int y;
} typedef x_y_t;

struct rotation
{
    x_y_t positions[4];
} typedef rotation_t;


struct shape
{
    rotation_t rotations[4];
} typedef shape_t;


const shape_t shape_O = {
    .rotations = {
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 1, .y = 0}, 
                {.x = 0, .y = 1}, 
                {.x = 1, .y = 1}, 
            }
        },
    }
};

const shape_t shape_I = {
    .rotations = {
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 0, .y = 1}, 
                {.x = 0, .y = 2}, 
                {.x = 0, .y = 3}, 
            }
        },
        {
            .positions = {
                {.x = 0, .y = 0}, 
                {.x = 1, .y = 0}, 
                {.x = 2, .y = 0}, 
                {.x = 3, .y = 0}, 
            }
        },
                {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 0, .y = -1}, 
                {.x = 0, .y = -2}, 
                {.x = 0, .y = -3}, 
            }
        },
        {
            .positions = {
                {.x = 0, .y = 0}, 
                {.x = -1, .y = 0}, 
                {.x = -2, .y = 0}, 
                {.x = -3, .y = 0}, 
            }
        }
    }
};

const shape_t shape_T = {
    .rotations = {
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = -1, .y = 1}, 
                {.x = 0, .y = 1}, 
                {.x = 1, .y = 1}, 
            }
        },
        {
            .positions = {
                {.x = 0, .y = 0}, 
                {.x = -1, .y = -1}, 
                {.x = -1, .y = 0}, 
                {.x = -1, .y = 1}, 
            }
        },
                {
            .positions = { 
                {.x = 0, .y = 1}, 
                {.x = -1, .y = 0}, 
                {.x = 0, .y = 0}, 
                {.x = 1, .y = 0}, 
            }
        },
        {
            .positions = {
                {.x = 0, .y = 0}, 
                {.x = 1, .y = -1}, 
                {.x = 1, .y = 0}, 
                {.x = 1, .y = 1}, 
            }
        }
    }
};

const shape_t shape_L = {
    .rotations = {
        {
            .positions = { 
                {.x = 1, .y = 0}, 
                {.x = -1, .y = 1}, 
                {.x = 0, .y = 1}, 
                {.x = 1, .y = 1}, 
            }
        },
        {
           .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 1, .y = 0}, 
                {.x = 1, .y = 1}, 
                {.x = 1, .y = 2}, 
            }
        },
                {
            .positions = { 
                {.x = -1, .y = 0}, 
                {.x = -1, .y = -1}, 
                {.x = 0, .y = -1}, 
                {.x = 1, .y = -1}, 
            }
        },
        {
            .positions = {
                {.x = 0, .y = 0}, 
                {.x = 0, .y = 1}, 
                {.x = 1, .y = 1}, 
                {.x = 2, .y = 1}, 
            }
        }
    }
};

const shape_t shape_J = {
    .rotations = {
        {
            .positions = { 
                {.x = -1, .y = 0}, 
                {.x = -1, .y = 1}, 
                {.x = 0, .y = 1}, 
                {.x = 1, .y = 1}, 
            }
        },
        {
           .positions = { 
                {.x = 0, .y = 0}, 
                {.x = -1, .y = 0}, 
                {.x = -1, .y = 1}, 
                {.x = -1, .y = 2}, 
            }
        },
                {
            .positions = { 
                {.x = 1, .y = 0}, 
                {.x = 1, .y = -1}, 
                {.x = 0, .y = -1}, 
                {.x = -1, .y = -1}, 
            }
        },
        {
           .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 1, .y = 0}, 
                {.x = 1, .y = 1}, 
                {.x = 1, .y = 2}, 
            }
        }
    }
};

const shape_t shape_S = {
    .rotations = {
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 1, .y = 0}, 
                {.x = -1, .y = 1}, 
                {.x = 0, .y = 1}, 
            }
        },
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 0, .y = -1}, 
                {.x = 1, .y = 0}, 
                {.x = 1, .y = 1}, 
            }
        },
    }
};

const shape_t shape_Z = {
    .rotations = {
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = -1, .y = 0}, 
                {.x = 1, .y = 1}, 
                {.x = 0, .y = 1}, 
            }
        },
        {
            .positions = { 
                {.x = 0, .y = 0}, 
                {.x = 0, .y = -1}, 
                {.x = -1, .y = 0}, 
                {.x = -1, .y = 1}, 
            }
        },
    }
};

const shape_t shapes[7] = {
    shape_O,
    shape_I,
    shape_T,
    shape_L,
    shape_J,
    shape_S,
    shape_Z,
};

// Function to get the number of rotation states for each shape
int GetShapeRotationCount(int shape) {
    switch (shape) {
        case O: return 1; // O only has one rotation
        case I: return 4; // I has 2 rotations
        case T: return 4; // T has 4 rotations
        case L: return 4; // L has 4 rotations
        case J: return 4; // J has 4 rotations
        case S: return 2; // S has 2 rotations
        case Z: return 2; // Z has 2 rotations
        default: return 0; // Default case
    }
}

int current_rotation = 0;

void RotateShape() {
    if (!HasBlock()) return;

    int rotation_count = GetShapeRotationCount(current_shape);

    x_y_t pivoit = { current_block[0].x , current_block[0].y };

    if(current_shape > Z) {
        printf("Not implemented\n");
        return;
    }

    current_rotation++;

    if(current_rotation >= rotation_count){
        current_rotation = 0;
    }

    const x_y_t* positions = shapes[current_shape].rotations[current_rotation].positions;
    bool can_rotate = true;
    for (int i = 0; i < 4; i++)
    {
        int x = pivoit.x + positions[i].x;
        int y = pivoit.y + positions[i].y;

        if (x >= BOARD_WIDTH || x < 0 || y >= BOARD_HEIGHT || y < 0) {
            can_rotate = false;
            break;
        } else if (board[y][x] == FILLED) {
            can_rotate = false;
            break;
        }
    }

    if(!can_rotate) {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        current_block[i].x = pivoit.x + positions[i].x;
        current_block[i].y = pivoit.y + positions[i].y;
    }

}