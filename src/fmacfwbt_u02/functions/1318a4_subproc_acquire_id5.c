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

extern uint32_t off_131988;
extern uint32_t off_13198C;
extern uint32_t dword_131998;
extern uint32_t dword_131994;
extern uint32_t dword_131990;
extern uint32_t dword_13199C;

// subproc_acquire_id5 @ 0x1318a4, size 226 bytes
// Doc: subproc_acquire_id5 [ipc]: Acquire sub-process handle id 5 and check ready
// subproc_acquire_id5 [ipc]: Acquire sub-process handle id 5 and check ready
int  subproc_acquire_id5(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v7; // r5
  int v8; // r4
  int v9; // r7
  int v10; // r4
  int v11; // r0
  int v12; // r1
  uint8_t *v14; // r7
  int v15; // r0
  int16_t v16; // r1
  int v17; // r4
  int v18; // r1
  int v19; // r2

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = rf_bus_setup_n3a8(5138, a4, a3, 0xCu);
  if ( **(int16_t **)off_131988 < 0 )
  {
    v14 = (uint8_t *)off_13198C;
    v8 = *((uint8_t *)off_13198C + 16);
    if ( v8 == 255 )
    {
      sub_12F694(dword_131998, dword_131994, 1092);
      v8 = v14[16];
    }
  }
  else
  {
    v8 = *((uint8_t *)off_13198C + 16);
  }
  if ( sub_101888() )
    mmio_bit_toggle_0189c(*((uint8_t *)a2 + 11));
  v9 = dword_131990 + 1320 * v8;
  v10 = *(uint32_t *)(v9 + 72);
  if ( v10 )
  {
    *(uint8_t *)v7 = *(uint8_t *)(v10 + 24);
    if ( *((uint8_t *)a2 + 10) )
    {
      if ( list_count_d594((uint32_t **)dword_13199C) == 1 )
      {
        v15 = rf_bus_setup_n3a8(59, 0, 5, 0xCu);
        *(uint8_t *)v15 = *(uint8_t *)(*(uint32_t *)(v9 + 72) + 24);
        v16 = *((uint16_t *)a2 + 4);
        v17 = a2[1];
        *(uint32_t *)(v15 + 2) = *a2;
        *(uint16_t *)(v15 + 10) = v16;
        *(uint32_t *)(v15 + 6) = v17;
        sub_12CBB4(v15);
        v18 = *a2;
        v19 = a2[1];
        *(uint16_t *)(v7 + 10) = *((uint16_t *)a2 + 4);
        *(uint32_t *)(v7 + 2) = v18;
        *(uint32_t *)(v7 + 6) = v19;
        goto LABEL_9;
      }
      v10 = *(uint32_t *)(v9 + 72);
    }
    v11 = *(uint32_t *)(v10 + 4);
    v12 = *(uint32_t *)(v10 + 8);
    *(uint16_t *)(v7 + 10) = *(uint16_t *)(v10 + 12);
    *(uint32_t *)(v7 + 2) = v11;
    *(uint32_t *)(v7 + 6) = v12;
LABEL_9:
    sub_12CBB4(v7);
    return 0;
  }
  *(uint8_t *)v7 = -1;
  sub_12CBB4(v7);
  return 0;
}

