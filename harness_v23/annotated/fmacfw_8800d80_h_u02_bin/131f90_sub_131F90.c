// v23 annotated: sub_131F90 @ 0x131f90
// Original: 131f90_sub_131F90.c
// Primary struct: <unclustered>
//
// sub_131F90 @ 0x131f90, size 96 bytes
int __fastcall sub_131F90(int a1, char *a2, __int16 a3, __int16 a4)
{
  _WORD *v7; // r4
  char v8; // r3
  int v9; // r1
  _BYTE *v10; // r0
  int v11; // r3

  if ( sub_12CD48(5u) == 1 )
    return 2;
  v7 = off_131FF0;
  v8 = *a2;
  v9 = *((_DWORD *)off_131FF0 + 1);
  if ( *a2 )
    v8 = 1;
  *((_BYTE *)off_131FF0 + 375) = v8;
  if ( !v9 )
  {
    v10 = (_BYTE *)sub_12C7EC(49, 0, 5, 1u);
    v11 = *((unsigned __int8 *)v7 + 375);
    v7[4] = 255;
    if ( v11 )
      LOBYTE(v11) = *((_BYTE *)v7 + 376);
    *v10 = v11;
    sub_12C84C((int)v10);
    sub_12CBF4(5u, 1);
  }
  sub_12C8D0(5140, a4, a3);
  return 0;
}

