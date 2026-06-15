// rf_stream_start2_n_14 @ 0x1375f0, size 76 bytes
// Doc: rf_stream_start2_n_14 [rf]: Starts secondary RF stream with mask and length setup
// rf_stream_start2_n_14 [rf]: Starts secondary RF stream with mask and length setup
int __fastcall rf_stream_start2_n_14(unsigned __int16 *a1, int a2)
{
  int v2; // r3
  int v3; // r4

  v2 = dword_13763C;
  v3 = dword_13763C + 3840;
  do
  {
    while ( !*(_BYTE *)v2 )
    {
      if ( a2 )
      {
        *(_BYTE *)(v2 + 56) = 0x80;
        return v2;
      }
LABEL_3:
      v2 += 60;
      if ( v2 == v3 )
        return 0;
    }
    if ( *(unsigned __int16 *)(v2 + 2) != *a1 || *(unsigned __int16 *)(v2 + 4) != a1[1] )
      goto LABEL_3;
    if ( *(unsigned __int16 *)(v2 + 6) == a1[2] )
      return v2;
    v2 += 60;
  }
  while ( v2 != v3 );
  return 0;
}

