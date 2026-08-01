#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t dword_11114C;
extern uint32_t dword_111144;
extern uint32_t dword_111148;

// ke_mem_alloc @ 0x1110cc, size 118 bytes
// Doc: ke_mem_alloc [ipc]: Allocate message slot and forward to handler
// ke_mem_alloc [ipc]: Allocate message slot and forward to handler
int  ke_mem_alloc(char a1, int a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = check_radio_state(4);
  if ( !v6 )
    return printf_wrapper(dword_11114C);
  v7 = v6;
  v8 = (uint32_t *)critical_enter_0();
  if ( v8 )
  {
    *(uint8_t *)v7 = a3;
    *((uint8_t *)v7 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v7 + 2) = a1;
    *((uint8_t *)v7 + 3) = 0;
    memcpy_aligned(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_111144;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (uint16_t)(a3 + 4) | v10 & v9 | 0x80000000;
    return ke_mutex_lock((int)v8);
  }
  else
  {
    printf_wrapper(dword_111148);
    return memory_pool_free(v7);
  }
}

