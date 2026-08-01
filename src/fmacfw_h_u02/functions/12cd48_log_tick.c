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

extern uint32_t off_12CDCC;
extern uint32_t dword_12CDDC;
extern uint32_t dword_12CDD4;
extern uint32_t dword_12CDD0;
extern uint32_t dword_12CDE4;
extern uint32_t dword_12CDE0;
extern uint32_t dword_12CDE8;
extern uint32_t dword_12CDD8;

// hci_cmd_handler @ 0x12cd48, size 130 bytes
// Doc: hci_cmd_handler [util]: Append a tick/stamp entry to the log buffer
// hci_cmd_handler [util]: Append a tick/stamp entry to the log buffer
int  hci_cmd_handler(unsigned int a1)
{
  int16_t **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (int16_t **)off_12CDCC;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(int16_t **)off_12CDCC >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    irq_disable_mmio_write(dword_12CDDC, dword_12CDD4, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12CDD0;
      v5 = 16 * v3;
      return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      irq_disable_mmio_write(dword_12CDE4, dword_12CDE0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_6;
  }
  irq_disable_mmio_write(dword_12CDE8, dword_12CDD4, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12CDD0;
  v7 = dword_12CDD0 + 16 * v3;
  v5 = 16 * v3;
  if ( *(uint16_t *)(v7 + 14) > v2 )
    return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  irq_disable_mmio_write(dword_12CDD8, dword_12CDD4, 212);
  return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

