// fwstruct annotate: 11bac0_sub_11BAC0.c
// sub_11BAC0 @ 0x11bac0, size 374 bytes
unsigned __int8 *__fastcall sub_11BAC0(unsigned __int8 *result)
{
  unsigned int v1; // r4
  int v2; // r5
  unsigned __int8 *v3; // r1
  int v4; // r6
  int v5; // r11
  char v6; // lr
  unsigned int v7; // r2
  unsigned int v8; // r10
  unsigned int v9; // r0
  unsigned int v10; // r3
  unsigned int v11; // t1
  int v12; // r7
  int v13; // r3
  int *v14; // r12
  unsigned int v15; // r5
  int v16; // r4
  unsigned int v17; // r2
  int v18; // r3
  int v19; // r10
  int v20; // r1
  unsigned int v21; // r10
  unsigned int v22; // r0
  unsigned int v23; // [sp+0h] [bp-1Ch]
  int v24; // [sp+4h] [bp-18h]
  int v25[5]; // [sp+8h] [bp-14h] BYREF

  v1 = result[106];
  if ( !result[106] )
  {
    if ( result[108] )
    {
      v24 = result[116];
      v2 = dword_11BC38 + 696 * v24;
      if ( *(_BYTE *)(v2 + 37) )
      {
        if ( (*(_DWORD *)(v2 + 4) & 0x20) != 0 )
        {
          sub_100200(v25, v1, 0x10u);
          v3 = (unsigned __int8 *)dword_11BC40;
          v23 = v1;
          v4 = 36 * *(unsigned __int8 *)(v2 + 35) + 8244 + dword_11BC3C;
          v5 = dword_11BC40 + 8;
          v6 = v1;
          v7 = v1;
          v8 = v1;
          v9 = v1;
          do
          {
            v11 = *(_DWORD *)(v4 + 4);
            v4 += 4;
            v10 = v11;
            v12 = v11;
            if ( v11 >= 0x7F0000 )
              v12 = 8323072;
            if ( v10 )
            {
              v13 = *(unsigned __int8 *)(dword_11BC44 + *v3);
              v14 = &v25[v13 + 4];
              v15 = *(v14 - 4) + v12;
              if ( v15 > v8 )
              {
                v8 = *(v14 - 4) + v12;
                v23 = *(unsigned __int8 *)(dword_11BC44 + *v3);
              }
              v1 = (unsigned __int8)(v1 + 1);
              v9 += v12;
              *(v14 - 4) = v15;
              if ( ((v7 >> v13) & 1) == 0 )
              {
                v7 = (unsigned __int8)(v7 | (1 << v13));
                ++v6;
              }
            }
            ++v3;
          }
          while ( (unsigned __int8 *)v5 != v3 );
          if ( v1 == 8 )
          {
            v16 = 3072;
            v17 = 0;
          }
          else
          {
            v16 = (unsigned __int8)(v1 - v6) << 10;
            v17 = v7 << 6;
          }
          if ( v9 > 0xFD0 )
          {
            if ( v9 <= 0xFD00 )
            {
              v18 = (unsigned __int8)((unsigned __int16)(v9 + 255) >> 8);
              v19 = (unsigned __int8)((unsigned __int16)(v8 + 255) >> 8);
              v20 = 0x4000;
            }
            else if ( v9 > 0x7E800 )
            {
              if ( v8 > 0x7F0000 )
                v21 = 8355839;
              else
                v21 = v8 + 0x7FFF;
              if ( v9 > 0x7F0000 )
                v22 = 8355839;
              else
                v22 = v9 + 0x7FFF;
              v18 = (unsigned __int8)(v22 >> 15);
              v19 = (unsigned __int8)(v21 >> 15);
              v20 = 49152;
            }
            else
            {
              v18 = (unsigned __int8)((v9 + 2047) >> 11);
              v19 = (unsigned __int8)((v8 + 2047) >> 11);
              v20 = 0x8000;
            }
          }
          else
          {
            v18 = (unsigned __int8)((v9 + 15) >> 4);
            v19 = (unsigned __int8)((v8 + 15) >> 4);
            v20 = 0;
          }
          *(_DWORD *)(dword_11BC38 + 696 * v24 + 580) = (v18 << 24) | (v23 << 12) | v17 | v16 | v20 | (v19 << 16) | 0xF;
          return (unsigned __int8 *)v24;
        }
      }
    }
  }
  return result;
}

