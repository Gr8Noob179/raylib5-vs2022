#include "raylib.h"
#include "Math.h"

const int LEGS_COUNT = 4;

class Table 
{
public:
    float width, height;
    float legs[LEGS_COUNT];
    float legWidth, legHeight;
    float weight;
    float r, g, b;
    float x, y;

    Color legsColor, topColor;

    void Draw()
    {
        //top
        DrawRectangle(x, y, width, height, BROWN);
        //legs
        for (int i = 0; i < LEGS_COUNT; i++) {
            DrawRectangle(legs[i], y, legWidth, legHeight, legsColor);
        }

    }
};

Vector2 Seek(Vector2 target, Vector2 position, Vector2 velocity, float speed)
{
    return Normalize(target - position) * speed - velocity;
}

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    Table woodTable;
    woodTable.height = 60.0f;
    woodTable.weight = 40.0f;

    woodTable.height = 60.0f;
    woodTable.width = 200.0f;
    woodTable.x = screenWidth * 0.5f - woodTable.width * 0.5f;
    woodTable.y = screenHeight * 0.75f - woodTable.height;
    woodTable.legWidth = 10.0f;
    woodTable.legHeight = woodTable.height * 3.0f;
    woodTable.legsColor = BLACK;
    woodTable.topColor = BROWN;
    woodTable.legs[0] = woodTable.x;
    woodTable.legs[1] = woodTable.x + woodTable.legWidth * 3.0f;
    woodTable.legs[2] = woodTable.x + woodTable.width - woodTable.legWidth * 3.0f;
    woodTable.legs[3] = woodTable.x + woodTable.width - woodTable.legWidth;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    const char* sentence = "something to write";

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        woodTable.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
