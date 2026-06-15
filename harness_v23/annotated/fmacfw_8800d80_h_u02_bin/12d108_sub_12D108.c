// v23 annotated: sub_12D108 @ 0x12d108
// Original: 12d108_sub_12D108.c
// Primary struct: <unclustered>
//
// sub_12D108 @ 0x12d108, size 60 bytes
int __fastcall sub_12D108(int result, _DWORD *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_12D144 < 0 && !a2 )
    result = sub_12F32C(dword_12D14C, dword_12D148, 72);
  if ( *(_DWORD *)v2 )
    **(_DWORD **)(v2 + 4) = a2;
  else
    *(_DWORD *)v2 = a2;
  *(_DWORD *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

