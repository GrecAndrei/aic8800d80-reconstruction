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

extern uint32_t off_1290A8;
extern uint32_t off_1290AC;
extern uint32_t off_1290A4;
extern uint32_t off_1290B0;
extern uint32_t off_1290BC;
extern uint32_t off_1290B8;
extern uint32_t dword_1290C0;
extern uint32_t off_1290B4;

// efuse_check @ 0x128fe8, size 186 bytes
void  efuse_check(int a1)
{
  uint8_t *v1; // r5
  uint64_t v3; // r2
  BOOL v4; // r0
  uint32_t *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = off_1290A8;
  LODWORD(v3) = *((uint32_t *)off_1290AC + 126);
  HIDWORD(v3) = *((uint32_t *)off_1290A8 + 1) & 0x20;
  if ( **(uint8_t **)off_1290A4 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = ll_util_get_state() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(uint8_t *)(a1 + 149) )
  {
    if ( !**(uint8_t **)off_1290B0 || !*(uint8_t *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(uint32_t *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = off_1290BC;
    v6 = *(uint32_t *)off_1290B8;
    *((uint32_t *)v1 + 5) = a1;
    v7 = *(uint16_t *)(v6 + 54);
    v8 = dword_1290C0;
    v1[29] = 1;
    ke_event_lock(v8, v7 + v5[4]);
    return;
  }
  if ( !**(uint8_t **)off_1290B0 || !*(uint8_t *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(uint32_t *)off_1290B4 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(uint32_t *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    handle_mmio_event();
  else
    v1[29] = 0;
}

