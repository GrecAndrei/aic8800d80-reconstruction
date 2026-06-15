// v23 annotated: rf_chan_init_or_set_n54 @ 0x124b04
// Original: 124b04_rf_chan_init_or_set_n54.c
// Primary struct: <unclustered>
//
// rf_chan_init_or_set_n54 @ 0x124b04, size 338 bytes
// Doc: rf_chan_init_or_set_n54 [rf]: Initialize/set RF channel/param with memset(0) helper
// rf_chan_init_or_set_n54 [rf]: Initialize/set RF channel/param with memset(0) helper
int __fastcall rf_chan_init_or_set_n54(int a1, int a2)
{
  unsigned __int8 v3; // r0
  unsigned int v4; // r4
  int v5; // r3
  _DWORD *v6; // r1
  unsigned int v8; // r5
  __int64 v9; // [sp+4h] [bp-18h] BYREF
  char v10; // [sp+Ch] [bp-10h] BYREF
  unsigned __int8 v11; // [sp+Dh] [bp-Fh]
  unsigned __int16 v12; // [sp+Eh] [bp-Eh]
  unsigned __int16 v13; // [sp+10h] [bp-Ch]
  __int16 v14; // [sp+12h] [bp-Ah]
  char v15; // [sp+16h] [bp-6h]

  v3 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
  if ( a1 <= 1 || (v4 = v3) == 0 )
  {
    msg_parse(dword_124C68);
    return -1;
  }
  *(_DWORD *)off_124C58 |= 0x500000u;
  get_cached_1828f8(&v9, 0);
  if ( v4 <= 0x23 )
  {
    v5 = BYTE1(v9);
    v10 = 0;
    v11 = BYTE1(v9);
    if ( v4 > 0xD )
    {
      if ( v4 != 14 )
      {
        msg_parse(dword_124C6C, v4, (_DWORD)v9);
        return -2;
      }
      v13 = 2484;
      v14 = 0;
      v15 = 0;
      if ( !BYTE1(v9) )
        goto LABEL_6;
LABEL_13:
      v8 = WORD1(v9);
      if ( v5 == 1 )
      {
        if ( v8 < WORD2(v9) )
          goto LABEL_21;
      }
      else
      {
        if ( v5 != 2 )
          goto LABEL_7;
        if ( (int)(v8 + 20) < WORD2(v9) )
        {
          v12 = v13 - 30;
          goto LABEL_7;
        }
        if ( v8 < WORD2(v9) )
        {
LABEL_21:
          v12 = v13 - 10;
          goto LABEL_7;
        }
        if ( WORD2(v9) < (int)(v8 - 19) )
        {
          v12 = v13 + 30;
          goto LABEL_7;
        }
      }
      v12 = v13 + 10;
      goto LABEL_7;
    }
    v13 = 5 * v4 + 2407;
  }
  else
  {
    v5 = BYTE1(v9);
    v13 = 5 * v4 + 5000;
    v10 = 1;
    v11 = BYTE1(v9);
  }
  v14 = 0;
  v15 = 0;
  if ( v5 )
    goto LABEL_13;
LABEL_6:
  v12 = v13;
LABEL_7:
  *(_BYTE *)off_124C5C = 1;
  rf_state_get_n246(0, (int)&v10);
  v6 = off_124C60;
  *(_DWORD *)off_124C58 &= 0xFF87FFFF;
  if ( *v6 )
    rf_level_apply_n_4ec(*v6);
  msg_parse(dword_124C64, v4, v13, v11);
  return 0;
}

