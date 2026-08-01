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

extern uint32_t off_111A18;
extern uint32_t off_111A14;
extern uint32_t off_111A1C;
extern uint32_t off_111A20;

// send_data_word @ 0x1119bc, size 88 bytes
int  send_data_word(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  uint32_t *v6; // r2

  v2 = (int *)off_111A18;
  v3 = *(uint32_t *)off_111A14;
  v4 = *(uint32_t *)off_111A18;
  *((uint16_t *)off_111A1C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(uint32_t *)v4 = -1073741824;
  *(uint32_t *)(v4 + 4) = v3;
  *(uint8_t *)(v4 + 3) = v5;
  *(uint16_t *)v4 = a2;
  if ( result && a2 )
  {
    result = memcpy(v3, result, a2);
    v4 = *v2;
  }
  v6 = off_111A20;
  *(uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

