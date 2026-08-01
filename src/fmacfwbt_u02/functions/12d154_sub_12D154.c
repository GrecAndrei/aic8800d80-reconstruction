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

extern uint32_t off_12D1FC;
extern uint32_t dword_12D20C;
extern uint32_t dword_12D204;
extern uint32_t dword_12D200;
extern uint32_t dword_12D214;
extern uint32_t dword_12D210;
extern uint32_t dword_12D218;
extern uint32_t dword_12D208;

// hci_cmd_send_vendor @ 0x12d154, size 168 bytes
int  hci_cmd_send_vendor(int a1, unsigned int a2)
{
  int16_t **v2; // r4
  int v4; // r7
  unsigned int v5; // r5
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  int v13; // r3

  v2 = (int16_t **)off_12D1FC;
  v4 = (uint8_t)a2;
  v5 = a2 >> 8;
  if ( **(int16_t **)off_12D1FC >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a2 > 0xDu )
  {
    mmio_irq_clear(dword_12D20C, dword_12D204, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12D200;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      mmio_irq_clear(dword_12D214, dword_12D210, 183);
  }
  else if ( (uint8_t)a2 != 13 )
  {
    goto LABEL_10;
  }
  mmio_irq_clear(dword_12D218, dword_12D204, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12D200;
  v13 = dword_12D200 + 16 * v4;
  v7 = 16 * v4;
  if ( *(uint16_t *)(v13 + 14) <= v5 )
    mmio_irq_clear(dword_12D208, dword_12D204, 269);
LABEL_3:
  v8 = *(uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(uint16_t *)(*(uint32_t *)(v9 + 8) + 2 * v5),
        (result = list_process_count(a1, (int *)v10, *(uint16_t *)(v10 + 4))) == 0) )
  {
    v12 = *(uint32_t *)(v9 + 4);
    if ( v12 )
      return list_process_count(a1, (int *)v12, *(uint16_t *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

