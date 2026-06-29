// fwstruct annotate: 12726c_sub_12726C.c
// sub_12726C @ 0x12726c, size 44 bytes
int sub_12726C()
{
  _DWORD *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_127298;
  if ( (*((_BYTE *)off_127298 + 88) & 8) != 0 )
  {
    v1 = dword_12729C;
    goto LABEL_6;
  }
  if ( (*((_BYTE *)off_127298 + 88) & 4) != 0 )
  {
    v1 = dword_1272A0;
LABEL_6:
    v2 = *((_DWORD *)off_127298 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(_BYTE *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return rf_status_query_n704();
  }
  if ( *((_DWORD *)off_127298 + 11) )
    return rf_status_query_n704();
  return result;
}

