#include <stdlib.h>
#include <stdio.h>
#include <raylib.h> // raylib 5.5

#include "video.h" // video_gif, video_gif_len
#include "sound.h" // sound_wav, sound_wav_len

#define FRAME_DELAY 3

int main() {
    SetTraceLogLevel(LOG_NONE);

    // preload resources before window opens
    int animFrames = 0;
    Image gif = LoadImageAnimFromMemory(".gif", video_gif, video_gif_len, &animFrames);

    // audio setup
    InitAudioDevice();

    // ray lib does not have a function to manipulate system volume
    // OS-specific solution is needed

    Music music = LoadMusicStreamFromMemory(".wav", sound_wav, sound_wav_len);
    music.looping = 0;

    // window setup
    InitWindow(0, 0, ""); // 0, 0 makes windowed fullscreen
    // ToggleFullscreen is broken on windows? wrong scaling, laggy transition

    int screenWidth = GetRenderWidth();
    int screenHeight = GetRenderHeight();
    
    Texture2D texture = LoadTextureFromImage(gif);

    float scale = (float)screenWidth / gif.width;
    Vector2 position = {0, 0};

    // warm up
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();

    PlayMusicStream(music);

    // play the gif (mostly taken from "gif player" example of raylib)
    // absence of WindowShouldClose() is intentional here
    for (int frame = 0; frame < animFrames; frame++) {
        for (int delay = 0; delay < FRAME_DELAY; delay++) {
            UpdateMusicStream(music);
            BeginDrawing();
            {
                ClearBackground(BLACK); // try removing this))
                DrawTextureEx(texture, position, 0.0f, scale, WHITE);
            }
            EndDrawing();
        }
        UpdateTexture(texture, (unsigned char*)gif.data + gif.height * gif.width * 4 * frame);
    }

    // play sound for just a bit longer
    for (int i = 0; i < 15; i++) {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadMusicStream(music);
    CloseWindow();
    
    return 0;
}