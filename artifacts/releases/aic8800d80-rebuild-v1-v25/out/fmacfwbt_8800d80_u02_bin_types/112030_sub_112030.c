// sub_112030 @ 0x112030, size 66 bytes
int sub_112030()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = off_112074;
  v1 = *((unsigned __int16 *)off_112074 + 7);
  *(uint16_t *)off_112078 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_112080 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(uint8_t *)off_11207C = 4;
      *v0 = 7;
      if ( !sub_1138E8() )
        sub_113FC4(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)off_11207C = 3;
    return 1;
  }
}

