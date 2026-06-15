// v23 annotated: sub_138BD8 @ 0x138bd8
// Original: 138bd8_sub_138BD8.c
// Primary struct: <unclustered>
//
// sub_138BD8 @ 0x138bd8, size 132 bytes
_DWORD *__fastcall sub_138BD8(int a1, __int16 a2)
{
  void *v2; // r6
  __int16 v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3

  v2 = off_138C60;
  v4 = a2;
  if ( *((unsigned __int8 *)off_138C5C + 16) == 255 )
  {
    v7 = (*((unsigned __int8 *)off_138C60 + 10) << 8)
       | (*((unsigned __int8 *)off_138C60 + 9) << 16)
       | *(_DWORD *)(a1 + 96);
    if ( (a2 & 0x80) == 0 )
    {
      v8 = (*((unsigned __int8 *)off_138C60 + 10) << 8)
         | (*((unsigned __int8 *)off_138C60 + 9) << 16)
         | *(_DWORD *)(a1 + 96) & 0xFFFFFF7D
         | 2;
      if ( (a2 & 1) != 0 )
        goto LABEL_6;
LABEL_10:
      v9 = v8 & 0xFFFFFFBF;
      goto LABEL_7;
    }
    v6 = a2 & 1;
  }
  else
  {
    v5 = *((unsigned __int8 *)off_138C60 + 10);
    if ( v5 == 255 )
    {
      v6 = 0;
      v4 = 128;
    }
    else
    {
      v6 = a2 & 1;
      v4 |= 0x80u;
    }
    v7 = (v5 << 8) | (*((unsigned __int8 *)off_138C60 + 9) << 16) | *(_DWORD *)(a1 + 96);
  }
  v8 = v7 | 0x82;
  if ( !v6 )
    goto LABEL_10;
LABEL_6:
  v9 = v8 | 0x40;
LABEL_7:
  *(_DWORD *)(a1 + 96) = v9;
  *((_BYTE *)v2 + 50) = 0;
  sub_11E4C4(a1);
  return sub_138890(a1, v4, *((_DWORD *)v2 + 16));
}

