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

extern uint32_t off_122A78;
extern uint32_t off_122A74;
extern uint32_t off_122A7C;

// scan_validate @ 0x122a28, size 76 bytes
int  scan_validate(int a1, int *a2, int a3, int a4)
{
  char *v7; // r7
  uint32_t *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(uint8_t *)a2 )
  {
    v7 = (char *)off_122A78;
    if ( (*((uint8_t *)off_122A74 + 1) & 1) == 0 || (*((uint32_t *)off_122A78 + 98) & 1) != 0 )
    {
      v8 = off_122A7C;
      v9 = *a2;
      v10 = a2[2];
      v11 = a2[3];
      *((uint32_t *)off_122A7C + 1) = a2[1];
      *(uint32_t *)(v7 + 266) = v9;
      v12 = a2[5];
      v13 = a2[4];
      v8[2] = v10;
      v8[6] = a2[6];
      v8[3] = v11;
      v8[4] = v13;
      v8[5] = v12;
    }
  }
  mac_write_header_word(122, a4, a3);
  return 0;
}

