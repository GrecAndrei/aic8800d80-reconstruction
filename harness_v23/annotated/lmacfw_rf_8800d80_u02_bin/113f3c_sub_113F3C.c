// v23 annotated: sub_113F3C @ 0x113f3c
// Original: 113f3c_sub_113F3C.c
// Primary struct: <unclustered>
//
// sub_113F3C @ 0x113f3c, size 152 bytes
int __fastcall sub_113F3C(int a1, int a2)
{
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r6
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r3
  int result; // r0
  unsigned int v10; // r4
  bool v11; // zf
  int v12; // r2
  unsigned int v13; // r4
  unsigned int v14; // r7
  _BYTE *v15; // r4
  unsigned int v16; // [sp+4h] [bp-18h]
  int v17; // [sp+8h] [bp-14h]
  _DWORD v18[4]; // [sp+Ch] [bp-10h] BYREF

  v3 = *(_DWORD *)(dword_113FD4 + 4);
  v4 = *(_DWORD *)(dword_113FD4 + 8);
  v18[0] = *(_DWORD *)dword_113FD4;
  v18[1] = v3;
  v18[2] = v4;
  v5 = v18[a1];
  v6 = sub_113A44(v5);
  v16 = v6;
  v7 = sub_113A44(v5 + 1);
  v8 = 0;
  v17 = v7;
  result = 0;
  while ( 1 )
  {
    v12 = v6 >> (8 * (v8 & 3));
    v14 = (unsigned __int8)v12;
    v10 = (unsigned __int8)v12 >> 4;
    if ( (v12 & 0xF0) == 0 )
    {
      v12 = 1 << (4 * v8);
      if ( !v14 )
      {
        result |= 2 << (4 * v8);
        v15 = (_BYTE *)(a2 + v8);
        goto LABEL_8;
      }
      result |= v12;
      v10 = v14;
    }
    v11 = (v10 & 1) == 0;
    if ( (v10 & 1) != 0 )
      LOBYTE(v12) = -1;
    v13 = v10 >> 1;
    if ( v11 )
      LOBYTE(v12) = 1;
    LOBYTE(v14) = v13 * v12;
    v15 = (_BYTE *)(a2 + v8);
LABEL_8:
    ++v8;
    *v15 = v14;
    if ( v8 == 6 )
      return result;
    v6 = *(_DWORD *)((char *)&v18[-2] + (v8 & 0xFFFFFFFC));
  }
}

