// v23 annotated: sub_128D64 @ 0x128d64
// Original: 128d64_sub_128D64.c
// Primary struct: <unclustered>
//
// sub_128D64 @ 0x128d64, size 78 bytes
void sub_128D64()
{
  _BYTE *v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // r0

  v0 = off_128DB4;
  if ( *(_BYTE *)off_128DB4 )
  {
    if ( *((_BYTE *)off_128DB4 + 28) )
    {
      v1 = *((_DWORD *)off_128DBC + 2);
      *(_DWORD *)off_128DB8 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = dword_128DC0;
        do
        {
          if ( !*(_BYTE *)(v1 + 106) )
          {
            if ( *(_BYTE *)(v1 + 108) )
            {
              v3 = *(unsigned __int8 *)(v1 + 116);
              if ( v3 != 255 && !sub_118DC4(v3, v2, v1) )
                ++v0[8];
            }
          }
          v1 = *(_DWORD *)v1;
        }
        while ( v1 );
      }
    }
  }
}

