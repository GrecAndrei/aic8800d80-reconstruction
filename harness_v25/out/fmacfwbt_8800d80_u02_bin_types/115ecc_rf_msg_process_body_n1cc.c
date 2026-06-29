// rf_msg_process_body_n1cc @ 0x115ecc, size 300 bytes
// Doc: rf_msg_process_body_n1cc [rf]: Processes body of RF message, updating sequence/length fields
// rf_msg_process_body_n1cc [rf]: Processes body of RF message, updating sequence/length fields
uint8_t *rf_msg_process_body_n1cc()
{
  uint32_t *v0; // r4
  uint8_t *v1; // r5
  int v2; // r1
  uint32_t *v3; // r2
  uint32_t *v4; // r2
  unsigned __int8 *v5; // r1
  int v6; // r1
  uint32_t *v7; // r2
  uint32_t *v8; // r1
  unsigned __int8 **v9; // r1
  int v10; // r3
  uint8_t *result; // r0
  int v12; // r2
  uint32_t *v13; // r3
  uint32_t *v14; // r3
  uint32_t *v15; // r3

  v0 = off_115FF8;
  v1 = off_115FFC;
  v2 = dword_116000;
  *(uint8_t *)off_115FFC = *(uint8_t *)off_115FF8 & 0xF;
  feature_guard_sdio(2, v2);
  if ( *v0 << 28 )
  {
    v3 = off_116008;
    *(uint32_t *)off_116004 &= ~0x80000000;
    *v0 = 0;
    while ( (*v3 & 4) == 0 )
      ;
    v4 = off_116004;
    v5 = (unsigned __int8 *)off_116010;
    *(uint32_t *)off_11600C = 4;
    v6 = v5[189];
    *v4 |= 0x80000000;
    if ( v6 )
      *(uint32_t *)((char *)v4 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(uint32_t *)off_116020 &= ~0x8000000u;
  }
  v7 = off_116014;
  v8 = off_115FF8;
  *(uint32_t *)off_116014 |= 0x111u;
  v1[1] = 1;
  *v8 = 32;
  v9 = (unsigned __int8 **)off_116018;
  *v7 &= 0xFFFFFEEE;
  v10 = **v9;
  if ( v10 == 3 )
  {
    v14 = off_116024;
    *(uint32_t *)off_116024 |= 1u;
    if ( (*v14 & 4) != 0 )
      *(uint32_t *)off_116028 = 512;
  }
  else if ( v10 == 1 )
  {
    sdio_wait_busy();
    v15 = off_116030;
    *(uint32_t *)off_11602C |= 0x20u;
    v15[20] |= 0x20000u;
    v15[20] |= 0x8000u;
    v15[20] |= 0x10000u;
    v15[20] = v15[20] & 0xFFFFFFC0 | 0x37;
    v15[23] = v15[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_11601C;
  v12 = 0;
  *(uint8_t *)off_11601C = 0;
  while ( 1 )
  {
    v13 = (uint32_t *)(4 * v12++ - 536813312);
    if ( (v13[64] & *v13) != 0 )
      break;
    if ( v12 == 3 )
      return result;
  }
  *result = 1;
  return result;
}

