// v23 annotated: sub_10F0C4 @ 0x10f0c4
// Original: 10f0c4_sub_10F0C4.c
// Primary struct: <unclustered>
//
// sub_10F0C4 @ 0x10f0c4, size 74 bytes
void __noreturn sub_10F0C4()
{
  int v0; // r2
  __int64 v1; // kr00_8
  char *v2; // r3
  __int64 v3; // r0
  int v4; // r4
  int v5; // r2
  __int64 v6; // kr10_8

  v0 = *(_DWORD *)off_10F110;
  v1 = *(_QWORD *)(*(_DWORD *)off_10F110 + 24);
  v2 = (char *)off_10F114;
  LODWORD(v3) = *(_DWORD *)(*(_DWORD *)off_10F110 + 36);
  v4 = *(_DWORD *)(*(_DWORD *)off_10F110 + 32);
  *(_DWORD *)off_10F114 = v1;
  v6 = *(_QWORD *)(v0 + 40);
  v5 = *(_DWORD *)(v0 + 44);
  HIDWORD(v3) = v6;
  *((_DWORD *)v2 + 1) = HIDWORD(v1);
  *((_DWORD *)v2 + 2) = v4;
  *(_QWORD *)(v2 + 12) = v3;
  *((_DWORD *)v2 + 5) = v5;
  sub_1033F8();
}

