// fwstruct annotate: 12bd40_sub_12BD40.c
// sub_12BD40 @ 0x12bd40, size 214 bytes
int sub_12BD40()
{
  int v0; // r4
  int v1; // r5
  unsigned __int16 *v2; // r6
  int v3; // r2
  int v4; // r1
  _DWORD *v6; // r3

  v0 = (*(_DWORD *)off_12BE18 >> 25) & 1;
  if ( (*(_DWORD *)off_12BE18 & 0x2000000) == 0
    && 32 * *(_DWORD *)off_12BE20
     - 2000
     - *((unsigned __int16 *)off_12BE24 + 92)
     - *((unsigned __int16 *)off_12BE24 + 93) < 0 )
  {
    return v0;
  }
  v1 = *(_DWORD *)off_12BE28;
  if ( !*(_DWORD *)off_12BE28 )
    return 1;
  v2 = (unsigned __int16 *)off_12BE24;
  v3 = *(_DWORD *)(v1 + 12);
  v4 = *((unsigned __int16 *)off_12BE24 + 93);
  if ( v3 - *((_DWORD *)off_12BE1C + 4) - 2000 - *((unsigned __int16 *)off_12BE24 + 92) - v4 < 0 )
  {
    if ( **(__int16 **)off_12BE30 < 0 && v3 - *((_DWORD *)off_12BE1C + 4) + 5000 < 0 )
    {
      sub_12F46C(dword_12BE38, dword_12BE34, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(_BYTE **)off_12BE2C != 1 )
      return 1;
    if ( **(__int16 **)off_12BE30 < 0 && v3 - *((_DWORD *)off_12BE1C + 4) - v4 < 0 )
    {
      sub_12F46C(dword_12BE3C, dword_12BE34, 580);
      v3 = *(_DWORD *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = off_12BE1C;
    *((_DWORD *)off_12BE1C + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}

