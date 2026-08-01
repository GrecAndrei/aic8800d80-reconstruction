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

extern uint32_t off_122D30;
extern uint32_t off_122D34;
extern uint32_t off_122D38;
extern uint32_t off_122D3C;
extern uint32_t off_122D40;
extern uint32_t off_122D48;
extern uint32_t off_122D44;

// check_command_permitted @ 0x122c98, size 152 bytes
int  check_command_permitted(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r4
  uint8_t *v7; // r4
  uint32_t *v8; // r6
  uint32_t *v9; // r5
  unsigned int v10; // r3
  void *v11; // r3
  uint32_t *v13; // r6
  uint32_t *v14; // r5

  v4 = *a2;
  if ( v4 && *((uint8_t *)off_122D30 + 177) )
  {
    v7 = off_122D34;
    v13 = off_122D38;
    v14 = off_122D3C;
    *(uint8_t *)off_122D34 = 1;
    *v13 |= 0x2000000u;
    v14[14] |= 0x10u;
  }
  else
  {
    v7 = off_122D34;
    v8 = off_122D38;
    v9 = off_122D3C;
    *(uint8_t *)off_122D34 = 0;
    *v8 &= ~0x2000000u;
    v9[14] &= ~0x10u;
  }
  *(uint32_t *)off_122D38 &= ~0x800u;
  v7[2] = 0;
  if ( a2[2] )
    v10 = *(uint32_t *)off_122D40 | 0x80000000;
  else
    v10 = *(uint32_t *)off_122D40 & 0x7FFFFFFF;
  *(uint32_t *)off_122D40 = v10;
  v11 = (void *)a2[4];
  if ( a2[4] )
  {
    v11 = off_122D48;
    *(uint32_t *)off_122D44 = *((uint32_t *)a2 + 2);
    *(uint32_t *)v11 &= 0xFFFFFu;
    *(uint32_t *)v11 |= *((uint32_t *)a2 + 3) << 20;
  }
  hci_evt_alloc_send(102, a4, a3, v11);
  return 0;
}

