// v23 annotated: rf_feature_check @ 0x12ea5c
// Original: 12ea5c_rf_feature_check.c
// Primary struct: <unclustered>
//
// rf_feature_check @ 0x12ea5c, size 40 bytes
// Doc: rf_feature_check [rf]: Check supported RF feature index / capability
// rf_feature_check [rf]: Check supported RF feature index / capability
BOOL __fastcall rf_feature_check(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(_DWORD *)off_12EA84 >> a1) & 1;
  if ( result )
    return *((_DWORD *)off_12EA84 + 1) >= a2;
  return result;
}

