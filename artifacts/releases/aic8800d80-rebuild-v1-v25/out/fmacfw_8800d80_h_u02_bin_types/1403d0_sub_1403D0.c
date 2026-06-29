// sub_1403D0 @ 0x1403d0, size 42 bytes
BOOL sub_1403D0()
{
  int v0; // r5

  v0 = dword_1403FC;
  if ( !*(uint32_t *)(dword_1403FC + 6472) )
    return 1;
  if ( sub_12CD48(0xBu) == 3 )
    return **(uint32_t **)(v0 + 6472) == 0;
  return 0;
}

