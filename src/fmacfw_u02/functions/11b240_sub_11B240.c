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

extern uint32_t off_11B350;
extern uint32_t dword_11B364;
extern uint32_t off_11B358;
extern uint32_t dword_11B360;
extern uint32_t dword_11B35C;
extern uint32_t off_11B354;

// check_link_state @ 0x11b240, size 272 bytes
// Doc: sub_121B240 [mac]: Subroutine checking state byte against value 3
// sub_121B240 [mac]: Subroutine checking state byte against value 3
int  check_link_state(int *a1)
{
  uint16_t *v1; // r6
  int v2; // r3
  int v3; // r9
  int v5; // r4
  int v6; // r10
  int v7; // r3
  int v8; // r2
  int *v9; // r5
  int v10; // r10
  int v11; // r3
  int v12; // r2
  int v13; // r11
  int v15; // r0
  int v16; // r4
  int16_t v17; // r3

  v1 = (uint16_t *)off_11B350;
  if ( *((uint8_t *)off_11B350 + 197) > 3u )
    return 0;
  v2 = 3;
  v3 = dword_11B364;
  LOBYTE(v5) = 3;
  while ( 1 )
  {
    v7 = v3 + 84 * v2;
    v8 = *(uint8_t *)(v7 + 26);
    *((uint8_t *)v1 + 190) = v5;
    if ( v8 == 1 )
      break;
    v9 = *(int **)(v7 + 12);
    if ( v9 )
    {
      v10 = v7;
      v11 = v9[9] & 0x200000;
      if ( v11 )
      {
LABEL_13:
        v13 = (int)v9;
        v9 = 0;
      }
      else
      {
        while ( 1 )
        {
          v12 = v9[19];
          if ( *(int *)(v12 + 72) >= 0 )
            break;
          if ( *(uint32_t *)(v12 + 16) )
          {
            v13 = *v9;
            if ( *(int *)(*(uint32_t *)(*v9 + 76) + 72) >= 0 )
              goto LABEL_3;
          }
          get_connection_by_index((int)v9, (uint8_t)v5);
          v9 = *(int **)(v10 + 12);
          if ( !v9 )
            goto LABEL_4;
          v11 = v9[9] & 0x200000;
          if ( v11 )
            goto LABEL_13;
        }
        v13 = (int)v9;
        v9 = (int *)v11;
      }
LABEL_3:
      v6 = process_tx_request(v13, a1, *((uint32_t *)v1 + 44), v1[93], *((uint8_t *)v1 + 190));
      if ( v6 )
      {
        if ( v9 )
          get_connection_by_index((int)v9, (uint8_t)v5);
        v16 = *(uint32_t *)(v13 + 68);
        if ( **(int16_t **)off_11B358 < 0 && !v16 )
          mmio_clear_register(dword_11B360, dword_11B35C, 1383);
        v17 = *(uint16_t *)(v16 + 8);
        *((uint32_t *)v1 + 51) = v16;
        *(uint16_t *)(v16 + 8) = v17 | 0x200;
        return v6;
      }
    }
LABEL_4:
    v5 = (char)(v5 - 1);
    v2 = v5;
    if ( v5 < *((uint8_t *)v1 + 197) )
      return 0;
  }
  if ( !*(uint8_t *)(*(uint32_t *)off_11B354 + 1) )
    return 0;
  v15 = *(uint32_t *)(v7 + 36);
  *a1 = *(uint32_t *)(v7 + 12);
  return v15 + 84;
}

