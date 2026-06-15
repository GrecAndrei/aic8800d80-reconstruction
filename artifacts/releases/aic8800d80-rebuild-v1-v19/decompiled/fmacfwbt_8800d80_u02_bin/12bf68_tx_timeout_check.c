// tx_timeout_check @ 0x12bf68, size 214 bytes
// Doc: tx_timeout_check [tx]: Check TX path for timeout conditions via MMIO register
// tx_timeout_check [tx]: Check TX path for timeout conditions via MMIO register
int tx_timeout_check()
{
  int v0; // r4
  int v1; // r5
  unsigned __int16 *v2; // r6
  int v3; // r2
  int v4; // r1
  _DWORD *v6; // r3

  v0 = (*(_DWORD *)off_12C040 >> 25) & 1;
  if ( (*(_DWORD *)off_12C040 & 0x2000000) == 0
    && 32 * *(_DWORD *)off_12C048
     - 2000
     - *((unsigned __int16 *)off_12C04C + 92)
     - *((unsigned __int16 *)off_12C04C + 93) < 0 )
  {
    return v0;
  }
  v1 = *(_DWORD *)off_12C050;
  if ( !*(_DWORD *)off_12C050 )
    return 1;
  v2 = (unsigned __int16 *)off_12C04C;
  v3 = *(_DWORD *)(v1 + 12);
  v4 = *((unsigned __int16 *)off_12C04C + 93);
  if ( v3 - *((_DWORD *)off_12C044 + 4) - 2000 - *((unsigned __int16 *)off_12C04C + 92) - v4 < 0 )
  {
    if ( **(__int16 **)off_12C058 < 0 && v3 - *((_DWORD *)off_12C044 + 4) + 5000 < 0 )
    {
      sub_12F694(dword_12C060, dword_12C05C, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(_BYTE **)off_12C054 != 1 )
      return 1;
    if ( **(__int16 **)off_12C058 < 0 && v3 - *((_DWORD *)off_12C044 + 4) - v4 < 0 )
    {
      sub_12F694(dword_12C064, dword_12C05C, 580);
      v3 = *(_DWORD *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = off_12C044;
    *((_DWORD *)off_12C044 + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}

