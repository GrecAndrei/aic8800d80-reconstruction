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

extern uint32_t dword_114F14;
extern uint32_t dword_114F24;
extern uint32_t dword_114F2C;
extern uint32_t dword_114F28;
extern uint32_t dword_114F18;
extern uint32_t dword_114F1C;
extern uint32_t dword_114F20;

// sub_114ECC @ 0x114ecc, size 72 bytes
void  __noreturn sub_114ECC(int a1)
{
  sub_10DA6C(dword_114F14);
  switch ( a1 )
  {
    case '0':
      sub_10DA6C(dword_114F24);
      break;
    case '@':
      sub_10DA6C(dword_114F2C);
      break;
    case ' ':
      sub_10DA6C(dword_114F28);
      break;
    default:
      sub_10DA6C(dword_114F18);
      break;
  }
  sub_10DA6C(dword_114F1C);
  sub_114C68();
  sub_10DA6C(dword_114F20);
  rf_state_check_n_e90();
}

