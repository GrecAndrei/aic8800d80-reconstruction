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

extern uint32_t dword_136E94;

// txpwr_cal_entry_get @ 0x136e40, size 84 bytes
// Doc: sub_1236E40 [mac]: FMAC behavioral routine indexed by mla with stride 0x2b8
// sub_1236E40 [mac]: FMAC behavioral routine indexed by mla with stride 0x2b8
int  txpwr_cal_entry_get(int result, int a2)
{
  int v2; // r4
  char v3; // r1
  int v4; // r0
  int16_t v5; // r1

  if ( *(uint8_t *)(result + 106) == 2 )
  {
    v2 = dword_136E94 + 696 * a2;
    result = wlc_bsscfg_down(result, v2, 0);
    v3 = *(uint8_t *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(uint8_t *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = bt_buf_alloc(65, 0, 5, 4u);
        v5 = *(uint16_t *)(v2 + 32);
        *(uint8_t *)(v4 + 3) = *(uint8_t *)(v2 + 34);
        *(uint8_t *)(v4 + 2) = 0;
        *(uint16_t *)v4 = v5;
        return hci_evt_send(v4);
      }
    }
  }
  return result;
}

