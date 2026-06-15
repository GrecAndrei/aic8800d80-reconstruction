// patch_apply_n7c @ 0x115564, size 184 bytes
// Doc: patch_apply_nc8 [patch]: Applies NC8 patch sequence by looping 0x56 iterations to write patch values to indexed offsets
// patch_apply_nc8 [patch]: Applies NC8 patch sequence by looping 0x56 iterations to write patch values to indexed offsets
void __noreturn patch_apply_n7c()
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

  v0 = (_DWORD *)dword_115620;
  if ( dword_115620 < (unsigned int)dword_115624 )
  {
    v1 = ((dword_115624 - 1 - dword_115620) & 0xFFFFFFFC) + 4 + dword_115620;
    do
      *v0++ = 0;
    while ( v0 != (_DWORD *)v1 );
  }
  v2 = dword_115628;
  if ( dword_115628 < (unsigned int)dword_11562C )
  {
    v3 = (char *)off_115630;
    v4 = (char *)off_115630 + ((dword_11562C - 1 - dword_115628) & 0xFFFFFFFC) + 4;
    v5 = (_DWORD *)dword_115628;
    do
    {
      v6 = *(_DWORD *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_115634;
  v8 = dword_115638;
  *((_DWORD *)off_115634 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(_BYTE *)(v10 + 768) = -1;
  }
  if ( (unsigned __int16)*(_DWORD *)off_115634 == 49729 )
    *(_DWORD *)off_11563C = 1;
  v11 = HIBYTE(*(_DWORD *)off_115640);
  *(_BYTE *)off_115644 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_11564C;
    *(_DWORD *)off_115648 = dword_115650;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(_DWORD *)off_115654 &= ~0x4000u;
  *(_BYTE *)off_115658 = BYTE2(*(_DWORD *)off_115640);
  sub_1030B0();
  sub_1154E8();
  firmware_init_0478();
}

