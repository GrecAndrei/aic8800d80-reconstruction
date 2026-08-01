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

extern uint32_t dword_13BE20;
extern uint32_t dword_13BE30;
extern uint32_t dword_13BE34;
extern uint32_t dword_13BE24;
extern uint32_t dword_13BE28;
extern uint32_t dword_13BE2C;

// ke_task_get @ 0x13bdb8, size 104 bytes
int  ke_task_get(unsigned int a1)
{
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v5; // r8
  int v6; // r0
  int v7; // r4

  v1 = dword_13BE20;
  v2 = dword_13BE20 + 32 * a1;
  v3 = *(uint8_t *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    wlan_ioctl_handler_3(dword_13BE30, (uint32_t *)v2);
    wlan_ioctl_handler_1(dword_13BE34, (uint32_t *)v2);
  }
  else
  {
    wlan_ioctl_handler_3(dword_13BE24, (uint32_t *)v2);
    wlan_ioctl_handler_1(dword_13BE28, (uint32_t *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = dword_13BE2C;
  hci_cmd_preprocess(v6 | 8, 4);
  *(uint8_t *)(v1 + v5 + 25) = 0;
  return init_state_table(v3, v2, 2, 0, 0, 39, v7);
}

