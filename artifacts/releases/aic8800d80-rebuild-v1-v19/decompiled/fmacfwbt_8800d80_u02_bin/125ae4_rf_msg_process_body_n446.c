// rf_msg_process_body_n446 @ 0x125ae4, size 258 bytes
// Doc: rf_msg_process_body_n446 [rf]: RF message body variant with ldrb dispatch table load
// rf_msg_process_body_n446 [rf]: RF message body variant with ldrb dispatch table load
void rf_msg_process_body_n446()
{
  int v0; // r4
  _BYTE *v1; // r6
  int v2; // r5
  _DWORD *v3; // r2
  int v4; // r7
  _BYTE *v5; // r8
  char v6; // r9
  int v7; // r10
  int v8; // r0
  int v9; // r3

  v0 = *((_DWORD *)off_125BEC + 2);
  v1 = off_125BF0;
  if ( **(__int16 **)off_125BE8 < 0 && *((_DWORD *)off_125BF0 + 1) )
  {
    sub_12F694(dword_125BFC, dword_125BF8, 1074);
    v2 = (unsigned __int8)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((unsigned __int8 *)off_125BF0 + 9);
    if ( *((_BYTE *)off_125BF0 + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_125BF4;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_125C00;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(_BYTE *)(v0 + 106) != 2
        || !*(_BYTE *)(v0 + 226)
        || !*(_BYTE *)(v0 + 108)
        || *(unsigned __int8 *)(v0 + 225) != *(unsigned __int8 *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( rf_chan_lookup_n_580c(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        sub_1286B4(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(_DWORD *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = sub_1286B4(v0);
        if ( v7 )
        {
          *(_BYTE *)(v0 + 144) = *(_BYTE *)(v0 + 107);
          *(_BYTE *)(v0 + 145) = -1;
          v8 = sub_1190B4(v0 + 116, 4);
          v9 = *((_DWORD *)v1 + 1);
          if ( v8 )
            *((_DWORD *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            fmacfwbt_sub_1221E68();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(_DWORD *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

