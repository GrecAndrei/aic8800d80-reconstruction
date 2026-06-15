// v23 annotated: sub_118908 @ 0x118908
// Original: 118908_sub_118908.c
// Primary struct: group_11 (cluster 11)
//
// sub_118908 @ 0x118908, size 118 bytes
// Doc: sub_1218914 [unknown]: Indexed table entry lookup with multiplied offset
// sub_1218914 [unknown]: Indexed table entry lookup with multiplied offset
int __fastcall sub_118908(int result)
{
  int v1; // r5
  int v2; // r4
  unsigned int v3; // r3
  unsigned __int8 *v4; // r2
  unsigned int v5; // r2
  int v6; // [sp+4h] [bp-14h]

  if ( *(_BYTE *)(result + 96) )
  {
    v1 = *(_DWORD *)(result + 36);
    v2 = result;
    v6 = *(_DWORD *)(dword_118980 + 152 * *(unsigned __int8 *)(result + 102) + 8) + v1;
    sub_11AB18(result + 24, v6);
    sub_118310(v2);
    result = unknown_helper_2(v2, v1, v6);
    if ( !result )
    {
      v3 = (unsigned __int8)(*(_BYTE *)(v2 + 116) + 1);
      v4 = *(unsigned __int8 **)off_118984;
      *(_BYTE *)(v2 + 116) = v3;
      v5 = *v4;
      if ( v3 > v5 )
      {
        return rf_channel_set_n6838(*(unsigned __int8 *)(v2 + 102), dword_118988, v2);
      }
      else if ( v3 == v5 )
      {
        return rf_msg_handler_n0ec(v2);
      }
    }
  }
  return result;
}

