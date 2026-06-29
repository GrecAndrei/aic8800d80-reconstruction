// fwstruct annotate: 130798_fmac_dbg_marker_set.c
// fmac_dbg_marker_set @ 0x130798, size 56 bytes
// Doc: fmac_dbg_marker_set [util]: Write debug marker bytes (0xbf, 0xc) to control word
// fmac_dbg_marker_set [util]: Write debug marker bytes (0xbf, 0xc) to control word
int __fastcall fmac_dbg_marker_set(int a1)
{
  _DWORD *v2; // r1
  _WORD *v3; // r2
  __int16 v4; // r6
  __int16 v5; // r5
  __int16 v6; // r4

  v2 = off_1307D0;
  **(_BYTE **)a1 = -65;
  *(_BYTE *)(*(_DWORD *)a1 + 1) = 12;
  *(_DWORD *)(*(_DWORD *)a1 + 2) = v2[12];
  v3 = *(_WORD **)a1;
  v4 = *((_WORD *)v2 + 26);
  v5 = *((_WORD *)v2 + 27);
  v6 = *((_WORD *)v2 + 28);
  v3[6] = *((_WORD *)v2 + 29);
  v3[3] = v4;
  v3[4] = v5;
  v3[5] = v6;
  *(_DWORD *)a1 = v3 + 7;
  return 14;
}

