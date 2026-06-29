// fwstruct annotate: 1207e0_chip_version_read_12207E0.c
// chip_version_read_12207E0 @ 0x1207e0, size 138 bytes
// Doc: chip_version_read_12207E0 [util]: Read chip version/revision field (bits 12-27) from MMIO 0x40320200
// chip_version_read_12207E0 [util]: Read chip version/revision field (bits 12-27) from MMIO 0x40320200
int chip_version_read_12207E0()
{
  int result; // r0
  _DWORD *v1; // r1
  _WORD *v2; // r3
  unsigned int v3; // r2
  __int16 v4; // r2
  _DWORD *v5; // r1
  __int16 v6; // r2
  _DWORD *v7; // r1
  __int16 v8; // r2

  if ( (unsigned __int16)(*(_DWORD *)off_12086C >> 12) && (unsigned __int16)(*(_DWORD *)off_12086C >> 12) <= 0x96u )
    result = (unsigned __int16)(*(_DWORD *)off_12086C >> 12);
  else
    result = 150;
  v1 = off_120870;
  v2 = off_120874;
  v3 = *(_DWORD *)off_120870;
  *((_WORD *)off_120874 + 4) = result;
  if ( (unsigned __int16)(v3 >> 12) && (unsigned __int16)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = off_120878;
  v2[5] = v4;
  if ( (unsigned __int16)(*v5 >> 12) && (unsigned __int16)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = off_12087C;
  v2[6] = v6;
  if ( (unsigned __int16)(*v7 >> 12) && (unsigned __int16)(*v7 >> 12) <= 0x96u )
  {
    v8 = *v7 >> 12;
    v2[7] = v8;
    v2[8] = v8;
  }
  else
  {
    v2[7] = 150;
    v2[8] = 150;
  }
  return result;
}

