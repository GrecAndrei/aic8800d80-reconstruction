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

extern uint32_t dword_139D6C;
extern uint32_t dword_139D70;
extern uint32_t dword_139D74;
extern uint32_t dword_139D78;
extern uint32_t dword_139D7C;
extern uint32_t dword_139D80;
extern uint32_t dword_139D84;
extern uint32_t dword_139D8C;
extern uint32_t dword_139D90;
extern uint32_t off_139D88;

// bt_init_mod @ 0x139cf4, size 118 bytes
int bt_init_mod()
{
  uint32_t *v0; // r6
  int v1; // r4
  int v2; // r5
  uint32_t *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (uint32_t *)(dword_139D6C + 16);
  zero_8_bytes((uint32_t *)dword_139D6C);
  v1 = dword_139D70;
  zero_8_bytes(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (uint32_t *)v1;
    v1 += 292;
    cmd_handler_a((int)v0, v3);
  }
  while ( v1 != v2 );
  zero_8_bytes((uint32_t *)dword_139D74);
  zero_8_bytes((uint32_t *)dword_139D78);
  cmd_handler_a(dword_139D74, (uint32_t *)dword_139D7C);
  cmd_handler_a(dword_139D74, (uint32_t *)dword_139D80);
  cmd_handler_a(dword_139D74, (uint32_t *)dword_139D84);
  v4 = dword_139D8C;
  result = dword_139D90;
  *((uint16_t *)off_139D88 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(uint8_t *)(v4 - 52) = 0;
    *(uint16_t *)(v4 + 8) = 0;
    *(uint32_t *)(v4 - 64) = result;
    *(uint32_t *)(v4 - 60) = v4;
    *(uint32_t *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}

