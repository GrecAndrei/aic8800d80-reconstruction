// v23 annotated: sub_113904 @ 0x113904
// Original: 113904_sub_113904.c
// Primary struct: <unclustered>
//
// sub_113904 @ 0x113904, size 156 bytes
void sub_113904()
{
  int *v0; // r4
  int v1; // r0
  _BYTE *v2; // r1
  int v3; // r0
  unsigned __int16 v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1139A0 = 1;
  }
  v0 = (int *)off_1139A4;
  v1 = dword_1139A8;
  ++*(_DWORD *)off_1139A4;
  sub_12D248(v1);
  v2 = off_1139B0;
  v3 = *(unsigned __int8 *)off_1139B0;
  v4 = *(_WORD *)off_1139AC + 1;
  *(_WORD *)off_1139AC = v4;
  if ( v3 && *(unsigned __int8 *)off_1139B4 <= (unsigned int)v4 )
  {
    v7 = *(unsigned __int8 *)off_1139B8;
    *v2 = 0;
    if ( v7 )
      *((_DWORD *)off_1139BC + 512) &= ~0x2000u;
    else
      *((_DWORD *)off_1139BC + 713) &= ~1u;
    sub_1120FC(1);
    sub_12C73C(1069, 1);
    sub_12ECD0(512, dword_1139C0);
    if ( !*(_BYTE *)off_1139C4 )
      sub_1136B8();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(_DWORD *)off_1139A0;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

