// v23 annotated: sub_102E08 @ 0x102e08
// Original: 102e08_sub_102E08.c
// Primary struct: <unclustered>
//
// sub_102E08 @ 0x102e08, size 136 bytes
int __fastcall sub_102E08(int a1, int a2, unsigned int a3, int a4)
{
  int v6; // r6
  int v7; // r4
  int v8; // r10
  int v9; // r12
  int v10; // r2
  int v11; // r6
  int v12; // lr
  int *v13; // r7
  int *v14; // r1
  _DWORD *v15; // r4
  int v16; // t1
  int result; // r0

  if ( a1 )
  {
    v6 = 16 * (dword_102E98 + a2);
    v7 = 4;
    v8 = 3;
  }
  else
  {
    v6 = 32 * (dword_102E90 + a2);
    v7 = 8;
    v8 = 5;
  }
  while ( !*(_DWORD *)off_102E94 )
    ;
  sub_102BF8(a1);
  if ( a3 )
  {
    v9 = 0;
    v10 = 4 * (v7 - v8);
    v11 = v6 - a4;
    v12 = 0;
    v13 = (int *)(a4 + 4 * v8);
    do
    {
      v14 = (int *)(a4 + 4 * v9);
      do
      {
        v15 = (int *)((char *)v14 + v11);
        v16 = *v14++;
        *v15 = v16;
      }
      while ( v13 != v14 );
      ++v12;
      v9 += v8;
      v11 += v10;
      v13 += v8;
    }
    while ( a3 > (unsigned __int8)v12 );
  }
  result = sub_102C5C(a1);
  *(_DWORD *)off_102E94 = 1;
  return result;
}

