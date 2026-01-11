
#include "doomgeneric.h"
#include <semblance/syscall.h>

void DG_Init() {
    semblance_syscall_init_window("DOOM", DOOMGENERIC_RESX, DOOMGENERIC_RESY);
}

void DG_SetWindowTitle(const char *title) {
    semblance_syscall_set_window_title(title);
}

void DG_DrawFrame() {
    // ...
}

void DG_SleepMs(uint32_t ms) {
    // ...
}

uint32_t DG_GetTicksMs() {
    return 0;
}

int DG_GetKey(int* pressed, unsigned char* doomKey) {
    return 0;
}

void init(int argc, char** argv) {
    doomgeneric_Create(argc, argv);
}

void tick() {
    doomgeneric_Tick();
}
