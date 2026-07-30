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

extern uint32_t off_119C3C;
extern uint32_t off_119C40;
extern uint32_t dword_119C48;
extern uint32_t dword_119C44;

// sub_119BF8 @ 0x119bf8, size 66 bytes
// Doc: rf_param_handler [rf]: Validates and dispatches RF parameter configuration
// rf_param_handler [rf]: Validates and dispatches RF parameter configuration
int  sub_119BF8(int a1, uint8_t *a2, int a3, int a4)
{
  unsigned int v7; // r0

  if ( **(int16_t **)off_119C3C < 0 )
  {
    v7 = *a2;
    if ( v7 <= HIBYTE(*(uint32_t *)off_119C40) )
      goto LABEL_3;
    rf_cmd_send_n264(dword_119C48, dword_119C44, 1803);
  }
  v7 = *a2;
LABEL_3:
  sub_118C90(v7);
  sub_11DED8(39, a4, a3);
  return 0;
}

