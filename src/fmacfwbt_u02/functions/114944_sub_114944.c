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

extern uint32_t off_1149E8;
extern uint32_t dword_1149EC;
extern uint32_t dword_1149F0;
extern uint32_t dword_1149F8;
extern uint32_t dword_1149F4;

// find_object_by_key @ 0x114944, size 164 bytes
int  find_object_by_key(char a1, int16_t a2, uint32_t *a3)
{
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r4
  int v10; // r1
  int v11; // r2
  int v12; // r6
  int v13; // r5
  uint16_t *v14; // r3
  int v15; // r5
  int16_t v16; // r1
  int16_t v17; // r2
  int v18; // r3
  int v19; // r2
  int v20; // r3
  uint64_t v21; // r4

  v6 = critical_enter_2();
  if ( v6 )
  {
    v9 = v6;
    v12 = critical_enter_0();
    if ( v12 )
    {
      v13 = *a3;
      v14 = off_1149E8;
      *(uint8_t *)(v9 + 2) = a1;
      v15 = (uint16_t)(v13 + 4);
      *(uint8_t *)v9 = v15 + 12;
      *(uint8_t *)(v9 + 1) = ((uint16_t)(v15 + 12) >> 8) & 0xF;
      *(uint8_t *)(v9 + 3) = 0;
      v16 = v14[13];
      v17 = v14[12];
      v18 = dword_1149EC;
      *(uint16_t *)(v9 + 6) = v16;
      *(uint16_t *)(v9 + 8) = v17;
      *(uint16_t *)(v9 + 10) = v15;
      *(uint16_t *)(v9 + 4) = a2;
      *(uint32_t *)(v9 + 12) = v18;
      if ( v15 )
      {
        *(uint32_t *)(v9 + 16) = *a3;
        memcpy_aligned(v9 + 20, a3 + 1, *a3);
      }
      v19 = *(uint32_t *)(v12 + 8);
      v20 = dword_1149F0;
      *(uint32_t *)v12 = v9;
      LODWORD(v21) = 0;
      HIDWORD(v21) = (uint16_t)(v15 + 16) | v20 & v19 | 0x80000000;
      *(uint64_t *)(v12 + 4) = v21;
      ke_mutex_lock(v12);
      return 0;
    }
    else
    {
      ke_event_schedule(dword_1149F8, v10, v11);
      memory_pool_free((uint32_t *)v9);
      return -2;
    }
  }
  else
  {
    ke_event_schedule(dword_1149F4, v7, v8);
    return -1;
  }
}

