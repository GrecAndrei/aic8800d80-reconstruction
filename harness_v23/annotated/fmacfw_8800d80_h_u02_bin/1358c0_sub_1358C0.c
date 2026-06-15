// v23 annotated: sub_1358C0 @ 0x1358c0
// Original: 1358c0_sub_1358C0.c
// Primary struct: <unclustered>
//
// sub_1358C0 @ 0x1358c0, size 124 bytes
void __fastcall sub_1358C0(
        unsigned __int16 *a1,
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
  unsigned __int16 *v13; // r6
  int v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r3
  unsigned int v21; // r3

  v13 = a1 + 6;
  sub_12C5FC(6154, 6);
  v15 = v13[2];
  sub_12EB90(256, dword_13593C, v15);
  if ( v15 )
  {
    sub_134CC4(v15, v16, v17, v18, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v19 = a1[6];
  if ( !a1[6] )
  {
LABEL_7:
    sub_135224();
    return;
  }
  if ( v19 != 1 )
  {
    if ( v19 == 2 )
      sub_135838(*((_BYTE *)a1 + 8), (int)(a1 + 9), (unsigned __int16)(*a1 - 6));
    return;
  }
  v20 = v13[1];
  if ( v20 == 4 )
  {
    sub_103268(3000);
    goto LABEL_7;
  }
  if ( v20 == 2 )
  {
    v21 = *a1;
    if ( v21 > 0x22 )
      sub_135028(3, (char *)a1 + 20, v17, v21, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  }
}

