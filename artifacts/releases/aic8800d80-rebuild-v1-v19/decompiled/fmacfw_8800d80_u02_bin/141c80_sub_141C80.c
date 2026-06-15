// sub_141C80 @ 0x141c80, size 184 bytes
int __fastcall sub_141C80(unsigned __int16 *a1, unsigned int a2, unsigned int a3, __int16 *a4)
{
  unsigned int v4; // r5
  __int16 v5; // r6
  __int16 **v6; // r4
  int v7; // r7
  __int16 v8; // r2
  int v9; // r5
  __int16 *v11; // r3
  int v12; // r5
  int result; // r0
  int v14; // r4
  bool v15; // nf
  int v16; // r1
  int v17; // r4
  int v18; // r2
  int v19; // r5

  v4 = *a1;
  v5 = *a4;
  v6 = (__int16 **)off_141D38;
  *((_BYTE *)a4 + 4) = (v4 & 0x40) != 0;
  *((_BYTE *)a4 + 2) = (v4 >> 7) & 7;
  v7 = (v4 >> 10) & 0x1F;
  *((_BYTE *)a4 + 5) = v7;
  v8 = (a3 >> 3) & 6 | v5 | v4 & 0x10 | v4 & 0x20;
  v9 = *(_DWORD *)(a1 + 1);
  v11 = *v6;
  *((_DWORD *)a4 + 7) = *(_DWORD *)(a1 + 3);
  *a4 = v8;
  *((_DWORD *)a4 + 6) = v9;
  v12 = *((unsigned __int8 *)a1 + 10);
  *((_BYTE *)a4 + 7) = v12;
  LOWORD(v14) = *(unsigned __int16 *)((char *)a1 + 11);
  a4[4] = v14;
  *((_BYTE *)a4 + 41) = *((_BYTE *)a1 + 13);
  result = *v11;
  v14 = (unsigned __int16)v14;
  if ( result < 0 && a2 <= 0xD )
  {
    result = sub_12F46C(dword_141D48, dword_141D44, 213);
    v14 = (unsigned __int16)a4[4];
    LOBYTE(v7) = *((_BYTE *)a4 + 5);
    v8 = *a4;
    v12 = *((unsigned __int8 *)a4 + 7);
  }
  v15 = (v8 & 4) != 0;
  v16 = dword_141D40;
  v17 = v14 << v7;
  v18 = *((unsigned __int16 *)off_141D3C + 14) + 20;
  *((_DWORD *)a4 + 4) = v17;
  if ( v15 )
    v19 = v12 << 10;
  else
    v19 = v12 << 8;
  *((_DWORD *)a4 + 3) = v19;
  *((_DWORD *)a4 + 12) = (unsigned int)(((unsigned int)v16 * (unsigned __int64)(unsigned int)(v17 * v18)) >> 32) >> 18;
  return result;
}

