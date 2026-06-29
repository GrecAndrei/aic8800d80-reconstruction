// sub_134F90 @ 0x134f90, size 142 bytes
void  sub_134F90(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r5
  uint8_t *v14; // r7
  int v17; // r1
  int v18; // r2
  __int16 v19; // r5

  v13 = *(uint32_t *)(a1 + 72);
  v14 = off_135020;
  sub_12EB90(256, dword_135024, *((unsigned __int8 *)off_135020 + 34), a2, (unsigned __int8)*(uint16_t *)(v13 + 108));
  if ( !v14[34] )
  {
    sub_134CC4(1, v17, v18, (unsigned __int8)v14[34], a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v19 = *(uint16_t *)(v13 + 108);
  if ( sub_12CD48(6u) != 5 && sub_12CD48(6u) != 8 )
  {
LABEL_5:
    v14[34] = 0;
    return;
  }
  if ( sub_12CD48(6u) == 5 && (v19 & 0xFC) == 0xB0 || sub_12CD48(6u) == 8 && (v19 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      sub_118B34(a1, 5);
      *(uint8_t *)(a1 + 98) = 1;
      return;
    }
    goto LABEL_5;
  }
}

