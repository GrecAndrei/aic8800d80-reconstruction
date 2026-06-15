// v23 annotated: sub_12221C @ 0x12221c
// Original: 12221c_sub_12221C.c
// Primary struct: <unclustered>
//
// sub_12221C @ 0x12221c, size 114 bytes
int __fastcall sub_12221C(int a1)
{
  int v1; // r4
  int *v2; // r2
  int v3; // r5
  int v4; // r6
  int *v5; // r0
  int *v6; // r1
  int v7; // t1
  bool v8; // zf
  int v9; // r3
  _BYTE *v10; // r4
  _DWORD *v11; // r5
  _BYTE *v12; // r0
  _BYTE *v13; // r1
  int *v14; // r2
  int v15; // r1
  _DWORD *v16; // r2
  int v17; // r0

  v2 = (int *)dword_122294;
  v3 = dword_122298;
  v4 = dword_12229C;
  v5 = (int *)(a1 + 444);
  v6 = (int *)(*(_DWORD *)off_122290 + 4);
  do
  {
    v7 = *v6++;
    v9 = v7 & v3;
    v8 = (v7 & v3) == 0;
    if ( (v7 & v3) != 0 )
      v1 = *v5;
    else
      v9 = *v5;
    if ( !v8 )
    {
      v1 &= 0xFFFu;
      v9 |= v1;
    }
    *v2++ = v9;
    ++v5;
  }
  while ( v2 != (int *)v4 );
  v10 = off_1222A0;
  v11 = off_1222A4;
  sub_102B80(*((_BYTE *)off_1222A0 + 410));
  v12 = off_1222AC;
  v13 = off_1222B0;
  *((_BYTE *)off_1222A8 + 9) = v10[410];
  v14 = (int *)off_1222B4;
  *v12 = 1;
  *v13 = 1;
  v15 = *v14;
  v16 = off_1222B8;
  v17 = dword_1222BC;
  v15 += 15000;
  *v11 = v15;
  *v16 = 15000;
  v16[1] = 15000;
  v16[2] = 15000;
  v16[3] = 15000;
  v16[4] = 15000;
  v16[5] = 15000;
  return msg_parse(v17, v15, v16);
}

