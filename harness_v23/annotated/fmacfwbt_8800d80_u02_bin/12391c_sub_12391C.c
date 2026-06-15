// v23 annotated: sub_12391C @ 0x12391c
// Original: 12391c_sub_12391C.c
// Primary struct: <unclustered>
//
// sub_12391C @ 0x12391c, size 142 bytes
int __fastcall sub_12391C(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r1
  BOOL v9; // r0
  int v10; // r2
  char v11; // r6
  _BYTE *v12; // r0
  BOOL v14; // r0
  int v15; // r3
  int v16; // r1

  v5 = *a2;
  v6 = a2[1];
  v7 = a2[2];
  if ( v5 )
  {
    v14 = sub_121BC0(v6, v7);
    v10 = a3;
    if ( v14 )
    {
      sub_13A4FC(dword_1239AC + 696 * a2[1], a2[2], a3);
      v11 = 2;
      v10 = a3;
      goto LABEL_4;
    }
  }
  else
  {
    v9 = sub_121B9C(v6, v7);
    v10 = a3;
    if ( v9 )
    {
      v15 = 696 * a2[1];
      v16 = dword_1239B0 + 32 * *(unsigned __int8 *)(v15 + 12 * a2[2] + dword_1239AC + 453);
      *(_WORD *)(v15 + 6 * a2[2] + dword_1239AC + 354) = 0;
      *(_WORD *)(v16 + 12) = 0;
      v11 = 2;
      goto LABEL_4;
    }
  }
  v11 = 3;
LABEL_4:
  v12 = (_BYTE *)sub_12CB54(43, a4, v10, 3);
  *v12 = a2[1];
  v12[1] = a2[2];
  v12[2] = v11;
  sub_12CBB4(v12);
  return 0;
}

