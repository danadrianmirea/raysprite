#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 600;
    float player_x = 100;
    float player_y = 100;
    int player_speed_x = 200;
    int player_speed_y = 200;
    int player_radius = 15;
    int player_increment = 1;

    float fPlayerSpeed = 300.0f;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "Moa, merge si in C++ combinatia, cu RayLib");
    SetTargetFPS(144);

    Image player = LoadImage("res/image/eu.png");    
    ImageResize(&player, 128, 128);

    Texture2D playerTex = LoadTextureFromImage(player); 
    float dt = GetFrameTime();

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);

       

       // player_x += player_speed_x * dt;
       // player_y += player_speed_y * dt;

        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_W)) {
            player_y -= fPlayerSpeed*dt;
        }
        if (IsKeyDown(KEY_S)) {
            player_y += fPlayerSpeed*dt;
        }
        if (IsKeyDown(KEY_A)) {
            player_x -= fPlayerSpeed*dt;
        }        
        if (IsKeyDown(KEY_D)) {
            player_x += fPlayerSpeed*dt;
        }
        

        /*
        if(player_x + player_radius >= screenWidth  || player_x - player_radius <= 0)
        {
            player_speed_x *= -player_increment;
        }

        if(player_y + player_radius >= screenHeight  || player_y - player_radius <= 0)
        {
            player_speed_y *= -player_increment;
        }
        */


        //DrawCircle(player_x,player_y,player_radius, WHITE);
        DrawTexture(playerTex, player_x - playerTex.width/2, player_y - playerTex.height/2, WHITE);


        EndDrawing();
        dt = GetFrameTime();
    }

    CloseWindow();
    return 0;
}