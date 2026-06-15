// v23 annotated: sub_131548 @ 0x131548
// Original: 131548_sub_131548.c
// Primary struct: <unclustered>
//
// sub_131548 @ 0x131548, size 182 bytes
int __fastcall sub_131548(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v5; // r5
  int v6; // r8
  char v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r3
  char v13; // r2
  int v14; // r0
  int v15; // r5
  char v16; // r3

  v5 = *a2;
  v6 = dword_131600;
  if ( !a2[2] )
  {
    v12 = dword_131600 + 696 * v5;
    if ( a2[1] )
      v13 = *(_BYTE *)(v12 + 53) | 1;
    else
      v13 = *(_BYTE *)(v12 + 53) & 0xFE;
    *(_BYTE *)(v12 + 53) = v13;
    goto LABEL_9;
  }
  if ( a2[1] )
    v9 = *(_BYTE *)(dword_131600 + 696 * v5 + 53) | 4;
  else
    v9 = *(_BYTE *)(dword_131600 + 696 * v5 + 53) & 0xFB;
  v10 = dword_131600 + 696 * v5;
  v11 = *(unsigned __int8 *)(v10 + 310);
  *(_BYTE *)(v10 + 53) = v9;
  if ( v11 == 15 )
  {
LABEL_9:
    v14 = sub_12C92C(65, 0, 5, 4u);
    v15 = v6 + 696 * v5;
    v16 = *(_BYTE *)(v15 + 34);
    *(_WORD *)v14 = *(_WORD *)(v15 + 32);
    *(_BYTE *)(v14 + 3) = v16;
    *(_BYTE *)(v14 + 2) = a2[1];
    sub_12C98C(v14);
  }
  sub_12CA10(5133, a4, a3);
  return 0;
}

