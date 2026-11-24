// sub_1004CC @ 0x1004cc, size 132 bytes
// Doc: sub_12004CC [mmio]: Initializes LMAC RF context from MMIO 0x40330000 via helper calls
// sub_12004CC [mmio]: Initializes LMAC RF context from MMIO 0x40330000 via helper calls
int __fastcall sub_1004CC(int a1)
{
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(_DWORD *)off_100550;
  v3 = *(_DWORD *)off_100550;
  v4 = sub_101A28();
  v5 = sub_101A2C();
  v6 = (v2 >> 8) & 0xF;
  v7 = (v3 >> 27) & 1;
  if ( a1 == 1 )
  {
    if ( v5 )
    {
      return 11;
    }
    else if ( v6 == 1 )
    {
      return 2;
    }
    else if ( v4 )
    {
      return 9;
    }
    else
    {
      return 3;
    }
  }
  else if ( a1 == 2 )
  {
    if ( v6 == 1 )
    {
      if ( v7 )
        return 7;
      else
        return 4;
    }
    else
    {
      return v7 + 5;
    }
  }
  else if ( a1 )
  {
    if ( **(__int16 **)off_100554 < 0 )
      rf_cmd_send_n264(dword_10055C, dword_100558, 434);
    return 0;
  }
  else if ( v5 )
  {
    return 10;
  }
  else if ( v7 )
  {
    return 8;
  }
  else
  {
    return v6 != 1;
  }
}

