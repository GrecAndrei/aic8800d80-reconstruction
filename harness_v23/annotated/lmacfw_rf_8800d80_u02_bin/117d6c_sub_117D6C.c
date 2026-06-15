// v23 annotated: sub_117D6C @ 0x117d6c
// Original: 117d6c_sub_117D6C.c
// Primary struct: <unclustered>
//
// sub_117D6C @ 0x117d6c, size 70 bytes
// Doc: sub_1217D6C [unknown]: Push-context helper loading offset 0x30 from argument struct
// sub_1217D6C [unknown]: Push-context helper loading offset 0x30 from argument struct
int __fastcall sub_117D6C(int a1, int a2, int a3)
{
  int v3; // r4
  int v6; // r8
  int v7; // r0
  int v8; // r1

  v3 = *(_DWORD *)(a2 + 48);
  if ( v3 )
  {
    v3 = 0;
    v6 = a2 + 48;
    do
    {
      if ( !is_flag_set_clz() )
        break;
      v7 = sub_11E7AC(v6);
      v8 = *(unsigned __int8 *)(v7 + 14);
      *(_BYTE *)(v7 + 53) = 0;
      ++v3;
      rf_subcmd_dispatch_n5b60(v7, v8);
      if ( a3 )
      {
        if ( v3 == a3 )
          break;
      }
    }
    while ( *(_DWORD *)(a2 + 48) );
  }
  return v3;
}

