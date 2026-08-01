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

extern uint32_t off_12FFF8;
extern uint32_t off_12FFFC;
extern uint32_t dword_130000;
extern uint32_t dword_130004;
extern uint32_t dword_130008;
extern uint32_t dword_13000C;
extern uint32_t dword_130010;
extern uint32_t dword_130014;

// call_handler @ 0x12ff98, size 94 bytes
int call_handler()
{
  int *v0; // r4
  uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  nvic_configure();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12FFF8 = 1;
  }
  v0 = (int *)off_12FFFC;
  v1 = (uint32_t *)dword_130000;
  ++*(uint32_t *)off_12FFFC;
  zero_8_bytes(v1);
  zero_8_bytes((uint32_t *)dword_130004);
  cmd_handler_a(dword_130000, (uint32_t *)dword_130008);
  cmd_handler_a(dword_130000, (uint32_t *)dword_13000C);
  cmd_handler_a(dword_130000, (uint32_t *)dword_130010);
  result = cmd_handler_a(dword_130000, (uint32_t *)dword_130014);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12FFF8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

