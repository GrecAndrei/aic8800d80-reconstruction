// v23 annotated: sub_12CB94 @ 0x12cb94
// Original: 12cb94_sub_12CB94.c
// Primary struct: <unclustered>
//
// sub_12CB94 @ 0x12cb94, size 82 bytes
int __fastcall sub_12CB94(int a1, int *a2, int a3)
{
  int v3; // r3
  int v5; // r2
  int v6; // r4
  int v7; // r6
  int v8; // r5
  int result; // r0

  if ( !a3 )
    return 0;
  v3 = a3 - 1;
  v5 = *a2;
  while ( 1 )
  {
    v6 = *(unsigned __int16 *)(v5 + 8 * v3);
    v7 = 8 * v3;
    v8 = v5 + 8 * v3--;
    if ( v6 == a1 )
      break;
    if ( v3 == -1 )
      return 0;
  }
  result = *(_DWORD *)(v8 + 4);
  if ( **(__int16 **)off_12CBE8 < 0 && !result )
  {
    sub_12F32C(dword_12CBF0, dword_12CBEC, 239);
    return *(_DWORD *)(v7 + *a2 + 4);
  }
  return result;
}

