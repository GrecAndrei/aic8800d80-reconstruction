// rf_feature_check @ 0x12ea5c, size 40 bytes
// Doc: rf_feature_check [rf]: Check supported RF feature index / capability
// rf_feature_check [rf]: Check supported RF feature index / capability
BOOL  rf_feature_check(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(uint32_t *)off_12EA84 >> a1) & 1;
  if ( result )
    return *((uint32_t *)off_12EA84 + 1) >= a2;
  return result;
}

