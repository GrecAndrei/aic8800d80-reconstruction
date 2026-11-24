// sub_100478 @ 0x100478, size 240 bytes
void __noreturn sub_100478()
{
  char *v0; // r4
  _DWORD *v1; // r5
  _DWORD *v2; // r3
  _DWORD *v3; // r0
  _DWORD *v4; // r2
  _DWORD *v5; // r3
  _DWORD *v6; // r1
  _DWORD *v7; // r3

  v0 = (char *)off_100568;
  v1 = off_100570;
  v2 = off_100574;
  v3 = off_100578;
  *(_DWORD *)off_10056C = off_100568;
  v4 = off_10057C;
  *v1 = v0 + 76;
  *v2 = v0 + 12;
  *v3 = v0 + 136;
  v5 = off_100580;
  v6 = off_100584;
  *v4 = v0 + 152;
  *v5 = v0 + 178;
  *v6 = v0 + 176;
  sub_1002A0();
  if ( *(_BYTE *)*v1 == 1 )
  {
    v7 = off_10058C;
    *((_DWORD *)off_100588 + 22) &= ~1u;
    *(_DWORD *)(v7 + 0x50) |= 1u;
    *(_DWORD *)(v7 + 0x50) &= ~2u;
  }
  *((_BYTE *)off_100594 + 2) = (*(_DWORD *)off_100590 & 0xF) == 10;
  sub_1301B4();
  log_hw_regs_init();
  rf_cmd_send_n_36c();
}
