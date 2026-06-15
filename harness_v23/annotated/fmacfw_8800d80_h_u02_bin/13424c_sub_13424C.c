// v23 annotated: sub_13424C @ 0x13424c
// Original: 13424c_sub_13424C.c
// Primary struct: <unclustered>
//
// sub_13424C @ 0x13424c, size 80 bytes
int sub_13424C()
{
  int *v0; // r4
  _BYTE *v1; // r2
  int v2; // r1
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_13429C = 1;
  }
  v0 = (int *)off_1342A0;
  v1 = off_1342A4;
  v2 = *((unsigned __int8 *)off_1342A4 + 15);
  v3 = *(_DWORD *)off_1342A0 + 1;
  *(_DWORD *)off_1342A0 = v3;
  if ( v2 )
  {
    sub_134228();
    v3 = *v0;
  }
  else if ( v1[14] == 1 )
  {
    sub_1345A8();
    v3 = *v0;
  }
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_13429C;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  sub_12E948(dword_1342A8);
  return 0;
}

