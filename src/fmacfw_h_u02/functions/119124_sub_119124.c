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


extern uint32_t dword_119244;
extern uint32_t dword_119258;
extern uint32_t off_11923C;
extern uint32_t off_119240;

// btm_chk_state @ 0x119124, size 278 bytes
int  btm_chk_state(int a1, char *a2)
{
  int v2; // r3
  int v3; // r3
  int v6; // r3
  BOOL v7; // r0
  int v8; // r8
  uint32_t *v9; // r0
  int v10; // r6
  int v11; // r5
  uint16_t *v12; // r2
  uint16_t v13; // r3
  uint16_t v14; // r1
  int v15; // r0

  v2 = *(uint8_t *)(a1 + 106);
  if ( v2 != 2 )
  {
    alloc_tx_event("vif type error:%d\n", v2);
    return 1;
  }
  v3 = *(uint32_t *)(a1 + 72);
  if ( v3 )
  {
    v6 = *(uint8_t *)(v3 + 4);
    if ( **(uint16_t **)off_11923C >= 0 || v6 != 2 )
    {
      v7 = (v6 | *(uint8_t *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(uint16_t **)off_11923C >= 0 )
  {
    goto LABEL_9;
  }
  irq_disable_mmio_write((int)aBandPhyBandMax_0, (int)aVifMgmtGetTxty, 520);
LABEL_9:
  v7 = 1;
LABEL_5:
  v8 = dword_119258;
  v9 = lock_acquire(v7, *(uint16_t *)(dword_119258 + 2 * *(uint8_t *)(a1 + 107)));
  v10 = (int)v9;
  if ( v9 )
  {
    get_status_flag_c5(a1, (int)v9);
    v11 = *(uint32_t *)(v10 + 72);
    *(uint8_t *)(v11 + 108) = 80;
    *(uint8_t *)(v11 + 109) = 0;
    *(uint8_t *)(v11 + 110) = 0;
    *(uint8_t *)(v11 + 111) = 0;
    memcpy_1((char *)(v11 + 112), a2, 6u);
    v12 = off_119240;
    v13 = *((uint16_t *)off_119240 + 254);
    v14 = *(uint16_t *)(a1 + 104);
    *(uint32_t *)(v11 + 118) = *(uint32_t *)(a1 + 100);
    ++v13;
    v15 = *(uint32_t *)(a1 + 100);
    *(uint16_t *)(v11 + 122) = v14;
    *(uint32_t *)(v11 + 124) = v15;
    *(uint16_t *)(v11 + 128) = v14;
    v12[254] = v13;
    *(uint16_t *)(v11 + 130) = 16 * v13;
    memcpy_1(
      (char *)(v11 + 132),
      (char *)(dword_119244 + (*(uint8_t *)(a1 + 107) << 9)),
      *(uint16_t *)(v8 + 2 * *(uint8_t *)(a1 + 107)) - 24);
    *(uint32_t *)(v10 + 88) = 0;
    *(uint32_t *)(v10 + 92) = 0;
    *(uint8_t *)(v10 + 28) = *(uint8_t *)(a1 + 107);
    *(uint8_t *)(v10 + 29) = -1;
    sec_check(v10, 5);
    return 0;
  }
  else
  {
    alloc_tx_event("no probe buf:%d\n", *(uint16_t *)(v8 + 2 * *(uint8_t *)(a1 + 107)));
    return 1;
  }
}
