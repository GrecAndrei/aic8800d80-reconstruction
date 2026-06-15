// v23 annotated: sub_11608C @ 0x11608c
// Original: 11608c_sub_11608C.c
// Primary struct: <unclustered>
//
// sub_11608C @ 0x11608c, size 18 bytes
// Doc: sub_121608C [mac]: Fetch context pointer at offset 0x48 from object
// sub_121608C [mac]: Fetch context pointer at offset 0x48 from object
_DWORD *__fastcall sub_11608C(int a1)
{
  _DWORD *result; // r0

  result = *(_DWORD **)(a1 + 72);
  if ( result )
  {
    result = (_DWORD *)log_free_dispatch_2(result);
    *(_DWORD *)(a1 + 72) = 0;
  }
  return result;
}

