// sub_114A68 @ 0x114a68, size 180 bytes
void __noreturn sub_114A68()
{
  _DWORD *v0; // r2
  unsigned int v1; // r3
  int v2; // r1
  char *v3; // r2
  char *v4; // r3
  _DWORD *v5; // r0
  int v6; // t1
  _DWORD *v7; // r2
  int v8; // r0
  int i; // r3
  int v10; // r2
  int v11; // r3
  _BYTE *v12; // r2

  v0 = (_DWORD *)dword_114B20;
  if ( dword_114B20 < (unsigned int)dword_114B24 )
  {
    v1 = ((dword_114B24 - 1 - dword_114B20) & 0xFFFFFFFC) + 4 + dword_114B20;
    do
      *v0++ = 0;
    while ( v0 != (_DWORD *)v1 );
  }
  v2 = dword_114B28;
  if ( dword_114B28 < (unsigned int)dword_114B2C )
  {
    v3 = (char *)off_114B30;
    v4 = (char *)off_114B30 + ((dword_114B2C - 1 - dword_114B28) & 0xFFFFFFFC) + 4;
    v5 = (_DWORD *)dword_114B28;
    do
    {
      v6 = *(_DWORD *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_114B34;
  v8 = dword_114B38;
  *((_DWORD *)off_114B34 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(_BYTE *)(v10 + 768) = -1;
  }
  if ( (unsigned __int16)*(_DWORD *)off_114B34 == 49729 )
    *(_DWORD *)off_114B3C = 1;
  v11 = HIBYTE(*(_DWORD *)off_114B40);
  *(_BYTE *)off_114B44 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_114B4C;
    *(_DWORD *)off_114B48 = dword_114B50;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(_DWORD *)off_114B54 &= ~0x4000u;
  *(_BYTE *)off_114B58 = BYTE2(*(_DWORD *)off_114B40);
  clock_calc();
  lmac_rf_init_globals();
}

