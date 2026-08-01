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

extern uint32_t dword_13BD6C;
extern uint32_t dword_13BD70;
extern uint32_t dword_13BD7C;
extern uint32_t dword_13BD80;
extern uint32_t dword_13BD74;
extern uint32_t dword_13BD78;

// sdio_rd_reg @ 0x13bcc4, size 168 bytes
// Doc: sdio_rd_reg [bt]: Allocates and sends HCI command with opcode from r0
// sdio_rd_reg [bt]: Allocates and sends HCI command with opcode from r0
uint32_t * sdio_rd_reg(unsigned int a1)
{
  int v1; // r5
  int v3; // r1
  uint8_t *v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r3
  uint32_t *v8; // r1
  uint32_t *v10; // [sp+4h] [bp-8h]

  v1 = (a1 << 8) | 8;
  irq_lock(0x2000, v1);
  irq_lock(8194, v1);
  v3 = dword_13BD6C;
  v4 = (uint8_t *)(dword_13BD6C + 32 * a1);
  v5 = v4[17];
  v6 = v4[16];
  v7 = v4[22];
  if ( v5 )
  {
    if ( v5 == 1 )
      *(uint8_t *)(696 * v6 + 12 * v7 + dword_13BD70 + 453) = 33;
    v8 = (uint32_t *)(v3 + 32 * a1);
    v10 = v8;
    if ( a1 <= 0xF )
      goto LABEL_5;
LABEL_7:
    check_abort_flag_3(dword_13BD7C, v8);
    check_abort_flag(dword_13BD80, v10);
    return hci_cmd_send(v1, 0);
  }
  v8 = (uint32_t *)(dword_13BD6C + 32 * a1);
  *(uint8_t *)(696 * v6 + 12 * v7 + dword_13BD70 + 452) = 33;
  v10 = v8;
  if ( a1 > 0xF )
    goto LABEL_7;
LABEL_5:
  check_abort_flag_3(dword_13BD74, v8);
  check_abort_flag(dword_13BD78, v10);
  return hci_cmd_send(v1, 0);
}

