// v23 annotated: chip_feature_check @ 0x101878
// Original: 101878_chip_feature_check.c
// Primary struct: <unclustered>
//
// chip_feature_check @ 0x101878, size 10 bytes
// Doc: chip_feature_check [util]: Reads chip revision register and extracts a feature flag bit
// chip_feature_check [util]: Reads chip revision register and extracts a feature flag bit
int chip_feature_check()
{
  return (*(_DWORD *)off_101884 >> 21) & 1;
}

