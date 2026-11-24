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


extern uint32_t off_1151BC;
extern uint32_t off_1151C4;

// apply_patch_table @ 0x114fec, size 464 bytes
int apply_patch_table()
{
  uint32_t *v0; // r7
  int *v1; // r5
  int i; // r4
  int v3; // r1
  int v4; // t1
  uint32_t *v5; // r5
  unsigned int v6; // r4
  int v7; // r3
  int v8; // r1
  int result; // r0
  int v10; // r4
  int v11; // r4
  unsigned int v12; // r4
  unsigned int v13; // r5
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v0 = off_1151BC;
  v1 = (int *)off_1151BC;
  for ( i = 0; i != 13; ++i )
  {
    v3 = i;
    v4 = *v1++;
    debug_printf("\nR%-4d: %08X", v3, v4);
  }
  v5 = off_1151C4;
  debug_printf(aSp08xLr08xPc08, v0[13], v0[14], v0[15], v0[16], v0[17], v0[18]);
  debug_printf("\nCPUID: %08X\nICSR : %08X\nVTOR : %08X\nAIRCR: %08X", *v5, v5[1], v5[2], v5[3]);
  debug_printf(
    "\nSHCSR: %08X\nCFSR : %08X\nHFSR : %08X\nDFSR : %08X\nAFSR : %08X",
    v5[9],
    v5[10],
    v5[11],
    v5[12],
    v5[15]);
  v6 = v5[10];
  if ( (uint8_t)v6 )
  {
    debug_printf(
      "\nMMFSR: %02X\n  IACCVIOL :%d\tDACCVIOL :%d\n  MUNSTKERR:%d\tMSTKERR  :%d\n  MLSPERR  :%d\tMMARVALID:%d",
      (uint8_t)v5[10],
      v6 & 1,
      (v6 >> 1) & 1,
      (v6 >> 3) & 1,
      (v6 >> 4) & 1,
      (v6 >> 5) & 1,
      (v6 >> 7) & 1);
    if ( (v6 & 0x80) != 0 )
      debug_printf("\nMMFAR: %08X", v5[13]);
  }
  if ( (v6 & 0xFF00) != 0 )
  {
    debug_printf(
      "\n"
      "BFSR : %02X\n"
      "  IBUSERR    :%d\tPRECISERR:%d\n"
      "  IMPRECISERR:%d\tUNSTKERR :%d\n"
      "  STKERR     :%d\tLSPERR   :%d\n"
      "  BFARVALID  :%d",
      BYTE1(v6),
      (v6 >> 8) & 1,
      (v6 >> 9) & 1,
      (v6 >> 10) & 1,
      (v6 >> 11) & 1,
      (v6 >> 12) & 1,
      (v6 >> 13) & 1,
      (v6 >> 15) & 1);
    if ( (v6 & 0x8000) != 0 )
      debug_printf("\nBFAR : %08X", *((uint32_t *)off_1151C4 + 14));
  }
  if ( HIWORD(v6) )
    debug_printf(
      "\nUFSR : %04X\n  UNDEFINSTR:%d\tINVSTATE :%d\n  INVPC     :%d\tNOCP     :%d\n  UNALIGNED :%d\tDIVBYZERO:%d",
      HIWORD(v6),
      HIWORD(v6) & 1,
      (v6 >> 17) & 1,
      (v6 >> 18) & 1,
      (v6 >> 19) & 1,
      HIBYTE(v6) & 1,
      (v6 >> 25) & 1);
  if ( (v0[19] & 8) == 0 )
  {
    debug_printf(aModeHandler);
    goto LABEL_9;
  }
  debug_printf(aModeThread);
  if ( (v0[20] & 1) == 0 )
  {
LABEL_9:
    debug_printf(aPrivPrivileged);
    goto LABEL_10;
  }
  debug_printf(aPrivUser);
LABEL_10:
  v7 = v0[19];
  v8 = v7 << 29;
  if ( (v7 & 4) != 0 )
    debug_printf(aStackPsp, v8);
  else
    debug_printf(aStackMsp, v8);
  result = debug_printf(aCntrl08xPmask0, v0[20], __get_CPSR(), __get_CPSR(), __get_CPSR());
  v10 = v0[18];
  if ( v10 )
  {
    v15 = v10 & 0xFFFFFFF0;
    debug_printf(aDumpmsp_0);
    v16 = v15 + 256;
    do
    {
      if ( !(v15 << 28) )
        debug_printf("\n[%08x]:", v15);
      v17 = *(uint32_t *)v15;
      v15 += 4;
      result = debug_printf(" %08X", v17);
    }
    while ( v16 != v15 );
  }
  v11 = v0[17];
  if ( v11 )
  {
    v12 = v11 & 0xFFFFFFF0;
    debug_printf(aDumppsp_0);
    v13 = v12 + 256;
    do
    {
      if ( !(v12 << 28) )
        debug_printf("\n[%08x]:", v12);
      v14 = *(uint32_t *)v12;
      v12 += 4;
      result = debug_printf(" %08X", v14);
    }
    while ( v13 != v12 );
  }
  return result;
}
