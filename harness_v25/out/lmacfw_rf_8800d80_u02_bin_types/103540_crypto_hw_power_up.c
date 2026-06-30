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

extern uint32_t off_1035D0;
extern uint32_t off_1035CC;
extern uint32_t off_1035D4;
extern uint32_t off_1035DC;
extern uint32_t off_1035E0;
extern uint32_t dword_1035E4;
extern uint32_t off_1035D8;

// crypto_hw_power_up @ 0x103540, size 138 bytes
// Doc: crypto_hw_power_up [ke]: Power up crypto hardware by setting control bits
// crypto_hw_power_up [ke]: Power up crypto hardware by setting control bits
int  crypto_hw_power_up(int a1, int a2, int a3, int a4, int a5)
{
  uint32_t *v5; // r2
  int v6; // r3
  uint32_t *v7; // r3
  uint32_t *v8; // r2
  int v9; // r3
  int *v10; // r3
  int *v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3

  v5 = off_1035D0;
  *(uint32_t *)off_1035CC |= 1u;
  while ( (*v5 & 0x10) == 0 )
  {
    LOWORD(v6) = 50;
    do
      v6 = (uint16_t)(v6 - 1);
    while ( v6 );
  }
  v7 = off_1035D4;
  v8 = off_1035D0;
  *(uint32_t *)off_1035D4 |= 0x80000u;
  *v7 |= 0x100000u;
  while ( (*v8 & 8) == 0 )
  {
    LOWORD(v9) = 50;
    do
      v9 = (uint16_t)(v9 - 1);
    while ( v9 );
  }
  v10 = (int *)off_1035DC;
  v11 = (int *)off_1035E0;
  v12 = dword_1035E4;
  *(uint32_t *)off_1035D8 |= 0x20000u;
  *v10 |= 0x1000000u;
  v13 = *v10 | 0x8000000;
  *v10 = v13;
  v14 = *v11 | 0x524;
  *v11 = v14;
  return sub_11F74C(0x2000, v12, v13, v14, a5);
}

