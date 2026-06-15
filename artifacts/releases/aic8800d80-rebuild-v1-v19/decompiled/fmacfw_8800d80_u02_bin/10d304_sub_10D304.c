// sub_10D304 @ 0x10d304, size 130 bytes
int sub_10D304()
{
  int v0; // r4
  int v2; // r1
  char *v3; // r2
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r1

  if ( (*((_DWORD *)off_10D388 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(_DWORD *)off_10D38C >> 3) & 1;
  if ( (*(_DWORD *)off_10D38C & 8) != 0 )
  {
    v0 = (*(_DWORD *)off_10D38C >> 1) & 1;
    if ( (*(_DWORD *)off_10D38C & 2) != 0 )
    {
      v2 = dword_10D394;
      v3 = (char *)off_10D38C + 5050236;
      *(_DWORD *)off_10D390 = 0x200000;
      *((_DWORD *)v3 + 1) |= 0x400000u;
      feature_guard_check(2, v2);
      do
      {
        v4 = *(_DWORD *)off_10D39C;
        v5 = *(_DWORD *)off_10D39C & 0x300000;
      }
      while ( !v5 );
      v6 = dword_10D3A8;
      *(_DWORD *)off_10D3A4 = v5;
      v0 = (v4 >> 20) & 1;
      feature_guard_check(2, v6);
    }
  }
  return v0;
}

