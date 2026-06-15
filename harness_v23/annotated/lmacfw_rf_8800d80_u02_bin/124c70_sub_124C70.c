// v23 annotated: sub_124C70 @ 0x124c70
// Original: 124c70_sub_124C70.c
// Primary struct: <unclustered>
//
// sub_124C70 @ 0x124c70, size 424 bytes
int __fastcall sub_124C70(int a1, unsigned __int8 **a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r7
  int v6; // r8
  int v7; // r0
  int v8; // r2
  _BYTE *v9; // r4
  int v10; // r1
  int v11; // r0
  int result; // r0
  __int64 v13; // [sp+4h] [bp-14h] BYREF
  unsigned __int8 v14; // [sp+Ch] [bp-Ch] BYREF
  unsigned __int8 v15; // [sp+Dh] [bp-Bh]
  unsigned __int16 v16; // [sp+Eh] [bp-Ah]
  int v17; // [sp+10h] [bp-8h]
  char v18; // [sp+16h] [bp-2h]

  get_cached_1828f8(&v13, 0);
  if ( a1 <= 1 )
  {
    msg_parse(dword_124E2C);
    return -1;
  }
  v4 = parse_int(a2[1], nullptr, 0xAu);
  v5 = parse_int(a2[2], nullptr, 0xAu);
  v6 = parse_int(a2[3], nullptr, 0xAu);
  if ( a1 > 3 )
    v7 = parse_int(a2[4], nullptr, 0xAu);
  else
    v7 = 0;
  if ( v4 == 5 )
  {
    v14 = v13;
    v15 = 0;
    v18 = 0;
    v17 = HIDWORD(v13);
    v16 = WORD2(v13);
    rf_state_get_n246(0, (int)&v14);
    sub_12407C(0);
    v8 = 2;
  }
  else
  {
    if ( v4 == 10 )
    {
      v14 = v13;
      v15 = 0;
      v18 = 0;
      v17 = HIDWORD(v13);
      v16 = WORD2(v13);
      rf_state_get_n246(0, (int)&v14);
      sub_12407C(0);
    }
    else
    {
      if ( (*(_BYTE *)off_124E18 & 8) == 0 && (v4 > 1 || v5 > 1) )
      {
        msg_parse(dword_124E30, v4, v5);
        return -2;
      }
      v17 = HIDWORD(v13);
      v15 = v4;
      v14 = v13;
      v18 = 0;
      if ( v4 )
      {
        if ( v4 == 1 )
        {
          if ( v6 )
            goto LABEL_25;
        }
        else
        {
          if ( !v6 )
          {
            if ( !v7 )
            {
              v16 = WORD2(v13) + 30;
LABEL_14:
              rf_state_get_n246(0, (int)&v14);
              sub_12407C(v5);
              v8 = 0;
              goto LABEL_16;
            }
LABEL_25:
            v16 = WORD2(v13) - 10;
            goto LABEL_14;
          }
          if ( v7 )
          {
            v16 = WORD2(v13) - 30;
            goto LABEL_14;
          }
        }
        v16 = WORD2(v13) + 10;
        goto LABEL_14;
      }
      v16 = WORD2(v13);
      rf_state_get_n246(0, (int)&v14);
      sub_12407C(v5);
    }
    v8 = v4 == 10;
  }
LABEL_16:
  v9 = off_124E20;
  v10 = v15;
  v11 = v14;
  *(_BYTE *)off_124E1C = v8;
  *v9 = v8;
  sub_102E84(v11, v10, v8);
  msg_parse(dword_124E24, v16, (unsigned __int16)v17);
  result = *(_DWORD *)off_124E28;
  if ( *(_DWORD *)off_124E28 )
  {
    rf_level_apply_n_4ec(result);
    return 0;
  }
  return result;
}

