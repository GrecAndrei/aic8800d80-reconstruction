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

extern uint32_t off_130214;
extern uint32_t off_130218;
extern uint32_t dword_13021C;
extern uint32_t dword_130220;
extern uint32_t dword_130224;
extern uint32_t dword_130228;
extern uint32_t dword_13022C;
extern uint32_t dword_130230;

// sub_1301B4 @ 0x1301b4, size 94 bytes
int sub_1301B4()
{
  int *v0; // r4
  uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  log_hw_init_if();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_130214 = 1;
  }
  v0 = (int *)off_130218;
  v1 = (uint32_t *)dword_13021C;
  ++*(uint32_t *)off_130218;
  bt_xtal_init_check(v1);
  bt_xtal_init_check((uint32_t *)dword_130220);
  list_push_tail(dword_13021C, (uint32_t *)dword_130224);
  list_push_tail(dword_13021C, (uint32_t *)dword_130228);
  list_push_tail(dword_13021C, (uint32_t *)dword_13022C);
  result = list_push_tail(dword_13021C, (uint32_t *)dword_130230);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_130214;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

