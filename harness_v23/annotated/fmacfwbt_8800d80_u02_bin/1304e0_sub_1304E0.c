// v23 annotated: sub_1304E0 @ 0x1304e0
// Original: 1304e0_sub_1304E0.c
// Primary struct: <unclustered>
//
// sub_1304E0 @ 0x1304e0, size 44 bytes
unsigned int sub_1304E0()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)off_13050C;
  result = *((unsigned __int8 *)off_13050C + 6);
  v2 = *((unsigned __int8 *)off_13050C + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((_BYTE *)off_13050C + 6) = v3;
    sub_10ED90(v3);
    return sub_12ECB0(dword_130510, v0[5], v0[6]);
  }
  return result;
}

