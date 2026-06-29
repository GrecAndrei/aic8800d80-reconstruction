// fwstruct annotate: 11a710_sub_11A710.c
// sub_11A710 @ 0x11a710, size 22 bytes
// Doc: sub_121A710 [bt]: Decrement refcount and fetch linked buffer pointer
// sub_121A710 [bt]: Decrement refcount and fetch linked buffer pointer
int __fastcall sub_11A710(int result)
{
  char v1; // r3

  v1 = *(_BYTE *)(result + 14) - 1;
  *(_BYTE *)(result + 14) = v1;
  if ( !v1 )
    return list_push_tail(*(_DWORD *)(result + 340));
  return result;
}

