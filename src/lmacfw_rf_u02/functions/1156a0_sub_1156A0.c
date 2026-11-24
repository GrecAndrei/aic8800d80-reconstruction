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


extern uint32_t dword_115740;
extern uint32_t dword_115744;
extern uint32_t off_11573C;
extern uint32_t off_115750;

// pdu_type_init @ 0x1156a0, size 154 bytes
int  pdu_type_init(int a1, int a2, int a3, int a4)
{
  int *v5; // r5
  int v6; // r3
  void *v9; // r8
  int result; // r0

  if ( a3 != 5 )
    a4 = 7 * a3;
  if ( a3 == 5 )
    v5 = (int *)dword_115744;
  else
    v5 = (int *)dword_115740;
  if ( a3 != 5 )
    v5 += a4;
  v6 = *v5;
  if ( **(uint16_t **)off_11573C < 0 && v6 == a1 )
    return ke_int_lock_1((int)aPrevHdFirstThd, (int)aTxlFrameExchan, 1972);
  if ( v6 )
  {
    v9 = off_115750;
    if ( *(uint8_t *)(*(uint32_t *)off_115750 + 1) || !v5[2] )
      *(uint32_t *)(v6 + 4) = a1;
    else
      *(uint32_t *)(v5[1] + 4) = a1;
    result = radio_pdu_type_cfg(a3);
  }
  else
  {
    result = (int)adv_pdu_type_handler(a1, a3);
    v9 = off_115750;
  }
  if ( !*(uint8_t *)(*(uint32_t *)v9 + 1) )
  {
    if ( (*(uint32_t *)(a2 + 56) & 0x200000) != 0 )
    {
      v5[1] = a1;
      v5[2] = 1;
    }
    else
    {
      v5[1] = 0;
      v5[2] = 0;
    }
  }
  *(uint32_t *)(dword_115740 + 28 * a3) = a2;
  return result;
}
