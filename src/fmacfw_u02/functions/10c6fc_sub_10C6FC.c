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

extern uint32_t off_10C7EC;
extern uint32_t off_10C7F0;
extern uint32_t off_10C7F4;
extern uint32_t off_10C82C;
extern uint32_t off_10C7F8;
extern uint32_t dword_10C7FC;
extern uint32_t dword_10C800;
extern uint32_t off_10C804;
extern uint32_t off_10C808;
extern uint32_t off_10C80C;
extern uint32_t dword_10C810;
extern uint32_t dword_10C814;
extern uint32_t dword_10C818;
extern uint32_t dword_10C81C;
extern uint32_t off_10C820;
extern uint32_t off_10C824;
extern uint32_t dword_10C828;

// peripheral_config_write @ 0x10c6fc, size 238 bytes
int peripheral_config_write()
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

  v0 = (int *)off_10C7EC;
  v1 = (int *)off_10C7F0;
  v2 = (int *)off_10C7F4;
  v3 = off_10C82C;
  *(uint32_t *)off_10C7EC |= 0x3F000000u;
  v4 = off_10C7F8;
  v5 = dword_10C7FC;
  *(uint32_t *)off_10C7F8 = dword_10C7FC;
  *v1 = v5 + 1578562697;
  *v2 = dword_10C800;
  v6 = off_10C804;
  v7 = off_10C808;
  v8 = off_10C80C;
  *v3 = 2423;
  *v6 = dword_10C810;
  *v7 = 37890;
  v4 += 131075;
  v9 = dword_10C814;
  *v8 = dword_10C814;
  v2 += 717332;
  v1 += 717334;
  v0 += 131615;
  *v4 = dword_10C818;
  *v2 = v9;
  *v1 = v9;
  *v0 = v9;
  v6[717338] = 2100;
  v10 = dword_10C81C;
  v7[749881] = dword_10C81C;
  v2 += 32546;
  v10 += 875888655;
  *v2 = v10;
  v0 += 32602;
  *(uint32_t *)off_10C820 = v10 - 943588895;
  v1[32584] = 909522486;
  *v0 = 65280;
  v11 = off_10C824;
  v4[33032] = dword_10C828;
  v2[42] = 21333;
  *v11 = (char *)v0 + 1441354102;
  return 21333;
}

