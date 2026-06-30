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

extern uint32_t off_12796C;
extern uint32_t off_127968;
extern uint32_t dword_127970;
extern uint32_t dword_127974;
extern uint32_t dword_12798C;
extern uint32_t dword_127988;

// sub_1278DC @ 0x1278dc, size 140 bytes
int sub_1278DC()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  uint32_t *v5; // r3
  int v6; // r1

  v0 = (int *)off_12796C;
  v1 = off_127968;
  sub_100200((int *)off_127968, 0, 0x60u);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    sub_100200(i, 0, 0x1Cu);
    *((uint16_t *)i + 7) = 255;
    *((uint8_t *)i + 24) = -1;
    *((uint8_t *)i + 27) = -1;
    if ( v2 <= 2 )
    {
      sub_12D108(v1);
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((uint16_t *)v0 + 47) = 0;
    *((uint8_t *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  sub_12D100(dword_127970);
  sub_12D100(dword_127974);
  sub_12D108(dword_127970);
  sub_12D108(dword_127970);
  sub_12D108(dword_127970);
  result = sub_12D108(dword_127970);
  v5 = off_127968;
  v6 = dword_12798C;
  *((uint32_t *)off_127968 + 13) = dword_127988;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

