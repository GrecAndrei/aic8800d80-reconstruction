// sub_10D15C @ 0x10d15c, size 130 bytes
int sub_10D15C()
{
  int v0; // r4
  int v2; // r1
  char *v3; // r2
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r1

  if ( (*((_DWORD *)off_10D1E0 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(_DWORD *)off_10D1E4 >> 3) & 1;
  if ( (*(_DWORD *)off_10D1E4 & 8) != 0 )
  {
    v0 = (*(_DWORD *)off_10D1E4 >> 1) & 1;
    if ( (*(_DWORD *)off_10D1E4 & 2) != 0 )
    {
      v2 = dword_10D1EC;
      v3 = (char *)off_10D1E4 + 5050236;
      *(_DWORD *)off_10D1E8 = 0x200000;
      *((_DWORD *)v3 + 1) |= 0x400000u;
      sub_12EEF8(2, v2);
      do
      {
        v4 = *(_DWORD *)off_10D1F4;
        v5 = *(_DWORD *)off_10D1F4 & 0x300000;
      }
      while ( !v5 );
      v6 = dword_10D200;
      *(_DWORD *)off_10D1FC = v5;
      v0 = (v4 >> 20) & 1;
      sub_12EEF8(2, v6);
    }
  }
  return v0;
}

