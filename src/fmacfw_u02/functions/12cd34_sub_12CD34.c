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


extern uint32_t dword_12CE58;
extern uint32_t dword_12CE64;
extern uint32_t off_12CE4C;
extern uint32_t off_12CE50;
extern uint32_t off_12CE5C;
extern uint32_t off_12CE60;
extern uint32_t off_12CE84;

// rx_phy_status_parse @ 0x12cd34, size 278 bytes
int  rx_phy_status_parse(unsigned int a1, int a2)
{
  uint16_t **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  uint16_t *v7; // r9
  int result; // r0
  int ( *v9)(uint32_t *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  uint32_t *v16; // r1
  int *v17; // r6

  v2 = (uint16_t **)off_12CE4C;
  v5 = a1 >> 8;
  v6 = (uint8_t)a1;
  if ( **(uint16_t **)off_12CE4C >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    mmio_clear_register((int)aTypeTaskMax, (int)aKeStateSet, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (uint16_t *)(((uint32_t *)(uintptr_t)off_12CE50)[4 * v6 + 2] + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      mmio_clear_register((int)aIdTaskMax, (int)aKeTaskLocal_0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_16;
  }
  mmio_clear_register((int)aKeTaskLocalTyp, (int)aKeStateSet, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v17 = &((uint32_t *)(uintptr_t)off_12CE50)[4 * v6];
  if ( *((uint16_t *)v17 + 7) > v5 )
  {
    v7 = (uint16_t *)(v17[2] + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  mmio_clear_register((int)aIdxTaskDescTyp, (int)aKeStateSet, 175);
  v7 = (uint16_t *)(v17[2] + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    mmio_clear_register((int)aKeStateidPtr, (int)aKeStateSet, 180);
LABEL_3:
  result = event_dispatch("\x80\x9Dset tsk:%x:%x\n", a1, a2);
  if ( (uint16_t)*v7 != a2 )
  {
    v9 = (int ( *)(uint32_t *, int))off_12CE84;
    v10 = dword_12CE58;
    v11 = (int *)off_12CE5C;
    *v7 = a2;
    while ( 1 )
    {
      result = (int)pkt_word_get(v10, v9, a1);
      v16 = (uint32_t *)result;
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_12CE60;
      v13 = dword_12CE64;
      ++*(uint32_t *)off_12CE60;
      cmd_handler_a(v13, v16);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      unknown_func_12d104(0x4000000);
    }
  }
  return result;
}
