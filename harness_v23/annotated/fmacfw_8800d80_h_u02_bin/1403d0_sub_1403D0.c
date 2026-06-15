// v23 annotated: sub_1403D0 @ 0x1403d0
// Original: 1403d0_sub_1403D0.c
// Primary struct: <unclustered>
//
// sub_1403D0 @ 0x1403d0, size 42 bytes
BOOL sub_1403D0()
{
  int v0; // r5

  v0 = dword_1403FC;
  if ( !*(_DWORD *)(dword_1403FC + 6472) )
    return 1;
  if ( sub_12CD48(0xBu) == 3 )
    return **(_DWORD **)(v0 + 6472) == 0;
  return 0;
}

