// sub_121534 @ 0x121534, size 198 bytes
uint32_t * sub_121534(int a1)
{
  int v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2
  int *v5; // r1
  uint32_t *v6; // r5
  uint32_t *result; // r0
  int v8; // r5
  int v9; // r6
  uint32_t *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(uint32_t *)off_1215FC) )
    return (uint32_t *)sub_12004C(
                       dword_121604 + 1320 * ((a1 - (HIBYTE(*(uint32_t *)off_1215FC) + 1)) / 2),
                       (((uint8_t)a1 - 1 - HIBYTE(*(uint32_t *)off_1215FC)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_121620 + 696 * (unsigned __int8)(a1 - 16);
    v9 = *(unsigned __int8 *)(v8 + 34);
    result = (uint32_t *)sub_11F278(v8);
    if ( *(uint8_t *)(dword_121604 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = off_121608;
    *(uint32_t *)off_121600 = *(unsigned __int16 *)(v8 + 38) | (*(unsigned __int16 *)(v8 + 40) << 16);
    *v10 = *(unsigned __int16 *)(v8 + 42);
  }
  else
  {
    v2 = dword_121604;
    v3 = off_121608;
    *(uint32_t *)off_121600 = -1;
    *v3 = -1;
    sub_12004C(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = off_12160C;
  v5 = (int *)off_121610;
  v6 = off_121618;
  result = off_12161C;
  *(uint32_t *)off_121614 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}

