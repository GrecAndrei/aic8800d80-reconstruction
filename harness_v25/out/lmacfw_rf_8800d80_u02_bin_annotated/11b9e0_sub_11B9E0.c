// fwstruct annotate: 11b9e0_sub_11B9E0.c
// sub_11B9E0 @ 0x11b9e0, size 44 bytes
int sub_11B9E0()
{
  _DWORD *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_11BA0C;
  if ( (*((_BYTE *)off_11BA0C + 88) & 8) != 0 )
  {
    v1 = dword_11BA10;
    goto LABEL_6;
  }
  if ( (*((_BYTE *)off_11BA0C + 88) & 4) != 0 )
  {
    v1 = dword_11BA14;
LABEL_6:
    v2 = *((_DWORD *)off_11BA0C + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(_BYTE *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return rf_msg_alloc_init();
  }
  if ( *((_DWORD *)off_11BA0C + 11) )
    return rf_msg_alloc_init();
  return result;
}

