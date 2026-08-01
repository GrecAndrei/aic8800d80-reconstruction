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

extern uint32_t dword_1153D8;
extern uint32_t dword_1153E8;
extern uint32_t dword_1153F0;
extern uint32_t dword_1153EC;
extern uint32_t dword_1153DC;
extern uint32_t dword_1153E0;
extern uint32_t dword_1153E4;

// cli_parse_char @ 0x115390, size 72 bytes
// Doc: patch_apply_n_166 [patch]: Stub for patch apply helper N166
// patch_apply_n_166 [patch]: Stub for patch apply helper N166
void  __noreturn cli_parse_char(int a1)
{
  log_printf(dword_1153D8);
  switch ( a1 )
  {
    case '0':
      log_printf(dword_1153E8);
      break;
    case '@':
      log_printf(dword_1153F0);
      break;
    case ' ':
      log_printf(dword_1153EC);
      break;
    default:
      log_printf(dword_1153DC);
      break;
  }
  log_printf(dword_1153E0);
  patch_copy_table();
  log_printf(dword_1153E4);
  patch_init();
}

