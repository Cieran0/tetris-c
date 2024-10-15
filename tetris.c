#include "tetris.h"
#include "shapes.h"

block_t board[BOARD_HEIGHT][BOARD_WIDTH];
selected_position_t current_block[4] = {{.x=-1}};

bool dropped = false;

int tick_counter = 0;
int input_counter = 0;
int input_counter_max = 3;
int fall_time = 10;

bool game_over = false;

Color current_colour = RED;

const Color colours[6] = {BLUE,GREEN,YELLOW,RED,ORANGE,PURPLE};

Color board_colours[BOARD_HEIGHT][BOARD_WIDTH];

void DrawGameOver();
bool CheckGameOver();

int main(void) {
    
    ClearBoard();
    InitWindow(SCALE(256), SCALE(192), "Tetris Mini");
    SetTargetFPS(60);
    double time = GetTime();
    SetRandomSeed(*((unsigned int*)&time));
    RandomShape(4,0);
    while (!WindowShouldClose()) {
        if(!HasBlock()) {
            RandomShape(4,0);
        }

        
        DrawLoop();
        if(game_over) {
            if(IsKeyPressed(KEY_SPACE)) {
                ClearBoard();
                current_block[0].x = -1;
                game_over = false;
            }
            
            continue;

        }

        if (IsKeyPressed(KEY_UP)) {
            RotateShape();
        }

        input_counter++;
        if(input_counter > input_counter_max) {
            HandleInput();
            input_counter = 0;
        }


        tick_counter++;
        if(tick_counter > fall_time) {
            MoveSelectedDown();
            tick_counter = 0;
        }

        if(dropped) {
            MakeReal();
            CheckLines();
            dropped = false;
        }

        game_over = CheckGameOver();
    }

    CloseWindow();
    return 0;
}

void DrawGameOver() {
    static const char* game_over_text = "Game Over!";
    int width = MeasureText(game_over_text,SCALE(10));
    DrawText(game_over_text, (SCALE(256) - width) / 2, SCALE(192)/2, SCALE(10), RED);
}

bool CheckGameOver() {
    for (int x = 0; x < BOARD_WIDTH; x++)
    {
        if(board[0][x] == FILLED) {
            return true;
        }
    }
    
}

void  MoveSelected(int direction) {
    if(!HasBlock())
        return;

    bool can_move = true;
    for (int i = 0; i < 4; i++)
    {
        selected_position_t cb = current_block[i];
        if (cb.x + direction == BOARD_WIDTH || cb.x + direction < 0) {
            can_move = false;
            break;
        } else if (board[cb.y][cb.x+direction] == FILLED) {
            can_move = false;
            break;
        }
    }

    if(!can_move) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        board[current_block[i].y][current_block[i].x] = EMPTY;
        current_block[i].x += direction;  // Move down
    }
}

void HandleInput() {
    if(IsKeyDown(KEY_RIGHT)) {
        MoveSelected(1);
    } else if (IsKeyDown(KEY_LEFT)) {
        MoveSelected(-1);
    } else if (IsKeyDown(KEY_DOWN)) {
        MoveSelectedDown();
    }
}

bool HasBlock() {
    return current_block[0].x != -1;
}

void DrawLoop() {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawBoard();
    DrawContainer();
    if(game_over) {
        DrawGameOver();
    }
    EndDrawing();
}

void DrawContainer() {
    int top_y = SCALE(BOARD_Y) - SCALE((BOARD_HEIGHT - 1) * BLOCK_SIZE);
    int bottom_y = SCALE(BOARD_Y);
    int start_x = SCALE(BOARD_X) - 1 - (SCALE(2));
    int end_x = SCALE(BOARD_X) + SCALE(BOARD_WIDTH * BLOCK_SIZE) + 1;
    
    DrawRectangle(start_x, top_y, SCALE(2), bottom_y, WHITE);
    DrawRectangle(end_x, top_y, SCALE(2), bottom_y, WHITE);
    DrawRectangle(start_x, bottom_y + SCALE(BLOCK_SIZE), (end_x - start_x) + SCALE(2), SCALE(192) - (bottom_y + 1), WHITE);
}

void ClearBoard() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            board[y][x] = EMPTY;
            board_colours[y][x] = BLACK;
        }
    }
    
}

void DrawBoard() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            DrawFilledBlock(x, y);
        }
    }

    if(!HasBlock())
        return;
    for (int i = 0; i < 4; i++)
    {
        DrawBlock(current_block[i].x, current_block[i].y, current_colour);
    }
    
}

void DrawBlock(int x, int y, Color colour) {
    int top_y = SCALE(BOARD_Y) - SCALE((BOARD_HEIGHT - 1) * BLOCK_SIZE);
    DrawRectangle(SCALE(BOARD_X) + SCALE(x * BLOCK_SIZE), 
                  top_y + SCALE(y * BLOCK_SIZE), 
                  SCALE(BLOCK_SIZE), 
                  SCALE(BLOCK_SIZE), 
                  colour);
    DrawRectangleLines(SCALE(BOARD_X) + SCALE(x * BLOCK_SIZE), 
                       top_y + SCALE(y * BLOCK_SIZE), 
                       SCALE(BLOCK_SIZE), 
                       SCALE(BLOCK_SIZE), 
                       BLACK);
}

void DrawFilledBlock(int x, int y) {
    block_t index = board[y][x];
    if (index == EMPTY) return; // Skip empty blocks
    
    DrawBlock(x,y,board_colours[y][x]);
}

bool Selected(int x, int y) {
    for (int i = 0; i < 4; i++)
    {
        if (current_block[i].x == x && current_block[i].y == y)
        {
            return true;
        }
    }
    return false;
}

void MakeReal() {
    for (int i = 0; i < 4; i++)
    {
        board[current_block[i].y][current_block[i].x] = FILLED;
        board_colours[current_block[i].y][current_block[i].x] = current_colour;
    }
    current_block[0].x = -1; 
}

void MoveSelectedDown() {
    if(!HasBlock())
        return;

    bool can_move = true;
    for (int i = 0; i < 4; i++)
    {
        selected_position_t cb = current_block[i];
        if (cb.y == (BOARD_HEIGHT-1)) {
            can_move = false;
            break;
        } else if (board[cb.y+1][cb.x] == FILLED) {
            can_move = false;
            break;
        }
    }

    if(!can_move) {
        dropped = true;
        return;
    }

    for (int i = 0; i < 4; i++) {
        board[current_block[i].y][current_block[i].x] = EMPTY;
        current_block[i].y += 1;  // Move down
    }
}

void CheckLine(int y) {

    for (int x = 0; x < BOARD_WIDTH; x++) {
        if (board[y][x] == EMPTY)
            return; 
    }

    for (int x = 0; x < BOARD_WIDTH; x++) {
        board[y][x] = EMPTY;
    }

    for (int i = y; i > 0; i--) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[i][x] = board[i - 1][x];
        }
    }

    for (int x = 0; x < BOARD_WIDTH; x++) {
        board[0][x] = EMPTY;
    }
}

void CheckLines() {
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        CheckLine(y);
    }
    
}