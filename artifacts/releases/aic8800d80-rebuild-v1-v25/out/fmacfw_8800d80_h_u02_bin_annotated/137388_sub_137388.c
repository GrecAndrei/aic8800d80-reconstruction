// fwstruct annotate: 137388_sub_137388.c
// sub_137388 @ 0x137388, size 212 bytes
_DWORD *__fastcall sub_137388(int a1)
{
  _WORD *v2; // r4
  _BYTE **v3; // r7
  __int16 v4; // r0
  _BYTE *v5; // r5
  int *v6; // r2
  unsigned __int16 *v7; // r0
  int v8; // r1
  int v9; // r0
  _DWORD *v11; // r3

  if ( *(_BYTE *)off_13745C )
    sub_102AD0(*((_BYTE *)off_13748C + 9));
  v2 = off_137460;
  v3 = (_BYTE **)off_137464;
  if ( *((_BYTE *)off_137460 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (_BYTE *)sub_12C7EC(v4, *((_WORD *)off_137460 + 1924), 4, 3u);
  sub_12EB90(
    8,
    dword_13746C,
    dword_137468,
    *(unsigned __int8 *)(*(_DWORD *)v2 + 366),
    *((unsigned __int8 *)v2 + 3850),
    a1);
  v6 = (int *)off_137474;
  v7 = (unsigned __int16 *)off_137478;
  *(_DWORD *)off_137470 &= ~4u;
  v8 = *v7;
  v9 = *(_DWORD *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(_BYTE *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && *((_BYTE *)off_137480 + 189) )
  {
    v11 = off_137488;
    *(_DWORD *)off_137484 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  sub_12C8F8(v9 - 12);
  *(_DWORD *)v2 = 0;
  sub_12C84C((int)v5);
  *((_DWORD *)off_13747C + 1) &= ~0x20u;
  return sub_12CBF4(4u, 0);
}

