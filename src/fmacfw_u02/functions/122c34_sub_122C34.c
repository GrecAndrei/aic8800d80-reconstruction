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

extern uint32_t dword_122C94;
extern uint32_t off_122C90;
extern uint32_t dword_122C9C;
extern uint32_t dword_122C98;

// hci_read_variant @ 0x122c34, size 92 bytes
int  hci_read_variant(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r5
  int v9; // r0

  v4 = dword_122C94;
  v6 = *a2;
  if ( **(int16_t **)off_122C90 < 0 && *(uint8_t *)(dword_122C94 + 1320 * v6 + 106) )
    mmio_clear_register(dword_122C9C, dword_122C98, 2639);
  v9 = v4 + 1320 * v6;
  *(uint16_t *)(v9 + 112) = *((uint16_t *)a2 + 1);
  *(uint8_t *)(v9 + 114) = a2[4];
  ke_msg_send_no_param(76, a4, a3);
  return 0;
}

