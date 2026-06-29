// sub_111ADC @ 0x111adc, size 66 bytes
int sub_111ADC()
{
  uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = off_111B20;
  v1 = *((unsigned __int16 *)off_111B20 + 7);
  *(uint16_t *)off_111B24 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_111B2C + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(uint8_t *)off_111B28 = 4;
      *v0 = 7;
      if ( !sub_113344() )
        sub_113694(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(uint8_t *)off_111B28 = 3;
    return 1;
  }
}

