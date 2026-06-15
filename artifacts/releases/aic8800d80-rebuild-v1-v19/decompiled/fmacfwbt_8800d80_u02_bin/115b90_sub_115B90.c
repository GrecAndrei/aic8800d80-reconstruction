// sub_115B90 @ 0x115b90, size 296 bytes
int sub_115B90()
{
  _DWORD *v0; // r2
  _BYTE *v1; // r4
  _DWORD *v2; // r2
  _BYTE *v3; // r6
  _DWORD *v4; // r3
  _BYTE **v5; // r5
  int v6; // r3
  int result; // r0
  _BYTE *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1
  _DWORD *v12; // r4

  v0 = off_115CBC;
  *((_DWORD *)off_115CB8 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115CC4;
  feature_guard_sdio(2, dword_115CC0);
  v2 = off_115CC8;
  *(_DWORD *)off_115CC8 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = off_115CCC;
  if ( *((_BYTE *)off_115CCC + 189) && **(__int16 **)off_115CD0 < 0 && *v1 != (*(_DWORD *)off_115CE4 & 0xF) )
    sub_12F694(dword_115D00, dword_115CFC, 968);
  v4 = off_115CC8;
  v5 = (_BYTE **)off_115CD4;
  *(_DWORD *)off_115CC8 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (unsigned __int8)**v5;
  if ( v6 == 3 )
  {
    *(_DWORD *)off_115CF8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(_DWORD *)off_115CF4 &= ~0x20u;
  }
  if ( *(_BYTE *)off_115CD8 )
    *(_DWORD *)off_115CBC |= 0x2000000u;
  else
    *((_DWORD *)off_115CB8 + 14) &= ~0x10u;
  result = feature_guard_sdio(2, dword_115CDC);
  v8 = *(_BYTE **)off_115CE0;
  v9 = **(unsigned __int8 **)off_115CE0;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(_DWORD *)off_115CF8 &= ~1u;
  }
  else
  {
    if ( !v3[189] )
    {
      *(_DWORD *)off_115CE4 = (unsigned __int8)(16 * *v1);
      v9 = (unsigned __int8)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115CE8;
      v11 = dword_115CEC;
      v12 = off_115CF0;
      do
      {
        if ( *(_BYTE *)(v10 + 37) )
        {
          result = v12[4];
          **(_DWORD **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}

