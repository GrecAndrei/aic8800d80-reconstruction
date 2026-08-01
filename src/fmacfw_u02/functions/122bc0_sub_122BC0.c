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

extern uint32_t dword_122C28;
extern uint32_t off_122C24;
extern uint32_t dword_122C30;
extern uint32_t dword_122C2C;

// hci_read_command @ 0x122bc0, size 98 bytes
int  hci_read_command(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r4
  uint8_t *v9; // r4

  v4 = dword_122C28;
  v6 = *a2;
  if ( **(int16_t **)off_122C24 < 0 && *(uint8_t *)(dword_122C28 + 1320 * v6 + 106) )
    mmio_clear_register(dword_122C30, dword_122C2C, 3702);
  v9 = (uint8_t *)(v4 + 1320 * v6);
  v9[143] = a2[1];
  v9[144] = a2[2];
  v9[145] = 0;
  ke_msg_send_no_param(134, a4, a3);
  return 0;
}

