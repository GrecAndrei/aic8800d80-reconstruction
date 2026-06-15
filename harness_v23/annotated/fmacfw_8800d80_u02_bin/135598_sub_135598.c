// v23 annotated: sub_135598 @ 0x135598
// Original: 135598_sub_135598.c
// Primary struct: <unclustered>
//
// sub_135598 @ 0x135598, size 186 bytes
void __fastcall sub_135598(
        char *a1,
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
  int v14; // r8
  unsigned int v15; // r1
  int v16; // r6
  int v17; // r3
  int v18; // r1
  char *v19; // r4
  int v20; // r12
  char *v21; // r3
  char v22; // t1
  int v23; // r1
  int v24; // r2
  int v25; // r1

  v14 = *((_DWORD *)off_135654 + 5);
  sub_12C73C(6154, 6);
  v15 = *(unsigned __int16 *)a1;
  v16 = *((unsigned __int16 *)a1 + 7);
  if ( v15 <= 5 )
  {
    v25 = dword_13565C;
    *(_WORD *)(v14 + 16) = 0;
    sub_12ECD0(256, v25, v16);
    if ( !v16 )
    {
LABEL_9:
      sub_135564(*((_WORD *)a1 + 8) & 0x3FFF);
      return;
    }
  }
  else
  {
    v17 = *(unsigned __int16 *)(v14 + 14);
    v18 = (unsigned __int16)(v15 - 6);
    v19 = a1 + 18;
    if ( v18 + v17 > 800 )
    {
      if ( **(__int16 **)off_135658 < 0 )
      {
        sub_12F49C(dword_135664, dword_135660, 1236);
        v17 = *(unsigned __int16 *)(v14 + 14);
      }
      v18 = (unsigned __int16)(800 - v17);
    }
    v20 = v14 + 20 + v17;
    if ( v18 )
    {
      do
      {
        v21 = v19 - 18;
        v22 = *v19++;
        *(_BYTE *)(v21 - a1 + v20) = v22;
      }
      while ( v19 != &a1[v18 + 18] );
    }
    *(_WORD *)(v14 + 16) = v18;
    sub_12ECD0(256, dword_13565C, v16);
    if ( !v16 )
      goto LABEL_9;
  }
  sub_134E04(v16, v23, v24, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}

