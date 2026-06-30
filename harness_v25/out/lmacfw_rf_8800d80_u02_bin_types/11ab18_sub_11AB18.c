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

extern uint32_t off_11ABEC;
extern uint32_t off_11ABF0;
extern uint32_t off_11ABF4;
extern uint32_t dword_11AC00;
extern uint32_t off_11AC04;
extern uint32_t dword_11AC0C;
extern uint32_t dword_11AC08;
extern uint32_t off_11ABF8;
extern uint32_t dword_11ABFC;

// sub_11AB18 @ 0x11ab18, size 212 bytes
int  sub_11AB18(int a1, int a2)
{
  int *v4; // r7
  uint32_t *v5; // r2
  int *v6; // r6
  int v7; // r2
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r2
  uint32_t *v13; // r2
  int v14; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11ABEC = 1;
  }
  v4 = (int *)off_11ABF0;
  v5 = off_11ABF4;
  ++*(uint32_t *)off_11ABF0;
  if ( a2 - v5[4] < 0 )
  {
    msg_parse(dword_11AC00, *(uint32_t *)(a1 + 4));
    if ( **(int16_t **)off_11AC04 < 0 )
      rf_cmd_send_n264(dword_11AC0C, dword_11AC08, 131);
  }
  v6 = (int *)off_11ABF8;
  if ( a1 == *(uint32_t *)off_11ABF8 )
  {
    sub_11E7AC(off_11ABF8);
    v12 = dword_11ABFC;
    *(uint32_t *)(a1 + 12) = a2;
    result = list_insert_sorted(v6, a1, v12);
    v9 = *v6;
    if ( !*v6 )
    {
      *((uint32_t *)off_11ABF4 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  list_remove_node(off_11ABF8, a1);
  v7 = dword_11ABFC;
  *(uint32_t *)(a1 + 12) = a2;
  result = list_insert_sorted(v6, a1, v7);
  v9 = *v6;
  if ( a1 == *v6 )
  {
LABEL_14:
    v13 = off_11ABF4;
    v14 = *(uint32_t *)(v9 + 12);
    result = 0x40000;
    *((uint32_t *)off_11ABF4 + 2) = 0x40000;
    v13[12] = v14;
    v13[2] = 4;
  }
LABEL_6:
  if ( *v4 && (v10 = *v4 - 1, v11 = *(uint32_t *)off_11ABEC, (*v4 = v10) == 0) && v11 )
  {
    __enable_irq();
    if ( a2 - *((uint32_t *)off_11ABF4 + 4) < 0 )
      return irq_nesting_or(0x20000000);
  }
  else if ( a2 - *((uint32_t *)off_11ABF4 + 4) < 0 )
  {
    return irq_nesting_or(0x20000000);
  }
  return result;
}

