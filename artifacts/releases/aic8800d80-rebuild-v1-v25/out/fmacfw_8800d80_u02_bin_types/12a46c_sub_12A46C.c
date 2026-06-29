// sub_12A46C @ 0x12a46c, size 74 bytes
int sub_12A46C()
{
  int result; // r0
  int *v1; // r3

  result = *(unsigned __int8 *)off_12A4B8;
  if ( *(uint8_t *)off_12A4B8 )
  {
    result = *((unsigned __int8 *)off_12A4BC + 17);
    if ( *((uint8_t *)off_12A4BC + 17) )
    {
      return 0;
    }
    else if ( *((unsigned __int8 *)off_12A4BC + 18) <= 1u )
    {
      v1 = *((int **)off_12A4BC + 2);
      if ( v1 )
      {
        while ( *((uint8_t *)v1 + 106) != 2 || !*((uint8_t *)v1 + 1224) )
        {
          v1 = (int *)*v1;
          if ( !v1 )
            return result;
        }
        return *(unsigned __int8 *)(dword_12A4C0 + 140 * *((unsigned __int8 *)v1 + 1225) + 133) == 0;
      }
    }
  }
  return result;
}

