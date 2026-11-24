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

// cli_parse_char @ 0x115390, size 72 bytes
void  cli_parse_char(int a1)
{
  log_printf(aFaultHandlerFa);
  switch ( a1 )
  {
    case '0':
      log_printf(aBusfault);
      break;
    case '@':
      log_printf(aUsagefault);
      break;
    case ' ':
      log_printf(aMemmanagefault);
      break;
    default:
      log_printf(aHardfault);
      break;
  }
  log_printf(aContext);
  patch_copy_table();
  log_printf(aFaultHandler);
  patch_init();
}
