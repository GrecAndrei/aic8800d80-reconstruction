// sub_113854 @ 0x113854, size 94 bytes
int __fastcall sub_113854(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  _BYTE *v6; // r1
  _DWORD *v8; // r1

  if ( *(_DWORD *)off_1138B4 )
  {
    v8 = off_1138C8;
    v1 = (int *)dword_1138CC;
    *(_DWORD *)off_1138B8 = dword_1138CC;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(int **)off_1138B8;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(_BYTE *)(*(_DWORD *)off_1138BC + 6) == 1 )
    *((_DWORD *)off_1138C0 + 83) |= v4;
  v6 = off_1138C4;
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((_DWORD *)v6 + 2) = v3;
  return 236;
}

