// sub_11E724 @ 0x11e724, size 60 bytes
int __fastcall sub_11E724(int result, _DWORD *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_11E760 < 0 && !a2 )
    result = sub_1219C4(dword_11E768, dword_11E764, 72);
  if ( *(_DWORD *)v2 )
    **(_DWORD **)(v2 + 4) = a2;
  else
    *(_DWORD *)v2 = a2;
  *(_DWORD *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

