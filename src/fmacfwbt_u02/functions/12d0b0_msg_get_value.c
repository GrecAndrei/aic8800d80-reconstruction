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

extern uint32_t off_12D134;
extern uint32_t dword_12D144;
extern uint32_t dword_12D13C;
extern uint32_t dword_12D138;
extern uint32_t dword_12D14C;
extern uint32_t dword_12D148;
extern uint32_t dword_12D150;
extern uint32_t dword_12D140;

// hci_cmd_send_short @ 0x12d0b0, size 130 bytes
// Doc: hci_cmd_send_short [ipc]: Extracts a 16-bit value from a message indexed by id and sub-id
// hci_cmd_send_short [ipc]: Extracts a 16-bit value from a message indexed by id and sub-id
int  hci_cmd_send_short(unsigned int a1)
{
  int16_t **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (int16_t **)off_12D134;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(int16_t **)off_12D134 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    mmio_irq_clear(dword_12D144, dword_12D13C, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12D138;
      v5 = 16 * v3;
      return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      mmio_irq_clear(dword_12D14C, dword_12D148, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_6;
  }
  mmio_irq_clear(dword_12D150, dword_12D13C, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12D138;
  v7 = dword_12D138 + 16 * v3;
  v5 = 16 * v3;
  if ( *(uint16_t *)(v7 + 14) > v2 )
    return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  mmio_irq_clear(dword_12D140, dword_12D13C, 212);
  return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

