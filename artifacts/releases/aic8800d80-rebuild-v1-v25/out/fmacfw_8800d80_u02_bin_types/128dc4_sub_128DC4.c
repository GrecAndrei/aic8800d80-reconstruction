// sub_128DC4 @ 0x128dc4, size 186 bytes
void  sub_128DC4(int a1)
{
  uint8_t *v1; // r5
  uint64_t v3; // r2
  BOOL v4; // r0
  uint32_t *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = off_128E84;
  LODWORD(v3) = *((uint32_t *)off_128E88 + 126);
  HIDWORD(v3) = *((uint32_t *)off_128E84 + 1) & 0x20;
  if ( **(uint8_t **)off_128E80 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = sub_1112F4() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(uint8_t *)(a1 + 149) )
  {
    if ( !**(uint8_t **)off_128E8C || !*(uint8_t *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(uint32_t *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = off_128E98;
    v6 = *(uint32_t *)off_128E94;
    *((uint32_t *)v1 + 5) = a1;
    v7 = *(unsigned __int16 *)(v6 + 54);
    v8 = dword_128E9C;
    v1[29] = 1;
    sub_124D3C(v8, v7 + v5[4]);
    return;
  }
  if ( !**(uint8_t **)off_128E8C || !*(uint8_t *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(uint32_t *)off_128E90 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(uint32_t *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    sub_128D64();
  else
    v1[29] = 0;
}

