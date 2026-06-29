// fwstruct annotate: 108090_sub_108090.c
// sub_108090 @ 0x108090, size 56 bytes
// Doc: sub_1208090 [unknown]: Unknown utility function at 0x108090
// sub_1208090 [unknown]: Unknown utility function at 0x108090
int sub_108090()
{
  unsigned int *v0; // r5
  int v1; // r6
  __int16 v2; // r4
  int result; // r0
  _DWORD *v4; // r1

  v0 = (unsigned int *)off_1080CC;
  v1 = *(_DWORD *)off_1080CC;
  v2 = (unsigned __int16)*(_DWORD *)off_1080C8 >> 4;
  result = feature_guard_sdio(1, dword_1080D0);
  v4 = off_1080D4;
  *v0 = (v2 + (_WORD)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

