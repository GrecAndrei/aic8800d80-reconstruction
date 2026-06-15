// v23 annotated: sub_124244 @ 0x124244
// Original: 124244_sub_124244.c
// Primary struct: <unclustered>
//
// sub_124244 @ 0x124244, size 144 bytes
unsigned int __fastcall sub_124244(unsigned int result, unsigned int a2, int a3)
{
  int v3; // r2
  int v4; // r3
  int v5; // r2
  int v6; // r5
  int v7; // r4
  int v8; // r3
  unsigned int *v9; // r1
  unsigned int v10; // t1

  if ( result <= 1 )
  {
    if ( !result && a2 <= 3 )
    {
      *(_DWORD *)off_1242D4 = 0;
      return result;
    }
    v4 = dword_1242E0;
    v3 = 512;
    *(_DWORD *)off_1242D4 = 512;
  }
  else if ( result > 4 )
  {
    if ( a3 )
    {
      v3 = 2048;
      v4 = dword_1242EC;
    }
    else
    {
      v3 = 2048;
      v4 = dword_1242DC;
    }
    *(_DWORD *)off_1242D4 = 2048;
  }
  else
  {
    if ( a3 )
    {
      v3 = 512;
      v4 = dword_1242E8;
    }
    else
    {
      v3 = 512;
      v4 = dword_1242D8;
    }
    *(_DWORD *)off_1242D4 = 512;
  }
  v5 = v4 + 4 * v3 - 4;
  v6 = (*(_DWORD *)off_1242E4 >> 5) & 3;
  *(_DWORD *)off_1242E4 &= 0xFFFFFF9F;
  v7 = 1048580 - v4;
  v8 = v4 - 4;
  do
  {
    v9 = (unsigned int *)(v7 + v8);
    v10 = *(_DWORD *)(v8 + 4);
    v8 += 4;
    result = v10;
    *v9 = v10;
  }
  while ( v8 != v5 );
  if ( v6 )
    *(_DWORD *)off_1242E4 = *(_DWORD *)off_1242E4 & 0xFFFFFF9F | (32 * v6);
  return result;
}

