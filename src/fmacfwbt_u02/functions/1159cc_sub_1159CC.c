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

// handle_debug_cmd @ 0x1159cc, size 72 bytes
void  handle_debug_cmd(int a1)
{
  printf_wrapper(aFaultHandlerFa);
  switch ( a1 )
  {
    case '0':
      printf_wrapper(aBusfault);
      break;
    case '@':
      printf_wrapper(aUsagefault);
      break;
    case ' ':
      printf_wrapper(aMemmanagefault);
      break;
    default:
      printf_wrapper(aHardfault);
      break;
  }
  printf_wrapper(aContext);
  init_queue_table();
  printf_wrapper(aFaultHandler);
  check_op_mode();
}
