// sub_103FA8 @ 0x103fa8, size 118 bytes
// Doc: sub_1203FA8 [mmio]: Set MMIO control bits at 0x4034224c/0x403422c4
// sub_1203FA8 [mmio]: Set MMIO control bits at 0x4034224c/0x403422c4
int *__fastcall sub_103FA8(int a1)
{
  unsigned int *v1; // r3
  int v2; // r5
  int v3; // r7
  int v4; // r12
  unsigned int *v5; // lr
  int v6; // r6
  int v7; // r0
  int *result; // r0
  int v9; // r4
  int *v10; // r3
  _DWORD *v11; // r2
  int v12; // t1

  v1 = (unsigned int *)off_104024;
  *(_DWORD *)off_104020 |= 0x100u;
  v2 = 0;
  v3 = -a1;
  v4 = a1 + 48;
  *v1 &= 0xFFFCFFFF;
  v5 = v1;
  v6 = 0;
  v7 = 128;
  while ( 1 )
  {
    result = (int *)(v4 + 4 * (v7 + v2));
    v9 = dword_104028 + v3;
    v10 = (int *)(48 - v3);
    do
    {
      v11 = (int *)((char *)v10 + v9);
      v12 = *v10++;
      *v11 = v12;
    }
    while ( v10 != result );
    ++v6;
    if ( v2 == 256 )
      break;
    v2 += 128;
    v3 -= 512;
    *v5 = *v5 & 0xFFFCFFFF | (v6 << 16);
    if ( v6 == 2 )
      v7 = 32;
    else
      v7 = 128;
  }
  *(_DWORD *)off_104020 &= ~0x100u;
  return result;
}

