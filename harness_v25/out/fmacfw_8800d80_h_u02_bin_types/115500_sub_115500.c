// sub_115500 @ 0x115500, size 296 bytes
int sub_115500()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r4
  uint32_t *v2; // r2
  uint8_t *v3; // r6
  uint32_t *v4; // r3
  uint8_t **v5; // r5
  int v6; // r3
  int result; // r0
  uint8_t *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1
  uint32_t *v12; // r4

  v0 = off_11562C;
  *((uint32_t *)off_115628 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115634;
  sub_12EB90(2, dword_115630);
  v2 = off_115638;
  *(uint32_t *)off_115638 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = off_11563C;
  if ( *((uint8_t *)off_11563C + 189) && **(__int16 **)off_115640 < 0 && *v1 != (*(uint32_t *)off_115654 & 0xF) )
    sub_12F32C(dword_115670, dword_11566C, 968);
  v4 = off_115638;
  v5 = (uint8_t **)off_115644;
  *(uint32_t *)off_115638 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (unsigned __int8)**v5;
  if ( v6 == 3 )
  {
    *(uint32_t *)off_115668 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(uint32_t *)off_115664 &= ~0x20u;
  }
  if ( *(uint8_t *)off_115648 )
    *(uint32_t *)off_11562C |= 0x2000000u;
  else
    *((uint32_t *)off_115628 + 14) &= ~0x10u;
  result = sub_12EB90(2, dword_11564C);
  v8 = *(uint8_t **)off_115650;
  v9 = **(unsigned __int8 **)off_115650;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(uint32_t *)off_115668 &= ~1u;
  }
  else
  {
    if ( !v3[189] )
    {
      *(uint32_t *)off_115654 = (unsigned __int8)(16 * *v1);
      v9 = (unsigned __int8)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115658;
      v11 = dword_11565C;
      v12 = off_115660;
      do
      {
        if ( *(uint8_t *)(v10 + 37) )
        {
          result = v12[4];
          **(uint32_t **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}

