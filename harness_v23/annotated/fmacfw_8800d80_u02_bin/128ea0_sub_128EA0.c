// v23 annotated: sub_128EA0 @ 0x128ea0
// Original: 128ea0_sub_128EA0.c
// Primary struct: <unclustered>
//
// sub_128EA0 @ 0x128ea0, size 72 bytes
void sub_128EA0()
{
  _BYTE *v0; // r5
  unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  int v4; // r6
  int v5; // r0

  v0 = off_128EE8;
  if ( !*((_BYTE *)off_128EE8 + 28) )
  {
    v1 = (unsigned int *)off_128EEC;
    v2 = *(_DWORD *)off_128EEC;
    v3 = *((_DWORD *)off_128EF0 + 2);
    *((_BYTE *)off_128EE8 + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = dword_128EF4;
      do
      {
        if ( !*(_BYTE *)(v3 + 106) )
        {
          if ( *(_BYTE *)(v3 + 108) )
          {
            v5 = *(unsigned __int8 *)(v3 + 116);
            if ( v5 != 255 && !sub_118DC4(v5, v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(_DWORD *)v3;
      }
      while ( v3 );
    }
  }
}

