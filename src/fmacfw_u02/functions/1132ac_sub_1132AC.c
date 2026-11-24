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


extern uint32_t off_11332C;
extern uint32_t off_113330;
extern uint32_t off_113338;
extern uint32_t off_11333C;
extern uint32_t off_113340;
extern uint32_t off_113344;

// irq_state_load @ 0x1132ac, size 126 bytes
int  irq_state_load(int a1)
{
  uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  uint8_t *v5; // r1
  uint8_t *v6; // r2
  int v7; // r7
  int v8; // r1
  int v9; // r4

  if ( (*(uint32_t *)off_11332C & 0x2000000) != 0 )
  {
    memset((int *)off_113330, 0xFFu, 4u);
  }
  else
  {
    v2 = (uint16_t *)off_113330;
    memset((int *)off_113330, 0xFFu, 4u);
    if ( patch_get_field((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      event_dispatch(aNoUsbInfoInFla);
    else
      event_dispatch("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = off_11333C;
  v6 = off_113340;
  *(uint32_t *)off_113338 = *(uint32_t *)a1;
  v7 = off_113344;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v8 = *(uint8_t *)(a1 + 8);
    if ( *(uint8_t *)(a1 + 8) )
      v8 = 1;
    v9 = cmd_dispatch(v7, v8);
    event_dispatch("open res:%d\n", v9);
  }
  while ( v9 );
  return 0;
}
