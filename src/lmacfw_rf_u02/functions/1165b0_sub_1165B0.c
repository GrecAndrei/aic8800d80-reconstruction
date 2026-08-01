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

extern uint32_t off_116600;
extern uint32_t dword_116608;
extern uint32_t dword_116604;

// wlan_tx_submit @ 0x1165b0, size 78 bytes
// Doc: sub_12165B0 [rf]: LMAC RF helper, checks flag and dispatches operation
// sub_12165B0 [rf]: LMAC RF helper, checks flag and dispatches operation
int  wlan_tx_submit(int a1, int a2)
{
  uint64_t v2; // kr00_8
  int v5; // r2

  v2 = *(uint64_t *)(a1 + 28);
  if ( **(int16_t **)off_116600 < 0 && (*(uint32_t *)(HIDWORD(v2) + 24) & 1) != 0 )
    flash_ctrl_init(dword_116608, dword_116604, 389);
  v5 = *(uint32_t *)(HIDWORD(v2) + 40);
  *(uint32_t *)(HIDWORD(v2) + 64) &= 0xFF87FFFF;
  *(uint64_t *)(HIDWORD(v2) + 12) = 0;
  *(uint32_t *)(HIDWORD(v2) + 60) = 0;
  *(uint32_t *)(HIDWORD(v2) + 68) = 0;
  *(uint32_t *)(v2 + 96) = 0;
  *(uint32_t *)(v2 + 100) = v5;
  return llm_scan_pdu_cfg(a1, a2);
}

