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

// process_debug_char @ 0x115250, size 72 bytes
void  process_debug_char(int a1)
{
  debug_printf(aFaultHandlerFa);
  switch ( a1 )
  {
    case '0':
      debug_printf(aBusfault);
      break;
    case '@':
      debug_printf(aUsagefault);
      break;
    case ' ':
      debug_printf(aMemmanagefault);
      break;
    default:
      debug_printf(aHardfault);
      break;
  }
  debug_printf(aContext);
  apply_patch_table();
  debug_printf(aFaultHandler);
  log_boot_message();
}
