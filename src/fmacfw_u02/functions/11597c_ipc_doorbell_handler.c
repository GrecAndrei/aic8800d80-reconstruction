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

extern uint32_t off_115AB4;
extern uint32_t off_115ABC;
extern uint32_t off_115AD4;
extern uint32_t off_115AD8;
extern uint32_t off_115AE0;
extern uint32_t off_115ACC;

// gpio_read_input @ 0x11597c, size 300 bytes
// Doc: ipc_doorbell_irq_handler_5a6a [ipc]: Handles IPC doorbell interrupt by setting MMIO flags
// ipc_doorbell_irq_handler_5a6a [ipc]: Handles IPC doorbell interrupt by setting MMIO flags
uint8_t *gpio_read_input()
{
  uint32_t *v0; // r4
  uint8_t *v1; // r5
  int v2; // r1
  uint32_t *v3; // r2
  uint32_t *v4; // r2
  uint8_t *v5; // r1
  int v6; // r1
  uint32_t *v7; // r2
  uint32_t *v8; // r1
  uint8_t **v9; // r1
  int v10; // r3
  uint8_t *result; // r0
  int v12; // r2
  uint32_t *v13; // r3
  uint32_t *v14; // r3
  uint32_t *v15; // r3

  v0 = ipc_doorbell_handler_n12c;
  v1 = ipc_doorbell_handler_aac;
  v2 = ipc_doorbell_handler_n134;
  *(uint8_t *)ipc_doorbell_handler_aac = *(uint8_t *)ipc_doorbell_handler_n12c & 0xF;
  check_status_bits(2, v2);
  if ( *v0 << 28 )
  {
    v3 = ipc_doorbell_handler_n13c;
    *(uint32_t *)off_115AB4 &= ~0x80000000;
    *v0 = 0;
    while ( (*v3 & 4) == 0 )
      ;
    v4 = off_115AB4;
    v5 = (uint8_t *)ipc_doorbell_handler_n144;
    *(uint32_t *)off_115ABC = 4;
    v6 = v5[189];
    *v4 |= 0x80000000;
    if ( v6 )
      *(uint32_t *)((char *)v4 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(uint32_t *)ipc_doorbell_handler_3 &= ~0x8000000u;
  }
  v7 = ipc_doorbell_handler_n148;
  v8 = ipc_doorbell_handler_n12c;
  *(uint32_t *)ipc_doorbell_handler_n148 |= 0x111u;
  v1[1] = 1;
  *v8 = 32;
  v9 = (uint8_t **)ipc_doorbell_handler_n14c;
  *v7 &= 0xFFFFFEEE;
  v10 = **v9;
  if ( v10 == 3 )
  {
    v14 = off_115AD4;
    *(uint32_t *)off_115AD4 |= 1u;
    if ( (*v14 & 4) != 0 )
      *(uint32_t *)off_115AD8 = 512;
  }
  else if ( v10 == 1 )
  {
    ipc_wait_flag();
    v15 = off_115AE0;
    *(uint32_t *)ipc_doorbell_isr_entry |= 0x20u;
    v15[20] |= 0x20000u;
    v15[20] |= 0x8000u;
    v15[20] |= 0x10000u;
    v15[20] = v15[20] & 0xFFFFFFC0 | 0x37;
    v15[23] = v15[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_115ACC;
  v12 = 0;
  *(uint8_t *)off_115ACC = 0;
  while ( 1 )
  {
    v13 = (uint32_t *)(4 * v12++ - 536813312);
    if ( (v13[64] & *v13) != 0 )
      break;
    if ( v12 == 3 )
      return result;
  }
  *result = 1;
  return result;
}

