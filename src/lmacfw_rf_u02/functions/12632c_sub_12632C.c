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


extern uint32_t off_126424;
extern uint32_t off_12642C;
extern uint32_t off_126430;
extern uint32_t off_126434;
extern uint32_t off_126438;
extern uint32_t off_12643C;
extern uint32_t off_126440;
extern uint32_t off_126444;
extern uint32_t off_126448;
extern uint32_t off_12644C;
extern uint32_t off_126450;
extern uint32_t off_126458;

// ll_state_reset @ 0x12632c, size 248 bytes
int ll_state_reset()
{
  int v0; // r4
  char *v1; // r8
  uint16_t *v2; // r5
  int v3; // r1
  uint8_t *v4; // r5
  uint16_t *v5; // r4
  uint32_t *v6; // r0
  uint32_t *v7; // r2
  uint32_t *v8; // r2
  unsigned int *v9; // r4
  int v10; // r1
  int result; // r0
  unsigned int v12; // r3
  int *v13; // r3
  int v14; // r3
  uint32_t *v15; // r3

  *(uint8_t *)off_126424 = 0;
  dispatch_event_handler_1("cob state -> %d\n", 0);
  v0 = *(uint8_t *)off_12642C;
  if ( v0 == 1 )
  {
    v15 = off_126450;
    *(uint32_t *)off_126450 &= ~0x100u;
    *v15 &= ~0x200u;
    *v15 &= ~0x400u;
    goto LABEL_15;
  }
  if ( *(uint8_t *)off_12642C )
  {
LABEL_15:
    dispatch_event_handler_1(
      "dut%d,%d,%d,%d,%d,%d\n",
      *(uint8_t *)off_126434,
      *(uint16_t *)off_126430,
      *((uint8_t *)off_126430 + 2),
      *((char *)off_126430 + 3),
      *((char *)off_126430 + 4),
      *((char *)off_126430 + 5));
    goto LABEL_7;
  }
  v1 = off_126458;
  if ( *off_126458 )
  {
    v2 = (uint16_t *)off_126430;
    v3 = *(uint8_t *)off_12642C;
    do
    {
      dispatch_event_handler_1(
        "dut%d,%d,%d,%d,%d,%d\n",
        v3 + 1,
        v2[4 * v3],
        LOBYTE(v2[4 * v3 + 1]),
        SHIBYTE(v2[4 * v3 + 1]),
        SLOBYTE(v2[4 * v3 + 2]),
        SHIBYTE(v2[4 * v3 + 2]));
      v3 = (uint8_t)++v0;
    }
    while ( (uint8_t)*v1 > (unsigned int)(uint8_t)v0 );
  }
  v4 = (uint8_t *)off_126434;
  v5 = off_126438;
  memset_thunk((int *)off_126430, 0, 8u);
  v6 = off_12643C;
  v7 = off_126440;
  *v4 = 1;
  *v1 = 1;
  *v5 = 0;
  *v6 = 0;
  *v7 = 0;
LABEL_7:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_126444 = 1;
  }
  v8 = off_126448;
  v9 = (unsigned int *)off_12644C;
  v10 = *(uint32_t *)off_126448;
  result = *(uint32_t *)off_126448 + 1;
  v12 = *(uint32_t *)off_12644C & 0xFFFFFBFF;
  *(uint32_t *)off_126448 = result;
  *v9 = v12;
  if ( result )
  {
    v13 = (int *)off_126444;
    *v8 = v10;
    v14 = *v13;
    if ( !v10 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}
