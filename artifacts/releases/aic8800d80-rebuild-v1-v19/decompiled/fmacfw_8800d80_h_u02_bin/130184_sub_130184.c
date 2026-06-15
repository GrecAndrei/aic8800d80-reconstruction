// sub_130184 @ 0x130184, size 44 bytes
unsigned int sub_130184()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)off_1301B0;
  result = *((unsigned __int8 *)off_1301B0 + 6);
  v2 = *((unsigned __int8 *)off_1301B0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((_BYTE *)off_1301B0 + 6) = v3;
    sub_10EDF8(v3);
    return sub_12E948(dword_1301B4, v0[5], v0[6]);
  }
  return result;
}

