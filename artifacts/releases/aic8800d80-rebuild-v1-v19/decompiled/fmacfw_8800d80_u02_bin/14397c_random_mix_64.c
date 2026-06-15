// random_mix_64 @ 0x14397c, size 46 bytes
// Doc: random_mix_64 [util]: Mix 64-bit value using magic constants (PRNG/random)
// random_mix_64 [util]: Mix 64-bit value using magic constants (PRNG/random)
int random_mix_64()
{
  unsigned __int64 v0; // kr00_8

  v0 = *(_QWORD *)(*(_DWORD *)off_1439AC + 168) * __PAIR64__(dword_1439B0, dword_1439B4) + 1;
  *(_QWORD *)(*(_DWORD *)off_1439AC + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

