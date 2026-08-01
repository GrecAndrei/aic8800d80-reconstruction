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

extern uint32_t dword_115298;
extern uint32_t dword_1152A8;
extern uint32_t dword_1152B0;
extern uint32_t dword_1152AC;
extern uint32_t dword_11529C;
extern uint32_t dword_1152A0;
extern uint32_t dword_1152A4;

// process_debug_char @ 0x115250, size 72 bytes
void  __noreturn process_debug_char(int a1)
{
  debug_printf(dword_115298);
  switch ( a1 )
  {
    case '0':
      debug_printf(dword_1152A8);
      break;
    case '@':
      debug_printf(dword_1152B0);
      break;
    case ' ':
      debug_printf(dword_1152AC);
      break;
    default:
      debug_printf(dword_11529C);
      break;
  }
  debug_printf(dword_1152A0);
  apply_patch_table();
  debug_printf(dword_1152A4);
  log_boot_message();
}

