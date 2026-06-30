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

extern uint32_t off_103A54;
extern uint32_t off_103A50;
extern uint32_t off_103A58;
extern uint32_t off_103A60;
extern uint32_t off_103A64;
extern uint32_t dword_103A68;
extern uint32_t off_103A5C;

// crypto_hw_power_up_39c4 @ 0x1039c4, size 138 bytes
// Doc: crypto_hw_power_up_39c4 [mac]: Power up crypto hardware block via MMIO register set/unset
// crypto_hw_power_up_39c4 [mac]: Power up crypto hardware block via MMIO register set/unset
int crypto_hw_power_up_39c4()
{
  uint32_t *v0; // r2
  int v1; // r3
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  int v4; // r3
  uint32_t *v5; // r3
  uint32_t *v6; // r0
  int v7; // r1

  v0 = off_103A54;
  *(uint32_t *)off_103A50 |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    LOWORD(v1) = 50;
    do
      v1 = (uint16_t)(v1 - 1);
    while ( v1 );
  }
  v2 = off_103A58;
  v3 = off_103A54;
  *(uint32_t *)off_103A58 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  v5 = off_103A60;
  v6 = off_103A64;
  v7 = dword_103A68;
  *(uint32_t *)off_103A5C |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return feature_guard_sdio(0x2000, v7);
}

