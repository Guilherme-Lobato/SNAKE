#include <raylib.h>
#include <stdlib.h>
#include <stdio.h> 

//TELA SELEÇÃO DE MAPAS
void openMapSelect() {
    typedef enum {MAP_1, MAP_2, MAP_3, MAP_4, VOLTAR} MapOption;

    const int largura = 800;
    const int altura = 800;
    InitWindow(largura, altura, "Escolha o mapa");
    SetTargetFPS(60);

    MapOption optionSelect = MAP_1; 
    int totalOptionsMaps = 5; 

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            optionSelect = (optionSelect + 1) % totalOptionsMaps;
        }
        if (IsKeyPressed(KEY_UP)) {
            optionSelect = (optionSelect - 1 + totalOptionsMaps) % totalOptionsMaps;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (optionSelect) {
                case MAP_1:
                    break;
                case MAP_2:
                    break;
                case MAP_3:
                    break;
                case MAP_4:
                    break;
                case VOLTAR:
                    CloseWindow();
                    main();
                    break;
            }
        }

        BeginDrawing();
        ClearBackground(BLUE); 

        DrawText("MAPA 1", (largura - MeasureText("MAPA 1", 40)) / 2, 220, 40, optionSelect == MAP_1 ? WHITE : BLACK);
        DrawText("MAPA 2", (largura - MeasureText("MAPA 2", 40)) / 2, 270, 40, optionSelect == MAP_2 ? WHITE : BLACK);
        DrawText("MAPA 3", (largura - MeasureText("MAPA 3", 40)) / 2, 320, 40, optionSelect == MAP_3 ? WHITE : BLACK);
        DrawText("MAPA 4", (largura - MeasureText("MAPA 4", 40)) / 2, 370, 40, optionSelect == MAP_4 ? WHITE : BLACK);
        DrawText("VOLTAR", (largura - MeasureText("VOLTAR", 40)) / 2, 420, 40, optionSelect == VOLTAR ? WHITE : BLACK);

        EndDrawing();
    }
}


int main(void) {
    typedef enum { MENU_PLAY, MENU_MAPS, MENU_STYLE_SNAKE, MENU_INFO, MENU_EXIT } MenuOption;
    const int largura = 800;
    const int altura = 800;
    InitWindow(largura, altura, "SNAKE");
    SetTargetFPS(60);

    Image bgImage = LoadImage("imagens/tela.png"); 
    Texture2D bgTexture = LoadTextureFromImage(bgImage);
    UnloadImage(bgImage); 

    MenuOption optionSelect = MENU_PLAY;
    int totalOptions = 5;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            optionSelect = (optionSelect + 1) % totalOptions;
        }
        if (IsKeyPressed(KEY_UP)) {
            optionSelect = (optionSelect - 1 + totalOptions) % totalOptions;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (optionSelect) {
                case MENU_PLAY:
                    break;
                case MENU_MAPS:
                    CloseWindow();
                    openMapSelect();
                    main();
                    break;
                case MENU_STYLE_SNAKE:
                    break;
                case MENU_INFO:
                    break;
                case MENU_EXIT:
                    CloseWindow();
                    break;
            }
        }

        BeginDrawing();

        Rectangle source = { 0, 0, bgTexture.width, bgTexture.height };
        Rectangle dest = { 0, 0, largura, altura }; 
        Color tint = WHITE; 

        if (!WindowShouldClose()) {
            DrawTexturePro(bgTexture, source, dest, (Vector2){ 0, 0 }, 0.0f, tint);
            DrawText("JOGAR", (largura - MeasureText("JOGAR", 40)) / 2, 220, 40, optionSelect == MENU_PLAY ? WHITE : BLACK);
            DrawText("MAPAS", (largura - MeasureText("MAPAS", 40)) / 2, 270, 40, optionSelect == MENU_MAPS ? WHITE : BLACK);
            DrawText("ESTILO", (largura - MeasureText("ESTILO", 40)) / 2, 320, 40, optionSelect == MENU_STYLE_SNAKE ? WHITE : BLACK);
            DrawText("INFORMAÇÕES", (largura - MeasureText("INFORMAÇÕES", 40)) / 2, 370, 40, optionSelect == MENU_INFO ? WHITE : BLACK);
            DrawText("SAIR", (largura - MeasureText("SAIR", 40)) / 2, 420, 40, optionSelect == MENU_EXIT ? WHITE : BLACK);
        }

        EndDrawing();
    }

    UnloadTexture(bgTexture);

    return 0;
}
