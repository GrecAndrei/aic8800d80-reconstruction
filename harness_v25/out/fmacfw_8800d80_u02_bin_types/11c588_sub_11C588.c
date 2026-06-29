// sub_11C588 @ 0x11c588, size 70 bytes
// Doc: sub_121C588 [unknown]: Unknown fmac helper function
// sub_121C588 [unknown]: Unknown fmac helper function
unsigned int * sub_11C588(unsigned int *result)
{
  int v1; // r2
  int v2; // r5
  unsigned int *v3; // r4
  uint64_t v4; // r6
  unsigned int *v5; // r0

  v1 = *(unsigned __int16 *)(dword_11C5D0 + 1320 * *((unsigned __int8 *)result + 28) + 1222);
  if ( v1 != 1023 && *((uint8_t *)off_11C5D4 + 361) != 2 )
  {
    v4 = *((QWORD *)result + 9);
    v2 = dword_11C5D0 + 1320 * *((unsigned __int8 *)result + 28);
    v3 = (unsigned int *)(v4 + 64);
    LODWORD(v4) = v4 + 80;
    while ( 1 )
    {
      v5 = v3++;
      result = queue_process(v5, *(uint32_t *)(HIDWORD(v4) + 36), v1);
      if ( v3 == (unsigned int *)v4 )
        break;
      v1 = *(unsigned __int16 *)(v2 + 1222);
    }
  }
  return result;
}

