// fwstruct annotate: 111884_sub_111884.c
// sub_111884 @ 0x111884, size 114 bytes
// Doc: rf_bus_mark_owner_n62 [rf]: Mark RF bus n62 as owned: set request+grant bits (0xc0) in bus state and record owner id.
// rf_bus_mark_owner_n62 [rf]: Mark RF bus n62 as owned: set request+grant bits (0xc0) in bus state and record owner id.
int sub_111884()
{
  int v0; // r3
  int *v1; // r2
  _DWORD *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  char *v6; // r3
  _DWORD *v7; // r4
  int v8; // r6
  __int64 v9; // kr00_8
  __int64 v10; // kr08_8

  v0 = *(_DWORD *)off_1118FC;
  v1 = (int *)off_111900;
  v2 = off_111904;
  *(_DWORD *)(v0 + 4) = *(_DWORD *)off_1118F8;
  result = *v1;
  v2[709] = v0;
  v4 = *(_DWORD *)off_111908;
  *(_BYTE *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(_BYTE *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (char *)off_11190C;
  v7 = off_111904;
  v8 = *((_DWORD *)off_11190C + 2);
  v9 = *(_QWORD *)off_11190C;
  *(_BYTE *)(*(_DWORD *)off_11190C + 3) |= 0xC0u;
  *(_BYTE *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(_QWORD *)(v6 + 12);
  *(_BYTE *)(v8 + 3) |= 0xC0u;
  *(_BYTE *)(v10 + 3) |= 0xC0u;
  *(_BYTE *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}

