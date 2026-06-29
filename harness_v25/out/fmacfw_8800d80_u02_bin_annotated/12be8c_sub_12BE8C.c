// fwstruct annotate: 12be8c_sub_12BE8C.c
// sub_12BE8C @ 0x12be8c, size 280 bytes
int __fastcall sub_12BE8C(int a1, int a2)
{
  void *v2; // r2
  int v3; // r4
  int result; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r2
  char *v11; // r4
  int v12; // r1
  int v13; // r2

  v2 = off_12BFA4;
  v3 = *(_DWORD *)off_12BFA4;
  *(_DWORD *)off_12BFA8 = *(_DWORD *)off_12BFA4;
  result = v3 << 21;
  if ( (v3 & 0x400) != 0 )
  {
    msg_parse(dword_12BFC0, a2, v2);
    while ( 1 )
      ;
  }
  v5 = v3 << 23;
  if ( (v3 & 0x100) == 0 )
  {
    v6 = v3 << 22;
    if ( (v3 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    msg_parse(dword_12BFBC, v5, v6);
    while ( 1 )
      ;
  }
  result = fw_state_check();
  v6 = v3 << 22;
  if ( (v3 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v3 & 0x10) != 0 )
  {
    rf_set_bit_flag(4);
    result = category_dispatch_5way(4);
  }
  if ( (v3 & 0x2F) != 0 )
  {
    if ( *(_BYTE *)off_12BFAC )
    {
      v11 = (char *)off_12BFD0;
      sub_102B80(*((_BYTE *)off_12BFD0 + 411));
      v12 = v11[411];
      *((_BYTE *)off_12BFD4 + 9) = v12;
      return msg_parse(dword_12BFD8, v12, v13);
    }
    if ( *(_BYTE *)off_12BFB0 )
    {
      result = *(_DWORD *)off_12BFB4 << 28;
      if ( result )
        *((_BYTE *)off_12BFB0 + 6) = 1;
    }
  }
  v7 = **(__int16 **)off_12BFB8;
  if ( v7 < 0 )
  {
    if ( (v3 & 1) != 0 )
    {
      v8 = dword_12BFC4;
      v9 = dword_12BFCC;
      v10 = 760;
    }
    else if ( (v3 & 2) != 0 )
    {
      v8 = dword_12BFC4;
      v9 = dword_12BFEC;
      v10 = 761;
    }
    else
    {
      v7 = v3 << 29;
      if ( (v3 & 4) != 0 )
      {
        v8 = dword_12BFC4;
        v9 = dword_12BFE8;
        v10 = 762;
      }
      else
      {
        result = v3 << 28;
        if ( (v3 & 8) != 0 )
        {
          v8 = dword_12BFC4;
          v9 = dword_12BFE4;
          v10 = 763;
        }
        else if ( (v3 & 0x80) != 0 )
        {
          v8 = dword_12BFC4;
          v9 = dword_12BFE0;
          v10 = 765;
        }
        else if ( (v3 & 0x40) != 0 )
        {
          v8 = dword_12BFC4;
          v9 = dword_12BFDC;
          v10 = 767;
        }
        else
        {
          v7 = v3 << 26;
          if ( (v3 & 0x20) == 0 )
            return result;
          v8 = dword_12BFC4;
          v9 = dword_12BFC8;
          v10 = 769;
        }
      }
    }
    return fmac_phy_op_handler(v9, v8, v10, v7);
  }
  return result;
}

