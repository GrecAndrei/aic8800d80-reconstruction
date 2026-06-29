// fwstruct annotate: 114d6c_sub_114D6C.c
// sub_114D6C @ 0x114d6c, size 112 bytes
void sub_114D6C()
{
  _DWORD *v0; // r3
  int v1; // r2
  unsigned int v2; // r1
  int v3; // r4
  _DWORD *v4; // t1
  int *v5; // r2
  int v6; // r5
  int v7; // r0
  int v8; // t1
  _DWORD *v9; // r3
  unsigned int v10; // r1
  int v11; // r0

  v0 = off_114DDC;
  if ( *(_DWORD *)off_114DDC == dword_114DE0 && *((_DWORD *)off_114DDC + 2) == dword_114DE0 + 135327480 )
  {
    v1 = *((_DWORD *)off_114DDC + 1);
    v2 = v1 & 3;
    if ( (v1 & 3) == 0 )
    {
      if ( *((_DWORD *)off_114DDC + 3) )
      {
        do
        {
          v3 = *(_DWORD *)(v1 + 4);
          v4 = *(_DWORD **)v1;
          v1 += 8;
          *v4 = v3;
          ++v2;
        }
        while ( v0[3] > v2 );
      }
      v5 = (int *)dword_114DE4;
      v6 = dword_114DE4 + 16;
      do
      {
        v8 = *v5++;
        v7 = v8;
        if ( !(v8 << 30) )
        {
          v9 = (_DWORD *)v5[3];
          v10 = (unsigned __int8)v9 & 3;
          if ( ((unsigned __int8)v9 & 3) == 0 )
          {
            if ( v5[7] )
            {
              v11 = v7 - (_DWORD)v9;
              do
              {
                *(_DWORD *)((char *)v9 + v11) = *v9;
                ++v10;
                ++v9;
              }
              while ( v10 < v5[7] );
            }
          }
        }
      }
      while ( v5 != (int *)v6 );
    }
  }
}

