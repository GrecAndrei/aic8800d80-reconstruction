// v23 annotated: sub_122A64 @ 0x122a64
// Original: 122a64_sub_122A64.c
// Primary struct: <unclustered>
//
// sub_122A64 @ 0x122a64, size 152 bytes
int __fastcall sub_122A64(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r4
  _BYTE *v7; // r4
  _DWORD *v8; // r6
  _DWORD *v9; // r5
  unsigned int v10; // r3
  _DWORD *v11; // r3
  _DWORD *v13; // r6
  _DWORD *v14; // r5

  v4 = *a2;
  if ( v4 && *((_BYTE *)off_122AFC + 177) )
  {
    v7 = off_122B00;
    v13 = off_122B04;
    v14 = off_122B08;
    *(_BYTE *)off_122B00 = 1;
    *v13 |= 0x2000000u;
    v14[14] |= 0x10u;
  }
  else
  {
    v7 = off_122B00;
    v8 = off_122B04;
    v9 = off_122B08;
    *(_BYTE *)off_122B00 = 0;
    *v8 &= ~0x2000000u;
    v9[14] &= ~0x10u;
  }
  *(_DWORD *)off_122B04 &= ~0x800u;
  v7[2] = 0;
  if ( a2[2] )
    v10 = *(_DWORD *)off_122B0C | 0x80000000;
  else
    v10 = *(_DWORD *)off_122B0C & 0x7FFFFFFF;
  *(_DWORD *)off_122B0C = v10;
  if ( a2[4] )
  {
    v11 = off_122B14;
    *(_DWORD *)off_122B10 = *((_DWORD *)a2 + 2);
    *v11 &= 0xFFFFFu;
    *v11 |= *((_DWORD *)a2 + 3) << 20;
  }
  sub_12CA10(102, a4, a3);
  return 0;
}

