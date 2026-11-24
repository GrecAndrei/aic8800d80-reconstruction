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


extern uint32_t dword_127E8C;
extern uint32_t dword_127E90;
extern uint32_t off_127EA0;

// wlc_validate_chip_queue @ 0x127e00, size 138 bytes
int  wlc_validate_chip_queue(int a1)
{
  uint16_t **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r4
  int result; // r0

  v1 = (uint16_t **)off_127EA0;
  v2 = dword_127E8C;
  v4 = (int *)(dword_127E8C + 28 * a1);
  if ( **(uint16_t **)off_127EA0 < 0 )
  {
    v5 = 8 * a1;
    if ( *(uint8_t *)(dword_127E8C + 28 * a1 + 24) != 255
      || (mmio_clear_register((int)aCtxtIdxChanCtx, (int)aChanCtxtDel, 3044), **v1 < 0) )
    {
      if ( *(uint8_t *)(v2 + 4 * (v5 - a1) + 25) )
        mmio_clear_register((int)aCtxtNbLinkedVi, (int)aChanCtxtDel, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  cmd_handler_a(dword_127E90, v4);
  v6 = v2 + 4 * (v5 - a1);
  result = (int)memset(v4, 0, 0x1Cu);
  *(uint16_t *)(v6 + 14) = 255;
  *(uint8_t *)(v6 + 24) = -1;
  *(uint8_t *)(v6 + 27) = -1;
  return result;
}
