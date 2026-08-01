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

extern uint32_t dword_120048;
extern uint32_t dword_120040;

// get_bss_by_channel @ 0x11fef8, size 326 bytes
uint64_t  get_bss_by_channel(uint8_t *a1, char a2)
{
  int v3; // r6
  int v4; // r8
  int v5; // r4
  uint8_t *v6; // r7
  int v7; // r10
  int *v8; // r9
  int *v9; // r0
  int v10; // r2
  int v11; // r3
  uint64_t result; // r0
  uint64_t v13; // r2
  int v14; // r4
  int v15; // r0

  v3 = *a1;
  v4 = a1[41];
  v5 = dword_120048;
  v6 = (uint8_t *)(1320 * v4 + 120 * v3 + dword_120048);
  v7 = 120 * v3 + 1320 * v4;
  v6[578] = a2;
  v6[576] = a1[40];
  v8 = (int *)(v7 + 480 + v5);
  v6[577] = v3;
  v9 = sub_100200(v8, 0, 0x48u);
  switch ( v6[576] )
  {
    case 0:
    case 3:
      *(uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = hash32(v9) & 0xFFFFFFLL;
      break;
    case 1:
      v15 = 1320 * v4 + 120 * v3 + v5;
      *(uint32_t *)(v15 + 560) = *((uint32_t *)a1 + 6);
      *(uint32_t *)(v15 + 564) = *((uint32_t *)a1 + 7);
      *(uint32_t *)(v15 + 568) = *((uint32_t *)a1 + 8);
      *(uint32_t *)(v15 + 572) = *((uint32_t *)a1 + 9);
      *(uint64_t *)(v15 + 552) = 0;
      break;
    case 4:
      *(uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = *(uint64_t *)&dword_120040;
      break;
    case 5:
      memcpy(v7 + 560 + v5, a1 + 8, 16);
      goto LABEL_3;
    default:
LABEL_3:
      *(uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = 0;
      break;
  }
  v10 = 1320 * v4 + 120 * v3 + v5;
  v11 = 1320 * v4 + v5;
  if ( *(uint8_t *)(v10 + 576) == 5 )
    *(uint32_t *)(v11 + 1204) = v8;
  else
    *(uint32_t *)(v11 + 1200) = v8;
  *(uint8_t *)(v10 + 579) = 1;
  result = *((uint64_t *)a1 + 1);
  v13 = *((uint64_t *)a1 + 2);
  v14 = v5 + 1320 * v4 + 120 * v3;
  *(uint64_t *)(v14 + 580) = result;
  *(uint64_t *)(v14 + 588) = v13;
  *(uint8_t *)(v14 + 596) = a1[4];
  return result;
}

