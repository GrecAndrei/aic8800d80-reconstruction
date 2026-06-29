// fwstruct annotate: 1236fc_sub_1236FC.c
// sub_1236FC @ 0x1236fc, size 52 bytes
_BYTE *__fastcall sub_1236FC(_BYTE *result)
{
  _BYTE *v1; // r3
  char v2; // r1
  char v3; // r2

  if ( *result == 2 )
  {
    if ( *(unsigned __int8 *)off_123730 == (unsigned __int8)result[1] )
    {
      v1 = off_123734;
      v2 = result[3];
      v3 = result[4];
      *((_BYTE *)off_123734 + 2) = result[2];
      v1[3] = v2;
      v1[4] = v3;
    }
    return (_BYTE *)sub_1264DC(*(_DWORD *)off_123738 + 20000);
  }
  return result;
}

