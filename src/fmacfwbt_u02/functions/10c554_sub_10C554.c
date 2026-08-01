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

extern uint32_t off_10C644;
extern uint32_t off_10C648;
extern uint32_t off_10C64C;
extern uint32_t off_10C684;
extern uint32_t off_10C650;
extern uint32_t dword_10C654;
extern uint32_t dword_10C658;
extern uint32_t off_10C65C;
extern uint32_t off_10C660;
extern uint32_t off_10C664;
extern uint32_t dword_10C668;
extern uint32_t dword_10C66C;
extern uint32_t dword_10C670;
extern uint32_t dword_10C674;
extern uint32_t off_10C678;
extern uint32_t off_10C67C;
extern uint32_t dword_10C680;

// sdio_irq_enable @ 0x10c554, size 238 bytes
int sdio_irq_enable()
{
  int *v0; // r2
  int *v1; // r0
  int *v2; // r1
  uint32_t *v3; // r12
  uint32_t *v4; // r4
  int v5; // r3
  uint32_t *v6; // r7
  uint32_t *v7; // r6
  uint32_t *v8; // r5
  int v9; // r3
  int v10; // r3
  uint32_t *v11; // r3

  v0 = (int *)off_10C644;
  v1 = (int *)off_10C648;
  v2 = (int *)off_10C64C;
  v3 = off_10C684;
  *(uint32_t *)off_10C644 |= 0x3F000000u;
  v4 = off_10C650;
  v5 = dword_10C654;
  *(uint32_t *)off_10C650 = dword_10C654;
  *v1 = v5 + 1578562697;
  *v2 = dword_10C658;
  v6 = off_10C65C;
  v7 = off_10C660;
  v8 = off_10C664;
  *v3 = 2423;
  *v6 = dword_10C668;
  *v7 = 37890;
  v4 += 131075;
  v9 = dword_10C66C;
  *v8 = dword_10C66C;
  v2 += 717332;
  v1 += 717334;
  v0 += 131615;
  *v4 = dword_10C670;
  *v2 = v9;
  *v1 = v9;
  *v0 = v9;
  v6[717338] = 2100;
  v10 = dword_10C674;
  v7[749881] = dword_10C674;
  v2 += 32546;
  v10 += 875888655;
  *v2 = v10;
  v0 += 32602;
  *(uint32_t *)off_10C678 = v10 - 943588895;
  v1[32584] = 909522486;
  *v0 = 65280;
  v11 = off_10C67C;
  v4[33032] = dword_10C680;
  v2[42] = 21333;
  *v11 = (char *)v0 + 1441354102;
  return 21333;
}

