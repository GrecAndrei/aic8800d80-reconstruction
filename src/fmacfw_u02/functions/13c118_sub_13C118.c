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

extern uint32_t off_13C270;
extern uint32_t dword_13C274;
extern uint32_t dword_13C28C;
extern uint32_t dword_13C27C;
extern uint32_t dword_13C278;
extern uint32_t dword_13C284;
extern uint32_t dword_13C288;
extern uint32_t dword_13C290;
extern uint32_t off_13C280;

// read_tx_power_cal @ 0x13c118, size 344 bytes
unsigned int  read_tx_power_cal(unsigned int result)
{
  int v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // r3
  int v8; // r7
  int v9; // r2
  int v10; // r8
  int v11; // r9
  int v12; // r7
  int v13; // r9
  int16_t v14; // r3
  int ( *v15)(int, int); // r2
  int16_t v16; // r1

  v1 = *(uint8_t *)(result + 27);
  v2 = *((uint32_t *)off_13C270 + 4);
  if ( v1 != 255 )
  {
    v3 = *(uint8_t *)(result + 29);
    v4 = dword_13C274;
    v5 = dword_13C274 + 696 * v3;
    v6 = result;
    result = *(uint32_t *)(v5 + 4) << 30;
    if ( (*(uint32_t *)(v5 + 4) & 2) != 0 )
    {
      v7 = 696 * v3 + 12 * v1 + dword_13C274;
      v8 = *(uint8_t *)(v7 + 453);
      ++*(uint8_t *)(v7 + 455);
      if ( v8 == 33 )
      {
        result = v2 + 1000000 - *(uint32_t *)(v7 + 444);
        if ( result > dword_13C28C && v2 - 500000 - *(uint32_t *)(v7 + 448) >= 0 && *(uint8_t *)(v5 + 36) != 1 )
        {
          result = dword_13C27C;
          v9 = *(uint8_t *)(dword_13C278 + v1);
          if ( !*(uint32_t *)(dword_13C27C + 84 * v9)
            && !*(uint32_t *)(dword_13C284 + 8 * v9)
            && !*(uint32_t *)(v4 + 8 * (v9 + 87 * v3 + 78)) )
          {
            result = dword_13C288;
            if ( !*(uint32_t *)(dword_13C288 + 8 * (165 * *(uint8_t *)(v6 + 28) + v9 + 159)) )
              return check_fw_state_byte(v3, v1, *(uint16_t *)(v6 + 32));
          }
        }
      }
      else
      {
        v10 = dword_13C290;
        v11 = dword_13C290 + 32 * v8;
        *(uint32_t *)(v11 + 8) = v2;
        result = rx_rate_field_parse((v8 << 8) | 8);
        v12 = 32 * v8;
        if ( result == 1 )
        {
          v13 = *(uint32_t *)(v11 + 28);
          v14 = *(uint16_t *)(v6 + 30);
          result = *(uint16_t *)(v13 + 4);
          *(uint16_t *)(v6 + 34) = result;
          if ( (v14 & 1) == 0 || (v14 & 3) == 3 )
          {
            if ( (*(uint8_t *)(*(uint32_t *)(v4 + 696 * v3 + 340) + 166) & 4) != 0 )
              *(uint32_t *)(v6 + 36) |= 0x200000u;
            v15 = *(int ( **)(int, int))v13;
            v16 = *(uint16_t *)(v6 + 32) - result;
            *(uint16_t *)(v6 + 30) = v14 | 2;
            result = v15(v13, v16 & 0xFFF) + v13;
            *(uint8_t *)(result + 6) = 1;
            if ( (*(uint16_t *)(v6 + 30) & 1) == 0 )
              *(uint16_t *)(v6 + 64) = *((uint16_t *)off_13C280 + 22) + (*((uint32_t *)off_13C270 + 4) >> 10);
            ++*(uint32_t *)(v12 + v10 + 4);
          }
        }
      }
    }
  }
  return result;
}

