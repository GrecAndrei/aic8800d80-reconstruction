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

// sub_115390 @ 0x115390, size 72 bytes
// Doc: patch_apply_n_166 [patch]: Stub for patch apply helper N166
// patch_apply_n_166 [patch]: Stub for patch apply helper N166
void  __noreturn sub_115390(int a1)
{
  sub_10DC24(dword_1153D8);
  switch ( a1 )
  {
    case '0':
      sub_10DC24(dword_1153E8);
      break;
    case '@':
      sub_10DC24(dword_1153F0);
      break;
    case ' ':
      sub_10DC24(dword_1153EC);
      break;
    default:
      sub_10DC24(dword_1153DC);
      break;
  }
  sub_10DC24(dword_1153E0);
  sub_11512C();
  sub_10DC24(dword_1153E4);
  patch_apply_n4a8();
}

