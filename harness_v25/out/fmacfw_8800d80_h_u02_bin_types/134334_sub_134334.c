// sub_134334 @ 0x134334, size 72 bytes
int  sub_134334(uint32_t *a1, uint32_t *a2)
{
  int v2; // r6
  int result; // r0

  v2 = *((uint32_t *)off_13437C + 4);
  *a1 = 0;
  *a2 = 0;
  if ( (*(uint8_t *)(v2 + 34) & 1) != 0 )
  {
    result = sub_138134(v2);
    if ( result )
    {
      *a1 = result + 2;
LABEL_4:
      *a2 = *(uint32_t *)(result + 44);
      return result;
    }
  }
  else
  {
    *a1 = v2 + 34;
    result = sub_1380D8();
    if ( result )
      goto LABEL_4;
  }
  if ( *(unsigned __int16 *)(v2 + 40) != 0xFFFF )
    *a2 = v2 + 40;
  return result;
}

