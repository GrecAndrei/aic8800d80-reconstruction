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


extern uint32_t dword_12C18C;
extern uint32_t dword_12C190;
extern uint32_t off_12C184;
extern uint32_t off_12C188;
extern uint32_t off_12C194;
extern uint32_t off_12C1A0;
extern uint32_t off_12C1A4;
extern uint32_t off_12C1A8;

// irq_combined_status @ 0x12bff0, size 402 bytes
void irq_combined_status()
{
  int v0; // r4
  int v1; // r3
  int v2; // r5

  v0 = *(uint32_t *)off_12C188 & *(uint32_t *)off_12C184;
  v1 = dword_12C18C & v0;
  *((uint32_t *)off_12C184 + 1) = v0;
  if ( v1 )
    unknown_func_12d104(0x1000000);
  if ( (dword_12C190 & v0) != 0 )
    unknown_func_12d104(0x800000);
  if ( (v0 & 4) != 0 )
    read_cal_value();
  if ( (v0 & 8) != 0 )
    mmio_copy_reg();
  if ( (v0 & 0x10000000) != 0 )
  {
    v2 = *(uint32_t *)off_12C1A0;
    *((uint8_t *)off_12C1A4 + 30) |= *(uint8_t *)off_12C1A0 & 0x3F;
    unknown_func_12d104(0x40000);
    *(uint32_t *)off_12C1A8 = v2;
  }
  if ( **(uint16_t **)off_12C194 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_0, (int)aHalMachwGenHan, 847);
    }
    else if ( (v0 & 0x200000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_1, (int)aHalMachwGenHan, 848);
    }
    else if ( (v0 & 0x40) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_2, (int)aHalMachwGenHan, 849);
    }
    else if ( (v0 & 0x100) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_3, (int)aHalMachwGenHan, 850);
    }
    else if ( (v0 & 0x1000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_4, (int)aHalMachwGenHan, 851);
    }
    else if ( (v0 & 0x2000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_5, (int)aHalMachwGenHan, 852);
    }
    else if ( (v0 & 0x4000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_6, (int)aHalMachwGenHan, 853);
    }
    else if ( (v0 & 0x8000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_7, (int)aHalMachwGenHan, 854);
    }
    else if ( (v0 & 0x10000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_8, (int)aHalMachwGenHan, 855);
    }
    else if ( (v0 & 0x20000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_9, (int)aHalMachwGenHan, 856);
    }
    else if ( (v0 & 0x1000000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_10, (int)aHalMachwGenHan, 857);
    }
    else if ( (v0 & 0x2000000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_11, (int)aHalMachwGenHan, 858);
    }
    else if ( (v0 & 0x100000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_12, (int)aHalMachwGenHan, 859);
    }
    else if ( (v0 & 0x8000000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN, (int)aHalMachwGenHan, 860);
    }
  }
}
