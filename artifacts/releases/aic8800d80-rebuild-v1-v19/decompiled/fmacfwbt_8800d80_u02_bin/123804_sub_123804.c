// sub_123804 @ 0x123804, size 140 bytes
// Doc: sub_1223804 [ipc]: SDIO/host cmd prep issuing 0x53/0xd to helper
// sub_1223804 [ipc]: SDIO/host cmd prep issuing 0x53/0xd to helper
int __fastcall sub_123804(int a1, unsigned __int8 *a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (_BYTE *)rf_bus_setup_n3a8(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_123890 + 1320 * v5;
  if ( !*(_BYTE *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( sub_12A818(
           v6,
           0,
           a2[3],
           a2[2],
           *((_DWORD *)a2 + 2),
           *((_DWORD *)a2 + 1),
           (*(unsigned __int16 *)(v6 + 222) << 10)
         + *(_DWORD *)off_123894 / (*(unsigned __int16 *)(v6 + 222) << 10) * (*(unsigned __int16 *)(v6 + 222) << 10)
         + *((_DWORD *)off_123898 + 4)
         - *(_DWORD *)off_123894
         + *((_DWORD *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    sub_12CBB4(v4);
    return 0;
  }
  *v4 = bt_link_state_get_n2c4();
  sub_12CBB4(v4);
  return 0;
}

