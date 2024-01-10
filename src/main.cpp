#include "raylib.h"
#include "Math.h"

class Table 
{
public:
    float width, height;
    int legs; 
    float legWidth, legHeight;
    float weight;
    float r, g, b;
    float x, y;
    Color color;

    void Draw()
    {
        //top
        DrawRectangle(x, y, width, height, color);

        float spacing = width / legs;
        float legX = x;

        //legs
        for (int i = 0; i < legs; i++) {
            DrawRectangle(legX, y, legWidth, legHeight, color);
            legX += spacing;
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

    woodTable.height = 50.0f;
    woodTable.width = 200.0f;
    woodTable.x = screenWidth * 0.5f - woodTable.width * 0.5f;
    woodTable.y = screenHeight * 0.75f - woodTable.height;
    woodTable.legs = 4;
    woodTable.legWidth = 200.0f;
    woodTable.legHeight = 60.0f;
    woodTable.color = BLACK;


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
