// sub_122F30 @ 0x122f30, size 120 bytes
int __fastcall sub_122F30(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned __int16 v5; // r3
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v9; // [sp+0h] [bp-14h] BYREF
  unsigned int v10; // [sp+4h] [bp-10h] BYREF
  unsigned int v11[3]; // [sp+8h] [bp-Ch] BYREF

  v9 = 0;
  v10 = 0;
  v4 = (_BYTE *)sub_12C92C(116, a4, a3, 6);
  if ( (*(_DWORD *)off_122FA8 & 0x2000000) != 0 )
  {
    sub_1148C4(&v9, &v10);
    v6 = v9;
    v5 = v10;
  }
  else
  {
    memset(v11, 0, 6);
    sub_114E6C((int)v11);
    v5 = __rev16(LOWORD(v11[0]));
    v6 = bswap32(*(unsigned int *)((char *)v11 + 2));
    v9 = v6;
    v10 = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v7 = dword_122FAC;
  v4[4] = BYTE1(v6);
  sub_12EA88(v7, HIBYTE(v5), (unsigned __int8)v6);
  sub_12C98C(v4);
  return 0;
}

