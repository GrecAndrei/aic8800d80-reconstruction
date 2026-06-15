// v23 annotated: sub_136024 @ 0x136024
// Original: 136024_sub_136024.c
// Primary struct: <unclustered>
//
// sub_136024 @ 0x136024, size 112 bytes
int __fastcall sub_136024(int a1, unsigned __int16 *a2, __int16 a3, __int16 a4)
{
  int v7; // r2
  int v9; // r7
  int v10; // r1
  int v11; // r2
  char v12; // r12

  feature_guard_check(256, dword_136094, *a2);
  v7 = *a2;
  if ( *(_BYTE *)(dword_136098 + 1320 * v7 + 106) == 2 )
  {
    v9 = dword_13609C + 696 * (v7 + 32);
    v10 = *(_DWORD *)(a2 + 3);
    v11 = *(_DWORD *)(a2 + 5);
    v12 = *((_BYTE *)a2 + 14);
    *(_DWORD *)(v9 + 192) = *(_DWORD *)(a2 + 1);
    *(_DWORD *)(v9 + 196) = v10;
    *(_DWORD *)(v9 + 200) = v11;
    *(_BYTE *)(v9 + 204) = v12;
    feature_guard_check(256, dword_1360A0, *((unsigned __int8 *)a2 + 2));
    sub_13289C(v9);
  }
  sub_12CA10(7179, a4, a3);
  return 0;
}

