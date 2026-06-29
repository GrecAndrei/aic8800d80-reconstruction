// sub_111A24 @ 0x111a24, size 162 bytes
int * sub_111A24(int a1, int a2, int a3)
{
  uint32_t *v3; // r6
  int *v4; // r5
  int v5; // r7
  uint32_t *v6; // r4

  if ( a1 )
  {
    v3 = (uint32_t *)(dword_111AC8 + 32 * (a1 - 1) + 8);
    v4 = (int *)(dword_111AC8 + 32 * (a1 - 1));
  }
  else
  {
    v3 = (uint32_t *)dword_111AD4;
    v4 = (int *)dword_111AD8;
  }
  v5 = *v4;
  if ( (*v4 & 0x80008000) != 0 && ((dword_111ACC & v5) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    v6 = off_111AD0;
    *((uint32_t *)off_111AD0 + 513) |= 0x200u;
    while ( (v6[5] & 0x80) == 0 )
      ;
    *v4 |= a2 | 0x8008000;
    if ( a3 )
      *v4 &= ~a3;
    if ( !a1 )
      goto LABEL_10;
    if ( v5 < 0 )
    {
      *v3 = 2;
      *v4 |= 0x40000000u;
      while ( (*v3 & 2) == 0 )
        ;
      if ( (v5 & 0x8000) != 0 )
        goto LABEL_10;
    }
    else if ( (v5 & 0x8000) != 0 )
    {
LABEL_10:
      *((uint32_t *)off_111AD0 + 513) |= 0x400u;
      return sub_11182C(a1);
    }
    *v4 &= ~0x8000u;
    goto LABEL_10;
  }
  return sub_11182C(a1);
}

