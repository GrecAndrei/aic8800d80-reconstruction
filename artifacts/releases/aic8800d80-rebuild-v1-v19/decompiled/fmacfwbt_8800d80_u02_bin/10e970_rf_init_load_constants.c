// rf_init_load_constants @ 0x10e970, size 260 bytes
// Doc: rf_init_load_constants [rf]: Loads RF/board constants and pointers, likely RF init or calibration setup
// rf_init_load_constants [rf]: Loads RF/board constants and pointers, likely RF init or calibration setup
int __fastcall rf_init_load_constants(unsigned int *a1)
{
  _DWORD *v1; // r2
  int v2; // r7
  int v3; // r3
  _DWORD *v4; // r5
  _DWORD *v5; // r10
  int v6; // r6
  unsigned int *v7; // r4
  int *v8; // r1
  int v9; // r0
  unsigned int v10; // r9
  unsigned int v11; // r8
  unsigned int v12; // r7
  unsigned int v13; // r6
  int result; // r0
  _DWORD v16[2]; // [sp+Ch] [bp-Ch] BYREF
  __int16 v17; // [sp+14h] [bp-4h]

  v1 = off_10EA74;
  v2 = dword_10EA78;
  v3 = dword_10EA7C;
  v4 = off_10EA80;
  v5 = off_10EA98;
  v6 = dword_10EA84;
  v7 = (unsigned int *)off_10EA88;
  v17 = 0;
  *((_DWORD *)off_10EA94 + 14) = 296;
  v1[3] = v1[3] & 0xE0000000 | v2;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 2u;
  *v4 &= ~1u;
  v16[0] = v6;
  v16[1] = 5610;
  sub_102898((unsigned __int16 *)v16, 0);
  v8 = (int *)off_10EA8C;
  v9 = dword_10EA90;
  *v5 |= 0x80000000;
  *v8 = v9;
  v10 = *v7;
  v11 = *v7;
  v12 = *v7;
  v13 = *v7;
  *v7 &= ~0x80000u;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v7 |= 0x400000u;
  result = sub_10E694(4u, 8u, a1);
  *v5 &= ~0x80000000;
  *v4 &= ~2u;
  *v7 = v10 & 0x80000 | *v7 & 0xFFF7FFFF;
  *v7 = v11 & 0x100000 | *v7 & 0xFFEFFFFF;
  *v7 = v12 & 0x200000 | *v7 & 0xFFDFFFFF;
  *v7 = v13 & 0x400000 | *v7 & 0xFFBFFFFF;
  return result;
}

