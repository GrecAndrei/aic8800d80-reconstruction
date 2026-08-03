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

extern uint32_t off_1238AC;
extern uint32_t dword_1238BC;
extern uint32_t dword_1238B4;
extern uint32_t dword_1238B8;
extern uint32_t off_1238B0;

// sub_1237F4 @ 0x1237f4, size 184 bytes
// Doc: sub_12237F6 [ipc]: Dispatch helper: sends cmd 0x25 via event_queue then sets state
// sub_12237F6 [ipc]: Dispatch helper: sends cmd 0x25 via event_queue then sets state
int  sub_1237F4(int a1, uint8_t *a2, int a3, int a4)
{
  uint8_t *v5; // r0
  int16_t **v6; // r6
  uint8_t *v7; // r5
  int v8; // r3

  v5 = (uint8_t *)sub_12C92C(37, a4, a3, 2);
  v6 = (int16_t **)off_1238AC;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (sub_12F46C(dword_1238BC, dword_1238B4, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        sub_12F46C(dword_1238B8, dword_1238B4, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(uint32_t *)off_1238B0 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(uint32_t *)off_1238B0 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(uint32_t *)off_1238B0 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(uint32_t *)off_1238B0 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = sub_121418(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  sdio_buffer_prepare_n_4e8(v7);
  return 0;
}

