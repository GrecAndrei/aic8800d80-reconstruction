// v23 annotated: sub_114920 @ 0x114920
// Original: 114920_sub_114920.c
// Primary struct: <unclustered>
//
// sub_114920 @ 0x114920, size 120 bytes
int __fastcall sub_114920(int a1, int a2)
{
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r0
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r2
  char v9; // r5
  unsigned int v10; // r4
  char v11; // r2
  _BYTE *v12; // r2
  _DWORD v14[3]; // [sp+4h] [bp-10h]

  v3 = *(_DWORD *)(dword_114998 + 4);
  v4 = *(_DWORD *)(dword_114998 + 8);
  v14[0] = *(_DWORD *)dword_114998;
  v14[1] = v3;
  v14[2] = v4;
  v5 = MEMORY[0x1FC](v14[a1]);
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = v5 >> (8 * v6);
    v9 = v8;
    v10 = (unsigned __int8)v8 >> 4;
    if ( (v8 & 0xF0) == 0 )
    {
      if ( !(_BYTE)v8 )
      {
        v7 |= 2 << (4 * v6);
        v12 = (_BYTE *)(a2 + v6);
        goto LABEL_9;
      }
      v7 |= 1 << (4 * v6);
      v10 = (unsigned __int8)v8;
    }
    if ( (v10 & 1) != 0 )
      v11 = -1;
    else
      v11 = 1;
    v9 = (v10 >> 1) * v11;
    v12 = (_BYTE *)(a2 + v6);
LABEL_9:
    ++v6;
    *v12 = v9;
  }
  while ( v6 != 3 );
  return v7;
}

