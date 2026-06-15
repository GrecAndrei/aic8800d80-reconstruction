// log_free_dispatch_2 @ 0x110008, size 218 bytes
// Doc: log_free_pool_dispatch2 [util]: Dispatch log free pool entry and check log level
// log_free_pool_dispatch2 [util]: Dispatch log free pool entry and check log level
int __fastcall log_free_dispatch_2(_DWORD *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = sub_10FF34((unsigned int)a1);
  if ( !result )
  {
    result = sub_10DC24(log_free_pool_dispatch2_n40c, a1);
    v5 = **(unsigned __int8 **)log_free_pool_dispatch2_n404;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return log_free_pool_d_3a48(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !sub_10FF34((unsigned int)a1) )
          sub_10DC24(dword_1100FC, a1);
        return sub_10FCE0(dword_1100F0, a1);
      }
      if ( **(__int16 **)log_free_dispatch_ne0 < 0 )
        return sub_12F46C(log_free_dispatch_nf0, log_free_dispatch_nec, 204);
      return result;
    }
    return log_free_pool_c(a1);
  }
  v3 = *((unsigned __int8 *)a1 - 4);
  v4 = **(unsigned __int8 **)log_free_pool_dispatch2_n404;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return log_free_pool_a(a1);
    if ( v3 == 2 )
      return log_free_pool_b(a1);
    if ( *((_BYTE *)a1 - 4) )
      return result;
    return log_free_pool_c(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(__int16 **)log_free_dispatch_ne0 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return log_free_pool_e_428c(a1);
      }
      if ( v3 == 3 )
        return log_free_pool_e_428c(a1);
      return sub_12F46C(log_free_dispatch_nf0, log_free_dispatch_nec, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return log_free_pool_f_904(a1);
  if ( !*((_BYTE *)a1 - 4) )
    return log_free_pool_d_3a48(a1);
  return result;
}

