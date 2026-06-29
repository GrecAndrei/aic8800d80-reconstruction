// fwstruct annotate: 1296ec_sub_1296EC.c
// sub_1296EC @ 0x1296ec, size 86 bytes
int sub_1296EC()
{
  int v0; // r1
  _DWORD *v1; // r0
  _DWORD *v2; // r1
  _DWORD *v3; // r5
  _DWORD *v4; // r2

  v0 = dword_12974C;
  *(_DWORD *)off_129744 |= 0x2000000u;
  feature_guard_sdio(2, v0);
  if ( !*((_BYTE *)off_129750 + 18) )
    *(_DWORD *)off_129754 &= ~1u;
  v1 = off_12975C;
  v2 = off_129754;
  v3 = off_129760;
  v4 = off_129764;
  *(_DWORD *)off_129758 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

