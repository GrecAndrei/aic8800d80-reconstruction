// sub_12A04C @ 0x12a04c, size 60 bytes
int  sub_12A04C(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = dword_12A088;
  v3 = dword_12A088 + 140 * result;
  if ( *(unsigned __int8 *)(v3 + 113) != 255 )
  {
    if ( *(uint8_t *)(v3 + 112) != 1 )
    {
      if ( !a2 )
        return result;
      goto LABEL_4;
    }
    --*(uint8_t *)off_12A08C;
    if ( a2 )
    {
LABEL_4:
      result = v2 + 140 * result;
      *(uint8_t *)(result + 113) = -1;
    }
  }
  return result;
}

