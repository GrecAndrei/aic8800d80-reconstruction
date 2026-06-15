// v23 annotated: sub_126B30 @ 0x126b30
// Original: 126b30_sub_126B30.c
// Primary struct: <unclustered>
//
// sub_126B30 @ 0x126b30, size 124 bytes
void sub_126B30()
{
  int *v0; // r4
  int v1; // r5
  _BYTE *v2; // r7
  int v3; // r8
  _DWORD *v4; // r6

  v0 = *((int **)off_126BAC + 2);
  v1 = *((_DWORD *)off_126BB0 + 10);
  sub_11C210();
  *(_DWORD *)off_126BB4 &= ~4u;
  if ( v0 )
  {
    v2 = off_126BB8;
    v3 = dword_126BC0;
    v4 = off_126BBC;
    do
    {
      while ( 1 )
      {
        if ( v0[18] == v1 && !*((_BYTE *)v0 + 106) && *((_BYTE *)v0 + 108) )
        {
          if ( v2[2] )
            *v4 &= ~0x80000000;
          if ( !*((_BYTE *)v0 + 1224) || *(_BYTE *)(v3 + 140 * *((unsigned __int8 *)v0 + 1225) + 133) )
            break;
        }
        v0 = (int *)*v0;
        if ( !v0 )
          return;
      }
      sub_118F4C(*((unsigned __int8 *)v0 + 116), 0, 0);
      v0 = (int *)*v0;
    }
    while ( v0 );
  }
}

