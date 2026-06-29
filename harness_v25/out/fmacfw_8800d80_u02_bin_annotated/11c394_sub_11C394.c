// fwstruct annotate: 11c394_sub_11C394.c
// sub_11C394 @ 0x11c394, size 208 bytes
unsigned int __fastcall sub_11C394(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, int *a6)
{
  unsigned int v6; // r4
  int v7; // r8
  int v8; // r0
  int v9; // r9
  unsigned int v10; // r12
  unsigned int v11; // r7
  __int16 **v12; // r4
  __int16 *v13; // r1
  int v14; // r2
  __int16 **v16; // r4
  __int16 *v17; // r1
  int v18; // r2

  v6 = *(_DWORD *)(a1 + 4);
  v7 = *(unsigned __int8 *)(a1 + 12);
  v8 = ((v6 >> 4) & 7) + 1;
  *a6 = v8;
  v9 = (v6 >> 9) & 3;
  v10 = v6 >> 4;
  v11 = v6 & 0xF;
  if ( a2 == 7 && ((v6 >> 7) & 3) == 1 )
  {
    v16 = (__int16 **)off_11C464;
    v17 = *(__int16 **)off_11C464;
    *a3 = dword_11C47C;
    v18 = *v17;
    *a4 = dword_11C480;
    if ( v18 < 0 )
    {
      if ( v11 )
      {
        sub_12F46C(dword_11C48C, dword_11C474, 2707);
        if ( **v16 >= 0 )
          goto LABEL_3;
        v8 = *a6;
      }
      if ( v8 != 1 )
        sub_12F46C(dword_11C484, dword_11C474, 2709);
    }
  }
  else
  {
    v12 = (__int16 **)off_11C464;
    v13 = *(__int16 **)off_11C464;
    *a3 = dword_11C468;
    v14 = *v13;
    *a4 = dword_11C46C;
    if ( v14 < 0 )
    {
      if ( (v10 & 4) == 0 || (sub_12F46C(dword_11C488, dword_11C474, 2717), **v12 < 0) )
      {
        if ( v11 > 0xB )
          sub_12F46C(dword_11C478, dword_11C474, 2718);
      }
    }
  }
LABEL_3:
  *a5 = *(_DWORD *)(dword_11C470 + 696 * v7 + 12);
  return v9 + 6 * v11;
}

