// fwstruct annotate: 138b74_sub_138B74.c
// sub_138B74 @ 0x138b74, size 92 bytes
_DWORD *__fastcall sub_138B74(int a1, __int16 a2)
{
  _DWORD *v2; // r6
  __int16 v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r3

  v2 = off_138BD0;
  v4 = a2;
  if ( *((unsigned __int8 *)off_138BD4 + 16) != 255 )
  {
    v4 = a2 | 0x80;
LABEL_3:
    v5 = (*((unsigned __int8 *)off_138BD0 + 10) << 8)
       | (*((unsigned __int8 *)off_138BD0 + 9) << 16)
       | (*((unsigned __int8 *)off_138BD0 + 11) << 24)
       | *(_DWORD *)(a1 + 96)
       | 0x80;
    goto LABEL_4;
  }
  if ( (a2 & 0x80) != 0 )
    goto LABEL_3;
  v5 = (*((unsigned __int8 *)off_138BD0 + 10) << 8)
     | (*((unsigned __int8 *)off_138BD0 + 9) << 16)
     | (*((unsigned __int8 *)off_138BD0 + 11) << 24)
     | *(_DWORD *)(a1 + 96) & 0xFFFFFF7F;
LABEL_4:
  if ( (v4 & 1) != 0 )
    v6 = v5 | 0x40;
  else
    v6 = v5 & 0xFFFFFFBF;
  *(_DWORD *)(a1 + 96) = v6;
  sub_11E4C4(a1);
  return sub_138890(a1, v4, v2[16]);
}

