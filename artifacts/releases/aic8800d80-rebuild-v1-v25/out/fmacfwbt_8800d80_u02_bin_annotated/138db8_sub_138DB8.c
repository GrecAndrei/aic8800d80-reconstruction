// fwstruct annotate: 138db8_sub_138DB8.c
// sub_138DB8 @ 0x138db8, size 92 bytes
_DWORD *__fastcall sub_138DB8(int a1, __int16 a2)
{
  _DWORD *v2; // r6
  __int16 v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r3

  v2 = off_138E14;
  v4 = a2;
  if ( *((unsigned __int8 *)off_138E18 + 16) != 255 )
  {
    v4 = a2 | 0x80;
LABEL_3:
    v5 = (*((unsigned __int8 *)off_138E14 + 10) << 8)
       | (*((unsigned __int8 *)off_138E14 + 9) << 16)
       | (*((unsigned __int8 *)off_138E14 + 11) << 24)
       | *(_DWORD *)(a1 + 96)
       | 0x80;
    goto LABEL_4;
  }
  if ( (a2 & 0x80) != 0 )
    goto LABEL_3;
  v5 = (*((unsigned __int8 *)off_138E14 + 10) << 8)
     | (*((unsigned __int8 *)off_138E14 + 9) << 16)
     | (*((unsigned __int8 *)off_138E14 + 11) << 24)
     | *(_DWORD *)(a1 + 96) & 0xFFFFFF7F;
LABEL_4:
  if ( (v4 & 1) != 0 )
    v6 = v5 | 0x40;
  else
    v6 = v5 & 0xFFFFFFBF;
  *(_DWORD *)(a1 + 96) = v6;
  sub_11EA44(a1);
  return sub_138AD4(a1, v4, v2[16]);
}

