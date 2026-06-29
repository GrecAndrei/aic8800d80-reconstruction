// sub_12D62C @ 0x12d62c, size 42 bytes
uint32_t * sub_12D62C(uint32_t *result, uint32_t *a2, uint32_t *a3)
{
  uint32_t **v3; // r3

  if ( !a2 )
    return (uint32_t *)list_push_tail((int)result, a3);
  v3 = (uint32_t **)*result;
  if ( (uint32_t *)*result == a2 )
    return (uint32_t *)bt_state_check_or_init((int)result, a3);
  if ( v3 )
  {
    while ( 1 )
    {
      result = *v3;
      if ( *v3 == a2 )
        break;
      v3 = (uint32_t **)*v3;
      if ( !result )
        return result;
    }
    *a3 = a2;
    *v3 = a3;
  }
  return result;
}

