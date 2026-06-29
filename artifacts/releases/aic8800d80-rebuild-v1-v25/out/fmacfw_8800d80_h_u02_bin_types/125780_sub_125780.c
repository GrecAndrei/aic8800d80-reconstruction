// sub_125780 @ 0x125780, size 258 bytes
void sub_125780()
{
  int v0; // r4
  uint8_t *v1; // r6
  int v2; // r5
  uint32_t *v3; // r2
  int v4; // r7
  uint8_t *v5; // r8
  char v6; // r9
  int v7; // r10
  int v8; // r0
  int v9; // r3

  v0 = *((uint32_t *)off_125888 + 2);
  v1 = off_12588C;
  if ( **(__int16 **)off_125884 < 0 && *((uint32_t *)off_12588C + 1) )
  {
    sub_12F32C(dword_125898, dword_125894, 1074);
    v2 = (unsigned __int8)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((unsigned __int8 *)off_12588C + 9);
    if ( *((uint8_t *)off_12588C + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_125890;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_12589C;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(uint8_t *)(v0 + 106) != 2
        || !*(uint8_t *)(v0 + 226)
        || !*(uint8_t *)(v0 + 108)
        || *(unsigned __int8 *)(v0 + 225) != *(unsigned __int8 *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( sub_1254A8(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        sub_128350(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(uint32_t *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = sub_128350(v0);
        if ( v7 )
        {
          *(uint8_t *)(v0 + 144) = *(uint8_t *)(v0 + 107);
          *(uint8_t *)(v0 + 145) = -1;
          v8 = sub_118B34(v0 + 116, 4);
          v9 = *((uint32_t *)v1 + 1);
          if ( v8 )
            *((uint32_t *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            sub_121AC8();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(uint32_t *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

