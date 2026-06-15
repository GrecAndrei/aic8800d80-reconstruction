// v23 annotated: sub_11C990 @ 0x11c990
// Original: 11c990_sub_11C990.c
// Primary struct: group_23 (cluster 23)
//
// sub_11C990 @ 0x11c990, size 46 bytes
// Doc: sub_121C990 [scan]: Indexed table lookup using sub-id * 0x528 stride, cap compare 0x3ff
// sub_121C990 [scan]: Indexed table lookup using sub-id * 0x528 stride, cap compare 0x3ff
unsigned int *__fastcall sub_11C990(unsigned int *result)
{
  int v1; // r2

  v1 = *(unsigned __int16 *)(dword_11C9C0 + 1320 * *((unsigned __int8 *)result + 28) + 1222);
  if ( v1 != 1023 && *((_BYTE *)off_11C9C4 + 361) != 2 )
    return sub_11B510((unsigned int *)(result[17] + 4), *(_DWORD *)(result[17] + 40), v1);
  return result;
}

