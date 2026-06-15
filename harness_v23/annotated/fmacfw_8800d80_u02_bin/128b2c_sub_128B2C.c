// v23 annotated: sub_128B2C @ 0x128b2c
// Original: 128b2c_sub_128B2C.c
// Primary struct: <unclustered>
//
// sub_128B2C @ 0x128b2c, size 154 bytes
int __fastcall sub_128B2C(int a1, int a2, int a3)
{
  int v4; // r0
  int v5; // r1
  int v6; // r5
  _BYTE *v7; // r3
  int v8; // r2
  int v9; // r0
  int v11; // r1

  if ( (a2 & 0x800000) != 0 )
  {
    if ( a1 )
      *(_BYTE *)(a1 + 115) = 0;
    return 1;
  }
  else
  {
    v4 = (unsigned __int8)(*(_BYTE *)(a1 + 115) + 1);
    v5 = *(_DWORD *)off_128BC8;
    *(_BYTE *)(a1 + 115) = v4;
    if ( *(unsigned __int8 *)(v5 + 1) == v4 )
    {
      v11 = dword_128BDC;
      *(_BYTE *)(a1 + 115) = 0;
      feature_guard_check(1024, v11);
      send_msg_to_host_c43(a1);
      return 1;
    }
    else
    {
      v6 = *(unsigned __int8 *)(a1 + 108);
      if ( *(_BYTE *)(a1 + 108) )
      {
        sub_118DC4(*(unsigned __int8 *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = off_128BD0;
        v8 = *((unsigned __int8 *)off_128BCC + 2);
        *((_BYTE *)off_128BD0 + 28) = 1;
        if ( v8 )
          *(_DWORD *)off_128BD4 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = dword_128BD8;
        v7[29] = 0;
        timestamp_remove(v9);
        *(_DWORD *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}

