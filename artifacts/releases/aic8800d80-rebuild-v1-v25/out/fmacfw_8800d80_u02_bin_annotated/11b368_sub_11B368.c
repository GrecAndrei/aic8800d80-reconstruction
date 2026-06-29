// fwstruct annotate: 11b368_sub_11B368.c
// sub_11B368 @ 0x11b368, size 74 bytes
int __fastcall sub_11B368(int result)
{
  _DWORD *v1; // r6
  char *v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r5
  int v6; // r3

  v1 = off_11B3B4;
  v2 = (char *)off_11B3B4 + 28 * result;
  if ( v2[46] )
  {
    v3 = *((_DWORD *)off_11B3B4 + 52);
    v2[46] = 0;
    v4 = result;
    v5 = 8 * result;
    if ( (v3 & 1) == 0 || *((unsigned __int8 *)v1 + 190) != result )
    {
      v6 = (int)&v1[7 * result];
      result = *(_DWORD *)(v6 + 36);
      if ( result )
        result = mmio_reg_poll_n6b4(result, v4, v3, v6);
      v1[v5 - v4 + 9] = 0;
    }
  }
  return result;
}

