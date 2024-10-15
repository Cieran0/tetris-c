#pragma once

#include "raylib.h"
#include "stdio.h"

#define SCALE_FACTOR 4
#define SCALE(x) (x * SCALE_FACTOR)
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 18
#define BOARD_SIZE (BOARD_WIDTH * BOARD_HEIGHT)
#define BLOCK_SIZE 10
#define BOARD_Y 180
#define BOARD_X 78

#define EMPTY false
#define FILLED true

typedef bool block_t;


struct selected_position
{
    int x;
    int y;
} typedef selected_position_t;

extern block_t board[BOARD_HEIGHT][BOARD_WIDTH];
extern selected_position_t current_block[4];

void ClearBoard(void);
void DrawBoard(void);
void DrawLoop(void);
void DrawBlock(int x, int y, Color colour);
void DrawFilledBlock(int x, int y);
void DrawContainer(void);
bool HasBlock(void);
void MoveSelectedDown();
void MakeReal();
void HandleInput();
void CheckLines();

extern Color current_colour;

extern const Color colours[6];