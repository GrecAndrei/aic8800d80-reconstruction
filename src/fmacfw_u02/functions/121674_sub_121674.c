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

extern uint32_t off_12173C;
extern uint32_t dword_121744;
extern uint32_t dword_121760;
extern uint32_t off_121748;
extern uint32_t off_121740;
extern uint32_t off_12174C;
extern uint32_t off_121750;
extern uint32_t off_121758;
extern uint32_t off_12175C;
extern uint32_t off_121754;

// get_core_rev @ 0x121674, size 198 bytes
uint32_t * get_core_rev(int a1)
{
  int v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2
  int *v5; // r1
  uint32_t *v6; // r5
  uint32_t *result; // r0
  int v8; // r5
  int v9; // r6
  uint32_t *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(uint32_t *)off_12173C) )
    return (uint32_t *)adjust_table_pointers(
                       dword_121744 + 1320 * ((a1 - (HIBYTE(*(uint32_t *)off_12173C) + 1)) / 2),
                       (((uint8_t)a1 - 1 - HIBYTE(*(uint32_t *)off_12173C)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_121760 + 696 * (uint8_t)(a1 - 16);
    v9 = *(uint8_t *)(v8 + 34);
    result = (uint32_t *)llm_conn_reset_state(v8);
    if ( *(uint8_t *)(dword_121744 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = off_121748;
    *(uint32_t *)off_121740 = *(uint16_t *)(v8 + 38) | (*(uint16_t *)(v8 + 40) << 16);
    *v10 = *(uint16_t *)(v8 + 42);
  }
  else
  {
    v2 = dword_121744;
    v3 = off_121748;
    *(uint32_t *)off_121740 = -1;
    *v3 = -1;
    adjust_table_pointers(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = off_12174C;
  v5 = (int *)off_121750;
  v6 = off_121758;
  result = off_12175C;
  *(uint32_t *)off_121754 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}

