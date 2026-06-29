// fwstruct annotate: 1133f0_sub_1133F0.c
// sub_1133F0 @ 0x1133f0, size 164 bytes
int __fastcall sub_1133F0(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r5
  int v4; // r3
  _DWORD *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_113494;
  if ( *(_BYTE *)off_113494 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113498;
  if ( *(_BYTE *)off_113498 )
  {
    sub_10DC24(dword_1134AC, rf_cmd_queue_next_n_c, *(unsigned __int8 *)off_113498);
    return -3;
  }
  else
  {
    v4 = *(char *)off_11349C;
    *(_BYTE *)off_113498 = 1;
    v5 = off_1134A0;
    if ( v4 )
    {
      *((_DWORD *)off_1134A0 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((_DWORD *)off_1134A0 + 713) |= 1u;
    }
    v6 = sub_11211C(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DC24(dword_1134B0, rf_cmd_queue_next_n_c, v6);
      return -1;
    }
    else
    {
      *(_BYTE *)off_1134A4 = 1;
      if ( *v2 )
      {
        sub_111DB4(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

