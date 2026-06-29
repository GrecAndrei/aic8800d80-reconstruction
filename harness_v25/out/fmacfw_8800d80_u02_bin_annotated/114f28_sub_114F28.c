// fwstruct annotate: 114f28_sub_114F28.c
// sub_114F28 @ 0x114f28, size 184 bytes
// Doc: patch_apply_n11c [patch]: Apply firmware patch to ROM code
// patch_apply_n11c [patch]: Apply firmware patch to ROM code
void __noreturn sub_114F28()
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

  v0 = (_DWORD *)dword_114FE4;
  if ( dword_114FE4 < (unsigned int)dword_114FE8 )
  {
    v1 = ((dword_114FE8 - 1 - dword_114FE4) & 0xFFFFFFFC) + 4 + dword_114FE4;
    do
      *v0++ = 0;
    while ( v0 != (_DWORD *)v1 );
  }
  v2 = dword_114FEC;
  if ( dword_114FEC < (unsigned int)dword_114FF0 )
  {
    v3 = (char *)off_114FF4;
    v4 = (char *)off_114FF4 + ((dword_114FF0 - 1 - dword_114FEC) & 0xFFFFFFFC) + 4;
    v5 = (_DWORD *)dword_114FEC;
    do
    {
      v6 = *(_DWORD *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_114FF8;
  v8 = dword_114FFC;
  *((_DWORD *)off_114FF8 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(_BYTE *)(v10 + 768) = -1;
  }
  if ( (unsigned __int16)*(_DWORD *)off_114FF8 == 49729 )
    *(_DWORD *)off_115000 = 1;
  v11 = HIBYTE(*(_DWORD *)off_115004);
  *(_BYTE *)off_115008 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_115010;
    *(_DWORD *)off_11500C = dword_115014;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(_DWORD *)patch_apply_n16c &= ~0x4000u;
  *(_BYTE *)patch_apply_n170 = BYTE2(*(_DWORD *)off_115004);
  sub_103258();
  patch_apply_4eac();
  firmware_init();
}

