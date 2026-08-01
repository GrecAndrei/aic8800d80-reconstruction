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

extern uint32_t dword_115A14;
extern uint32_t dword_115A24;
extern uint32_t dword_115A2C;
extern uint32_t dword_115A28;
extern uint32_t dword_115A18;
extern uint32_t dword_115A1C;
extern uint32_t dword_115A20;

// handle_debug_cmd @ 0x1159cc, size 72 bytes
// Doc: rf_bus_setup_n396_59ce [rf]: Pack and store RF bus register fields from descriptor bytes
// rf_bus_setup_n396_59ce [rf]: Pack and store RF bus register fields from descriptor bytes
void  __noreturn handle_debug_cmd(int a1)
{
  printf_wrapper(dword_115A14);
  switch ( a1 )
  {
    case '0':
      printf_wrapper(dword_115A24);
      break;
    case '@':
      printf_wrapper(dword_115A2C);
      break;
    case ' ':
      printf_wrapper(dword_115A28);
      break;
    default:
      printf_wrapper(dword_115A18);
      break;
  }
  printf_wrapper(dword_115A1C);
  init_queue_table();
  printf_wrapper(dword_115A20);
  check_op_mode();
}

