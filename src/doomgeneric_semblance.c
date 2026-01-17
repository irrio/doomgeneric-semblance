
#include "doomgeneric.h"
#include "doomkeys.h"
#include <semblance/syscall.h>
#include <stdio.h>
#include <SDL_keycode.h>

void DG_Init() {
    semblance_syscall_init_window("DOOM", DOOMGENERIC_RESX, DOOMGENERIC_RESY);
}

void DG_SetWindowTitle(const char *title) {
    semblance_syscall_set_window_title(title);
}

void DG_DrawFrame() {
    semblance_syscall_render(DG_ScreenBuffer, DOOMGENERIC_RESX, DOOMGENERIC_RESY);
}

void DG_SleepMs(uint32_t ms) {
    semblance_syscall_sleep_ms(ms);
}

uint32_t DG_GetTicksMs() {
    return semblance_syscall_get_ticks_ms();
}

static int translate_key_code(int sdl_key_code) {
    switch (sdl_key_code) {
        case SDLK_RETURN:
            return KEY_ENTER;
        case SDLK_ESCAPE:
            return KEY_ESCAPE;
        case SDLK_LEFT:
            return KEY_LEFTARROW;
        case SDLK_RIGHT:
            return KEY_RIGHTARROW;
        case SDLK_UP:
            return KEY_UPARROW;
        case SDLK_DOWN:
            return KEY_DOWNARROW;
        case SDLK_LCTRL:
        case SDLK_RCTRL:
            return KEY_FIRE;
        case SDLK_SPACE:
            return KEY_USE;
        case SDLK_LSHIFT:
        case SDLK_RSHIFT:
            return KEY_RSHIFT;
        case SDLK_LALT:
        case SDLK_RALT:
            return KEY_LALT;
        case SDLK_F2:
            return KEY_F2;
        case SDLK_F3:
            return KEY_F3;
        case SDLK_F4:
            return KEY_F4;
        case SDLK_F5:
            return KEY_F5;
        case SDLK_F6:
            return KEY_F6;
        case SDLK_F7:
            return KEY_F7;
        case SDLK_F8:
            return KEY_F8;
        case SDLK_F9:
            return KEY_F9;
        case SDLK_F10:
            return KEY_F10;
        case SDLK_F11:
            return KEY_F11;
        case SDLK_F12:
            return KEY_F12;
        case SDLK_EQUALS:
        case SDLK_PLUS:
            return KEY_EQUALS;
        case SDLK_MINUS:
            return KEY_MINUS;
        default:
            return tolower(sdl_key_code);
    }
}

int DG_GetKey(int* pressed, unsigned char* doomKey) {
    read_key_result_t result = semblance_syscall_read_key();
    if (!result.read) return 0;
    *pressed = result.pressed;
    *doomKey = translate_key_code(result.key_code);
    return 1;
}

void init(int argc, char** argv) {
    doomgeneric_Create(argc, argv);
}

void tick() {
    doomgeneric_Tick();
}
