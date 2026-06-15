// sub_10D1C4 @ 0x10d1c4, size 130 bytes
int sub_10D1C4()
{
  int v0; // r4
  int v2; // r1
  char *v3; // r2
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r1

  if ( (*((_DWORD *)off_10D248 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(_DWORD *)off_10D24C >> 3) & 1;
  if ( (*(_DWORD *)off_10D24C & 8) != 0 )
  {
    v0 = (*(_DWORD *)off_10D24C >> 1) & 1;
    if ( (*(_DWORD *)off_10D24C & 2) != 0 )
    {
      v2 = dword_10D254;
      v3 = (char *)off_10D24C + 5050236;
      *(_DWORD *)off_10D250 = 0x200000;
      *((_DWORD *)v3 + 1) |= 0x400000u;
      sub_12EB90(2, v2);
      do
      {
        v4 = *(_DWORD *)off_10D25C;
        v5 = *(_DWORD *)off_10D25C & 0x300000;
      }
      while ( !v5 );
      v6 = dword_10D268;
      *(_DWORD *)off_10D264 = v5;
      v0 = (v4 >> 20) & 1;
      sub_12EB90(2, v6);
    }
  }
  return v0;
}

