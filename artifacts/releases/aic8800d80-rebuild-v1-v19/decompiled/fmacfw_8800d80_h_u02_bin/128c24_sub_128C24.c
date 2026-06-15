// sub_128C24 @ 0x128c24, size 78 bytes
void sub_128C24()
{
  _BYTE *v0; // r5
  int v1; // r4
  void *v2; // r6
  int v3; // r0

  v0 = off_128C74;
  if ( *(_BYTE *)off_128C74 )
  {
    if ( *((_BYTE *)off_128C74 + 28) )
    {
      v1 = *((_DWORD *)off_128C7C + 2);
      *(_DWORD *)off_128C78 |= 4u;
      v0[8] = 0;
      if ( v1 )
      {
        v2 = off_128C80;
        do
        {
          if ( !*(_BYTE *)(v1 + 106) )
          {
            if ( *(_BYTE *)(v1 + 108) )
            {
              v3 = *(unsigned __int8 *)(v1 + 116);
              if ( v3 != 255 && !sub_118C84(v3, (int)v2, v1) )
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

