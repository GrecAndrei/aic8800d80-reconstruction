// fwstruct annotate: 12a32c_sub_12A32C.c
// sub_12A32C @ 0x12a32c, size 74 bytes
int sub_12A32C()
{
  int result; // r0
  int *v1; // r3

  result = *(unsigned __int8 *)off_12A378;
  if ( *(_BYTE *)off_12A378 )
  {
    result = *((unsigned __int8 *)off_12A37C + 17);
    if ( *((_BYTE *)off_12A37C + 17) )
    {
      return 0;
    }
    else if ( *((unsigned __int8 *)off_12A37C + 18) <= 1u )
    {
      v1 = *((int **)off_12A37C + 2);
      if ( v1 )
      {
        while ( *((_BYTE *)v1 + 106) != 2 || !*((_BYTE *)v1 + 1224) )
        {
          v1 = (int *)*v1;
          if ( !v1 )
            return result;
        }
        return *(unsigned __int8 *)(dword_12A380 + 140 * *((unsigned __int8 *)v1 + 1225) + 133) == 0;
      }
    }
  }
  return result;
}

