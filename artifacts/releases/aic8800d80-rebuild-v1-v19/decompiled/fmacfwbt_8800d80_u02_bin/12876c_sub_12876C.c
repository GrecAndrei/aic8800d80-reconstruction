// sub_12876C @ 0x12876c, size 106 bytes
int __fastcall sub_12876C(int result)
{
  int v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r2
  int v7; // r3
  int v8; // r2

  if ( *(_BYTE *)(result + 25) )
  {
    v1 = 0;
    v2 = dword_1287D8;
    while ( 1 )
    {
      v3 = *(_DWORD *)(v2 + 72);
      v2 += 1320;
      if ( v3 == result )
        break;
      if ( ++v1 == 4 )
      {
        v4 = 15;
        goto LABEL_6;
      }
    }
    v7 = dword_1287D8 + 1320 * v1;
    v8 = *(char *)(v7 + 110);
    v4 = *(char *)(v7 + 109);
    if ( v4 >= v8 )
      v4 = v8;
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = off_1287DC;
    *(_BYTE *)(result + 12) = v4;
    if ( v5[10] == result )
      return bt_hci_cmd_build_n6ac(v4);
  }
  else
  {
    v6 = off_1287DC;
    *(_BYTE *)(result + 12) = 15;
    if ( v6[10] == result )
      return bt_hci_cmd_build_n6ac(15);
  }
  return result;
}

