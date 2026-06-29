// fwstruct annotate: 11f4d8_rf_feature_check.c
// rf_feature_check @ 0x11f4d8, size 40 bytes
// Doc: rf_mem_read_n_b2 [rf]: RF memory read: extract single bit from word at given shift
// rf_mem_read_n_b2 [rf]: RF memory read: extract single bit from word at given shift
BOOL __fastcall rf_feature_check(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(_DWORD *)off_11F500 >> a1) & 1;
  if ( result )
    return *((_DWORD *)off_11F500 + 1) >= a2;
  return result;
}

