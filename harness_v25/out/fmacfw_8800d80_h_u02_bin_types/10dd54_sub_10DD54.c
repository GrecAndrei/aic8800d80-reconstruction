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

extern uint32_t off_10DDB4;
extern uint32_t dword_10DDB8;
extern uint32_t off_10DDBC;
extern uint32_t off_10DDC4;
extern uint32_t dword_10DDC8;
extern uint32_t off_10DDC0;

// sub_10DD54 @ 0x10dd54, size 94 bytes
int sub_10DD54()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r3
  int result; // r0

  sub_10DB64(1);
  sub_10DBAC(1);
  sub_10DB64(2);
  sub_10DBAC(2);
  if ( *((uint8_t *)off_10DDB4 + 369) )
  {
    sub_10DBC0(1);
    sub_10DBC0(2);
  }
  else
  {
    sub_10DBD4(1);
    sub_10DBD4(2);
  }
  sub_10DB94(3);
  sub_10DC04(3, 2, dword_10DDB8);
  v0 = off_10DDBC;
  v1 = off_10DDC4;
  result = dword_10DDC8;
  *((uint32_t *)off_10DDBC + 1) = off_10DDC0;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

