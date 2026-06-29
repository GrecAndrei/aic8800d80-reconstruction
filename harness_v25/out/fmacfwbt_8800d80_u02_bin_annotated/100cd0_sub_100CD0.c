// fwstruct annotate: 100cd0_sub_100CD0.c
// sub_100CD0 @ 0x100cd0, size 174 bytes
int __fastcall sub_100CD0(int result)
{
  unsigned int *v1; // r3
  _DWORD *v2; // r1
  unsigned int v3; // r5
  _DWORD *v4; // r4
  _DWORD *v5; // r3

  v1 = (unsigned int *)off_100D84;
  v2 = off_100D88;
  v3 = *(_DWORD *)off_100D84;
  v4 = off_100D8C;
  *(_DWORD *)off_100D88 = (*(unsigned __int8 *)off_100D80 << 10) & 0x1FC00 | *(_DWORD *)off_100D88 & 0xFFFE03FF;
  *v1 |= 0x18u;
  *v1 = *v1 & 0xFFFFFFF8 | 3;
  *v2 |= 0x80000u;
  *v2 |= 0x40000u;
  *v1 = *v1 & 0xFFFFFC1F | 0xE0;
  *v4 &= ~2u;
  *v4 |= 1u;
  if ( !result && ((v3 >> 5) & 0x1F) != 7 )
  {
    v5 = off_100D90;
    *(_DWORD *)off_100D90 |= 0x80u;
    *v5 &= ~0x40u;
    *v5 |= 0x40u;
    *v5 &= ~0x80u;
  }
  return result;
}

