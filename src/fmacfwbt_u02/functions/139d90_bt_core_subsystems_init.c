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

extern uint32_t dword_139E08;
extern uint32_t dword_139E0C;
extern uint32_t dword_139E10;
extern uint32_t dword_139E14;
extern uint32_t dword_139E18;
extern uint32_t dword_139E1C;
extern uint32_t dword_139E20;
extern uint32_t dword_139E28;
extern uint32_t dword_139E2C;
extern uint32_t off_139E24;

// bt_core_subsystems_init @ 0x139d90, size 118 bytes
// Doc: bt_core_subsystems_init [bt]: Initialize BT core subsystem tables/structures
// bt_core_subsystems_init [bt]: Initialize BT core subsystem tables/structures
int bt_core_subsystems_init()
{
  uint32_t *v0; // r6
  int v1; // r4
  int v2; // r5
  uint32_t *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (uint32_t *)(dword_139E08 + 16);
  bt_xtal_init_check((uint32_t *)dword_139E08);
  v1 = dword_139E0C;
  bt_xtal_init_check(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (uint32_t *)v1;
    v1 += 292;
    list_push_tail((int)v0, v3);
  }
  while ( v1 != v2 );
  bt_xtal_init_check((uint32_t *)dword_139E10);
  bt_xtal_init_check((uint32_t *)dword_139E14);
  list_push_tail(dword_139E10, (uint32_t *)dword_139E18);
  list_push_tail(dword_139E10, (uint32_t *)dword_139E1C);
  list_push_tail(dword_139E10, (uint32_t *)dword_139E20);
  v4 = dword_139E28;
  result = dword_139E2C;
  *((uint16_t *)off_139E24 + 51) = -1;
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

