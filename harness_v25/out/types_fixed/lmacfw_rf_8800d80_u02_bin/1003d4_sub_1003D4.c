// sub_1003D4 @ 0x1003d4, size 190 bytes
void __noreturn sub_1003D4()
{
  char *v0; // r4
  _DWORD *v1; // r2
  _DWORD *v2; // r5
  _DWORD *v3; // r1
  _DWORD *v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r6
  _DWORD *v7; // r3

  v0 = (char *)off_100498;
  v1 = off_10049C;
  v2 = off_1004A0;
  *(_DWORD *)off_100494 = off_100498;
  *v1 = v0 + 12;
  v3 = off_1004A4;
  v4 = off_1004A8;
  v5 = off_1004AC;
  v6 = off_1004B0;
  *v2 = v0 + 76;
  *v3 = v0 + 136;
  *v4 = v0 + 152;
  *v6 = v0 + 178;
  *v5 = v0 + 176;
  rf_init_setup_n_2a0();
  if ( *(_BYTE *)*v2 == 1 )
  {
    v7 = off_1004B8;
    *((_DWORD *)off_1004B4 + 22) &= ~1u;
    *(_DWORD *)(v7 + 0x50) |= 1u;
    *(_DWORD *)(v7 + 0x50) &= ~2u;
  }
  sub_123068();
  sub_10F4B8();
}
