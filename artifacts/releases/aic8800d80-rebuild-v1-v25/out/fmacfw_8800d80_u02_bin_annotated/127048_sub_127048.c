// fwstruct annotate: 127048_sub_127048.c
// sub_127048 @ 0x127048, size 44 bytes
int sub_127048()
{
  _DWORD *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_127074;
  if ( (*((_BYTE *)off_127074 + 88) & 8) != 0 )
  {
    v1 = dword_127078;
    goto LABEL_6;
  }
  if ( (*((_BYTE *)off_127074 + 88) & 4) != 0 )
  {
    v1 = dword_12707C;
LABEL_6:
    v2 = *((_DWORD *)off_127074 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(_BYTE *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return fmac_msg_handler_init();
  }
  if ( *((_DWORD *)off_127074 + 11) )
    return fmac_msg_handler_init();
  return result;
}

