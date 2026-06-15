// v23 annotated: sub_10C984 @ 0x10c984
// Original: 10c984_sub_10C984.c
// Primary struct: <unclustered>
//
// sub_10C984 @ 0x10c984, size 52 bytes
int sub_10C984()
{
  int v0; // r4
  int result; // r0
  int *v2; // r2
  _BYTE *v3; // r3
  _DWORD *v4; // r2

  v0 = *(_DWORD *)off_10C9B8 & 0x1F00;
  if ( v0 )
  {
    result = irq_nesting_or_d104(2048);
    v2 = (int *)off_10C9BC;
    v3 = off_10C9C4;
    *(_DWORD *)off_10C9C0 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = off_10C9C8;
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}

