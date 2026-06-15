// v23 annotated: sub_10FEF8 @ 0x10fef8
// Original: 10fef8_sub_10FEF8.c
// Primary struct: <unclustered>
//
// sub_10FEF8 @ 0x10fef8, size 218 bytes
int __fastcall sub_10FEF8(_DWORD *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = log_ptr_in_range((unsigned int)a1);
  if ( !result )
  {
    result = sub_10DA6C(dword_10FFDC, a1);
    v5 = **(unsigned __int8 **)off_10FFD4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return sub_113300(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !log_ptr_in_range((unsigned int)a1) )
          sub_10DA6C(dword_10FFEC, a1);
        return sub_10FBD0(dword_10FFE0, a1);
      }
      if ( **(__int16 **)off_10FFD8 < 0 )
        return rf_cmd_send_n264(dword_10FFE8, dword_10FFE4, 204);
      return result;
    }
    return sub_1103B0(a1);
  }
  v3 = *((unsigned __int8 *)a1 - 4);
  v4 = **(unsigned __int8 **)off_10FFD4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return sub_110280(a1);
    if ( v3 == 2 )
      return sub_110320(a1);
    if ( *((_BYTE *)a1 - 4) )
      return result;
    return sub_1103B0(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(__int16 **)off_10FFD8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return log_free_pool_e(a1);
      }
      if ( v3 == 3 )
        return log_free_pool_e(a1);
      return rf_cmd_send_n264(dword_10FFE8, dword_10FFE4, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return rf_mem_write_n3f8(a1);
  if ( !*((_BYTE *)a1 - 4) )
    return sub_113300(a1);
  return result;
}

