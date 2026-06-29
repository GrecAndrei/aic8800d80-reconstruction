// sub_129F0C @ 0x129f0c, size 60 bytes
int  sub_129F0C(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = dword_129F48;
  v3 = dword_129F48 + 140 * result;
  if ( *(unsigned __int8 *)(v3 + 113) != 255 )
  {
    if ( *(uint8_t *)(v3 + 112) != 1 )
    {
      if ( !a2 )
        return result;
      goto LABEL_4;
    }
    --*(uint8_t *)off_129F4C;
    if ( a2 )
    {
LABEL_4:
      result = v2 + 140 * result;
      *(uint8_t *)(result + 113) = -1;
    }
  }
  return result;
}

