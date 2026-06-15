// v23 annotated: sub_114498 @ 0x114498
// Original: 114498_sub_114498.c
// Primary struct: group_7 (cluster 7)
//
// sub_114498 @ 0x114498, size 94 bytes
// Doc: sub_1214498 [util]: Internal helper invoked from rf_fault_dump path
// sub_1214498 [util]: Internal helper invoked from rf_fault_dump path
int __fastcall sub_114498(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  _BYTE *v6; // r1
  _DWORD *v8; // r1

  if ( *(_DWORD *)off_1144F8 )
  {
    v8 = off_11450C;
    v1 = (int *)dword_114510;
    *(_DWORD *)off_1144FC = dword_114510;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(int **)off_1144FC;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(_BYTE *)(*(_DWORD *)off_114500 + 6) == 1 )
    *((_DWORD *)off_114504 + 83) |= v4;
  v6 = off_114508;
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((_DWORD *)v6 + 2) = v3;
  return 236;
}

