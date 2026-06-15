// v23 annotated: sub_138D18 @ 0x138d18
// Original: 138d18_sub_138D18.c
// Primary struct: <unclustered>
//
// sub_138D18 @ 0x138d18, size 132 bytes
_DWORD *__fastcall sub_138D18(int a1, __int16 a2)
{
  void *v2; // r6
  __int16 v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3

  v2 = off_138DA0;
  v4 = a2;
  if ( *((unsigned __int8 *)off_138D9C + 16) == 255 )
  {
    v7 = (*((unsigned __int8 *)off_138DA0 + 10) << 8)
       | (*((unsigned __int8 *)off_138DA0 + 9) << 16)
       | *(_DWORD *)(a1 + 96);
    if ( (a2 & 0x80) == 0 )
    {
      v8 = (*((unsigned __int8 *)off_138DA0 + 10) << 8)
         | (*((unsigned __int8 *)off_138DA0 + 9) << 16)
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
    v5 = *((unsigned __int8 *)off_138DA0 + 10);
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
    v7 = (v5 << 8) | (*((unsigned __int8 *)off_138DA0 + 9) << 16) | *(_DWORD *)(a1 + 96);
  }
  v8 = v7 | 0x82;
  if ( !v6 )
    goto LABEL_10;
LABEL_6:
  v9 = v8 | 0x40;
LABEL_7:
  *(_DWORD *)(a1 + 96) = v9;
  *((_BYTE *)v2 + 50) = 0;
  message_dispatch_n_16e(a1);
  return sub_1389D0(a1, v4, *((_DWORD *)v2 + 16));
}

