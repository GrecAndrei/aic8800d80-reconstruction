// sub_13B600 @ 0x13b600, size 142 bytes
int __fastcall sub_13B600(int a1, char *a2, unsigned int a3)
{
  unsigned int v5; // r5
  int v6; // r6
  char v7; // r0
  char v8; // r8
  unsigned __int8 v9; // r7
  char v10; // r6
  _BYTE *v11; // r0

  if ( a2[2] != 2 )
    return 0;
  v5 = a3 >> 8;
  if ( msg_get_value(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B690 + 32 * v5;
    if ( *(_BYTE *)(v6 + 17) == 1 )
    {
      v7 = sub_13C49C(*(_DWORD *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(_BYTE *)(v6 + 20) + v7;
      v11 = (_BYTE *)rf_bus_setup_n3a8(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      sub_12CBB4((int)v11);
    }
    *(_DWORD *)(696 * (unsigned __int8)*a2 + 12 * (unsigned __int8)a2[1] + dword_13B694 + 448) = *((_DWORD *)off_13B698
                                                                                                 + 4);
    bt_hci_cmd_alloc_send(v5);
  }
  return 0;
}

