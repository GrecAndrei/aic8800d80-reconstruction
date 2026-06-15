// v23 annotated: sub_10F204 @ 0x10f204
// Original: 10f204_sub_10F204.c
// Primary struct: <unclustered>
//
// sub_10F204 @ 0x10f204, size 74 bytes
void __noreturn sub_10F204()
{
  int v0; // r2
  __int64 v1; // kr00_8
  char *v2; // r3
  __int64 v3; // r0
  int v4; // r4
  int v5; // r2
  __int64 v6; // kr10_8

  v0 = *(_DWORD *)off_10F250;
  v1 = *(_QWORD *)(*(_DWORD *)off_10F250 + 24);
  v2 = (char *)off_10F254;
  LODWORD(v3) = *(_DWORD *)(*(_DWORD *)off_10F250 + 36);
  v4 = *(_DWORD *)(*(_DWORD *)off_10F250 + 32);
  *(_DWORD *)off_10F254 = v1;
  v6 = *(_QWORD *)(v0 + 40);
  v5 = *(_DWORD *)(v0 + 44);
  HIDWORD(v3) = v6;
  *((_DWORD *)v2 + 1) = HIDWORD(v1);
  *((_DWORD *)v2 + 2) = v4;
  *(_QWORD *)(v2 + 12) = v3;
  *((_DWORD *)v2 + 5) = v5;
  phy_rf_init();
}

