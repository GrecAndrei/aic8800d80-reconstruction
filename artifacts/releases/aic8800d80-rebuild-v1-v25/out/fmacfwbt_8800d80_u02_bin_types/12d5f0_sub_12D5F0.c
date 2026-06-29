// sub_12D5F0 @ 0x12d5f0, size 60 bytes
uint32_t * sub_12D5F0(uint32_t *result, uint32_t **a2, uint32_t *a3)
{
  uint32_t *v3; // r3
  uint32_t *v4; // r4
  uint32_t **v5; // r3

  v3 = (uint32_t *)*result;
  if ( !a2 )
    return (uint32_t *)bt_state_check_or_init((int)result, a3);
  if ( v3 )
  {
    v4 = result;
    if ( v3 == a2 )
    {
LABEL_8:
      v5 = (uint32_t **)result[1];
      result = *a2;
      *a3 = *a2;
      *a2 = a3;
      if ( v5 == a2 )
        v4[1] = a3;
    }
    else
    {
      while ( 1 )
      {
        v3 = (uint32_t *)*v3;
        if ( !v3 )
          break;
        if ( a2 == v3 )
          goto LABEL_8;
      }
    }
  }
  return result;
}

