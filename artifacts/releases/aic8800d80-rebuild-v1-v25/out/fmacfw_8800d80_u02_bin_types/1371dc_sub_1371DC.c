// sub_1371DC @ 0x1371dc, size 112 bytes
BOOL  sub_1371DC(unsigned __int8 *a1)
{
  int v1; // r8
  int v3; // r9
  int v4; // r7
  int v5; // r4
  int v6; // r5
  unsigned __int8 *v7; // r10
  int v8; // r2

  v1 = *((unsigned __int8 *)off_13724C + 3898);
  if ( *((uint8_t *)off_13724C + 3898) )
    return sub_143710(a1 + 1, dword_137250, 7) == 0;
  v3 = *(uint32_t *)off_13724C;
  v4 = *(unsigned __int8 *)(*(uint32_t *)off_13724C + 368);
  if ( *(uint8_t *)(*(uint32_t *)off_13724C + 368) )
  {
    v5 = *(uint32_t *)off_13724C;
    v6 = *((unsigned __int8 *)off_13724C + 3898);
    v7 = a1 + 1;
    while ( *(uint8_t *)(v5 + 252) )
    {
      v8 = *a1;
      if ( v8 == *(unsigned __int8 *)(v5 + 252) )
      {
        if ( !sub_143710(v5 + 253, v7, v8) )
          return 1;
        v4 = *(unsigned __int8 *)(v3 + 368);
      }
      ++v6;
      v5 += 33;
      if ( v4 <= v6 )
        return v1;
    }
  }
  return 1;
}

