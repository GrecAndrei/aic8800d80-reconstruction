// sub_108D34 @ 0x108d34, size 492 bytes
_DWORD *__fastcall sub_108D34(int a1, int a2)
{
  _DWORD *v2; // r2
  unsigned int *v3; // r3
  _DWORD *v4; // r12
  _DWORD *v5; // r6
  unsigned int *v6; // r7
  unsigned int *v7; // r4
  _DWORD *v8; // lr
  int v9; // r11
  int v10; // r10
  int v11; // r6
  int *v12; // r5
  int v15; // r9
  int i; // r4
  int v17; // lr
  int v18; // r1
  int v19; // r12
  unsigned int *v20; // r3
  _DWORD *result; // r0
  _DWORD *v22; // r2
  int v23; // [sp+0h] [bp-Ch] BYREF
  int v24; // [sp+4h] [bp-8h] BYREF

  v2 = off_108F20;
  v3 = (unsigned int *)off_108F24;
  v4 = off_108F40;
  v5 = off_108F28;
  v6 = (unsigned int *)off_108F2C;
  v7 = (unsigned int *)off_108F30;
  v8 = off_108F38;
  v9 = dword_108F44;
  v10 = dword_108F48;
  *(_DWORD *)off_108F20 &= ~4u;
  *v5 &= 0xFFFF0FFF;
  v11 = 0;
  *v6 = 0;
  *v3 |= 0x80u;
  *v7 |= 0x80000000;
  *v2 |= 4u;
  v6 -= 6154;
  *v4 = HIWORD(*v4) << 16;
  *v6 = *v6 & 0xCFFFFFFF | 0x10000000;
  *v2 &= ~4u;
  *v7 &= ~0x80000000;
  *v3 &= ~0x80u;
  *v2 |= 4u;
  v12 = (int *)off_108F34;
  *v8 |= 2u;
  *v3 = *v3 & 0xFFFF8FFF | 0x4000;
  *v3 = *v3 & 0xF8FFFFFF | 0x6000000;
  *v3 = *v3 & 0xFFFFF8FF | 0x100;
  *v3 &= ~4u;
  *v3 |= 1u;
  *v3 |= 8u;
  *v7 = ((unsigned int)v6 + 1059082178) | *v7 & 0x80000000;
  v15 = ((v4[8208] >> 3) & 7) << 6;
  for ( i = 0; i != 16; ++i )
  {
    while ( ((a1 >> i) & 1) == 0 )
    {
      if ( ++i == 16 )
        goto LABEL_7;
    }
    *v12 = *v12 & v9 | ((__int16)(v15 | (4 * i)) << 8);
    *v12 |= 0x20000u;
    *v12 |= 0x40000u;
    delay_us(1);
    sub_108CB8(&v23, (unsigned int *)&v24);
    v17 = v24 / 8;
    v18 = i;
    if ( a2 )
    {
      *(_WORD *)(a2 + 4 * v11) = v23 / 8;
      v19 = a2 + 4 * v11++;
      *(_WORD *)(v19 + 2) = v17;
    }
    msg_parse(v10, v18);
  }
LABEL_7:
  v20 = (unsigned int *)off_108F24;
  result = off_108F3C;
  v22 = off_108F34;
  *(_DWORD *)off_108F38 &= ~2u;
  *v20 |= 4u;
  *v20 = *v20 & 0xFFFF8FFF | 0x3000;
  *v20 = *v20 & 0xFFFFF8FF | 0x600;
  *v20 &= ~8u;
  *v20 &= ~1u;
  *result &= 0xCFFFFFFF;
  *v22 &= 0xFFFE00FF;
  *v22 &= ~0x20000u;
  *v22 |= 0x40000u;
  return result;
}

