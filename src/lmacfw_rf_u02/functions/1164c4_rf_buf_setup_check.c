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

extern uint32_t dword_11657C;
extern uint32_t dword_116578;
extern uint32_t dword_116574;
extern uint32_t dword_116570;
extern uint32_t off_11656C;

// rf_buf_setup_check @ 0x1164c4, size 168 bytes
// Doc: rf_buf_setup_check [rf]: Setup/check RF buffer with 0x1000 size limit
// rf_buf_setup_check [rf]: Setup/check RF buffer with 0x1000 size limit
int  rf_buf_setup_check(int a1, int a2, int a3)
{
  uint64_t v3; // kr00_8
  int v6; // r1
  int v7; // r7
  int result; // r0
  int v9; // r2
  int v10; // r3
  int v11; // r2
  unsigned uint64_t v12; // kr08_8

  v3 = *(uint64_t *)(a1 + 28);
  if ( a3 > 4096 )
  {
    v12 = (unsigned int)dword_11657C * (unsigned uint64_t)(unsigned int)(v3 - dword_116578);
    *(uint32_t *)(HIDWORD(v3) + 28) = *(uint32_t *)(HIDWORD(v3) + 24) + 4095;
    *(uint32_t *)(HIDWORD(v3) + 32) = patch_ctrl_write_magic(HIDWORD(v3) + 8, a3, HIDWORD(v12) >> 12) + 4;
  }
  else
  {
    *(uint32_t *)(HIDWORD(v3) + 28) = *(uint32_t *)(HIDWORD(v3) + 24) + a3 - 1;
    *(uint32_t *)(HIDWORD(v3) + 32) = a3 + 4;
    *(uint32_t *)(HIDWORD(v3) + 20) = 0;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
      v6 = dword_116574;
    else
      v6 = v3 + 44;
    v7 = v3 + 44;
  }
  else
  {
    v6 = dword_116570;
    v7 = v3 + 44;
  }
  result = sub_1282E8(v7, v6, 52);
  v9 = *(uint32_t *)off_11656C;
  if ( *(uint32_t *)(v3 + 64) & 0x7C | (*(uint32_t *)(v3 + 64) >> 11) & 6 )
    v10 = (uint16_t)((uint16_t)*(uint32_t *)off_11656C << 8) | (uint8_t)v9;
  else
    v10 = *(uint32_t *)off_11656C & 0xFF00 | BYTE1(v9);
  v11 = *(uint32_t *)(a1 + 28);
  *(uint32_t *)(v3 + 80) = v10;
  *(uint32_t *)(HIDWORD(v3) + 40) = 0;
  *(uint32_t *)(HIDWORD(v3) + 44) = v7;
  *(uint32_t *)(HIDWORD(v3) + 64) = 0;
  *(uint32_t *)(a1 + 44) = 0;
  *(uint32_t *)(a1 + 48) = 0;
  *(uint32_t *)(v11 + 40) = 0;
  *(uint16_t *)(a1 + 38) = 0;
  return result;
}

