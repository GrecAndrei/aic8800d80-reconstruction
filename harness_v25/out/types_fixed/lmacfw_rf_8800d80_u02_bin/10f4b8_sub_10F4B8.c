// sub_10F4B8 @ 0x10f4b8, size 70 bytes
void __noreturn sub_10F4B8()
{
  __int64 v0; // r0
  __int64 v1; // kr00_8
  _QWORD *v2; // r3

  v0 = *(_QWORD *)(*(_DWORD *)off_10F500 + 32);
  v1 = *(_QWORD *)(*(_DWORD *)off_10F500 + 24);
  v2 = off_10F504;
  *((_DWORD *)off_10F504 + 4) = *(_DWORD *)(*(_DWORD *)off_10F500 + 44);
  *v2 = v1;
  *(_DWORD *)(v2 + 0x4) = v0;
  sub_10C2E4();
  hw_config_init();
  sub_102A58();
  if ( **(_BYTE **)off_10F508 == 3 )
    mac_desc_init();
  sub_10D43C();
}
