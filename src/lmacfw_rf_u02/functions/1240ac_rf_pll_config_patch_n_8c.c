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

extern uint32_t off_124130;
extern uint32_t off_124134;
extern uint32_t dword_12413C;
extern uint32_t dword_124140;
extern uint32_t dword_124144;
extern uint32_t dword_124148;
extern uint32_t dword_124138;
extern uint32_t dword_12414C;

// rf_pll_config_patch_n_8c @ 0x1240ac, size 130 bytes
// Doc: rf_pll_config_patch_n_8c [rf]: Configures RF PLL/clock registers by clearing mask bits 0x30000 and 0x600
// rf_pll_config_patch_n_8c [rf]: Configures RF PLL/clock registers by clearing mask bits 0x30000 and 0x600
int  rf_pll_config_patch_n_8c(int a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  int v5; // r0
  int result; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v1 = (unsigned int *)off_124130;
  v2 = (unsigned int *)off_124134;
  v3 = *(uint32_t *)off_124130 & 0xFFFCFFFF;
  v4 = *(uint32_t *)off_124134 & 0xFFFFF9FF;
  *(uint32_t *)off_124134 = v4;
  *v1 = v3;
  switch ( a1 )
  {
    case 0:
      msg_parse(dword_12413C);
      result = 0;
      break;
    case 1:
      v7 = dword_124140;
      *v1 = v3 | 0x10000;
      msg_parse(v7);
      result = 0;
      break;
    case 2:
      v8 = dword_124144;
      *v1 = v3 | 0x10000;
      *v2 = v4 | 0x200;
      msg_parse(v8);
      result = 0;
      break;
    case 3:
      v9 = dword_124148;
      *v1 = v3 | 0x20000;
      msg_parse(v9);
      result = 0;
      break;
    case 4:
      v5 = dword_124138;
      *v1 = v3 | 0x20000;
      *v2 = v4 | 0x400;
      msg_parse(v5);
      goto LABEL_3;
    default:
      msg_parse(dword_12414C);
LABEL_3:
      result = 0;
      break;
  }
  return result;
}

