// fwstruct annotate: 114de8_sub_114DE8.c
// sub_114DE8 @ 0x114de8, size 184 bytes
void __noreturn sub_114DE8()
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

  v0 = (_DWORD *)dword_114EA4;
  if ( dword_114EA4 < (unsigned int)dword_114EA8 )
  {
    v1 = ((dword_114EA8 - 1 - dword_114EA4) & 0xFFFFFFFC) + 4 + dword_114EA4;
    do
      *v0++ = 0;
    while ( v0 != (_DWORD *)v1 );
  }
  v2 = dword_114EAC;
  if ( dword_114EAC < (unsigned int)dword_114EB0 )
  {
    v3 = (char *)off_114EB4;
    v4 = (char *)off_114EB4 + ((dword_114EB0 - 1 - dword_114EAC) & 0xFFFFFFFC) + 4;
    v5 = (_DWORD *)dword_114EAC;
    do
    {
      v6 = *(_DWORD *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_114EB8;
  v8 = dword_114EBC;
  *((_DWORD *)off_114EB8 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(_BYTE *)(v10 + 768) = -1;
  }
  if ( (unsigned __int16)*(_DWORD *)off_114EB8 == 49729 )
    *(_DWORD *)off_114EC0 = 1;
  v11 = HIBYTE(*(_DWORD *)off_114EC4);
  *(_BYTE *)off_114EC8 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_114ED0;
    *(_DWORD *)off_114ECC = dword_114ED4;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(_DWORD *)off_114ED8 &= ~0x4000u;
  *(_BYTE *)off_114EDC = BYTE2(*(_DWORD *)off_114EC4);
  sub_1031D8();
  sub_114D6C();
  sub_100478();
}

