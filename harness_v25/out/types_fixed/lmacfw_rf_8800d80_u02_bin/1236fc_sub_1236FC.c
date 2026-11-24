// sub_1236FC @ 0x1236fc, size 52 bytes
_BYTE *__fastcall sub_1236FC(_BYTE *result)
{
  _BYTE *v1; // r3
  char v2; // r1
  char v3; // r2

  if ( *result == 2 )
  {
    if ( *(unsigned __int8 *)off_123730 == (unsigned __int8)*(_DWORD *)(result + 0x4) )
    {
      v1 = off_123734;
      v2 = *(_DWORD *)(result + 0xc);
      v3 = *(_DWORD *)(result + 0x10);
      *((_BYTE *)off_123734 + 2) = *(_DWORD *)(result + 0x8);
      *(_DWORD *)(v1 + 0xc) = v2;
      *(_DWORD *)(v1 + 0x10) = v3;
    }
    return (_BYTE *)sub_1264DC(*(_DWORD *)off_123738 + 20000);
  }
  return result;
}

