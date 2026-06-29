// sub_115640 @ 0x115640, size 296 bytes
int sub_115640()
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

  v0 = off_11576C;
  *((uint32_t *)off_115768 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115774;
  sub_12ECD0(2, dword_115770);
  v2 = off_115778;
  *(uint32_t *)off_115778 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = off_11577C;
  if ( *((uint8_t *)off_11577C + 189) && **(__int16 **)off_115780 < 0 && *v1 != (*(uint32_t *)off_115794 & 0xF) )
    sub_12F46C(dword_1157B0, dword_1157AC, 968);
  v4 = off_115778;
  v5 = (uint8_t **)off_115784;
  *(uint32_t *)off_115778 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (unsigned __int8)**v5;
  if ( v6 == 3 )
  {
    *(uint32_t *)off_1157A8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(uint32_t *)off_1157A4 &= ~0x20u;
  }
  if ( *(uint8_t *)off_115788 )
    *(uint32_t *)off_11576C |= 0x2000000u;
  else
    *((uint32_t *)off_115768 + 14) &= ~0x10u;
  result = sub_12ECD0(2, dword_11578C);
  v8 = *(uint8_t **)off_115790;
  v9 = **(unsigned __int8 **)off_115790;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(uint32_t *)off_1157A8 &= ~1u;
  }
  else
  {
    if ( !v3[189] )
    {
      *(uint32_t *)off_115794 = (unsigned __int8)(16 * *v1);
      v9 = (unsigned __int8)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115798;
      v11 = dword_11579C;
      v12 = off_1157A0;
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

