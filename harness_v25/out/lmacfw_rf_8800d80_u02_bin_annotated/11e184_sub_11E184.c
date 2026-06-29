// fwstruct annotate: 11e184_sub_11E184.c
// sub_11E184 @ 0x11e184, size 82 bytes
int __fastcall sub_11E184(int a1, int *a2, int a3)
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
  if ( **(__int16 **)off_11E1D8 < 0 && !result )
  {
    rf_cmd_send_n264(dword_11E1E0, dword_11E1DC, 239);
    return *(_DWORD *)(v7 + *a2 + 4);
  }
  return result;
}

