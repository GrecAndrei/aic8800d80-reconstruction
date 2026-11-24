// irq_vector_init @ 0x102bfc, size 132 bytes
// Doc: irq_vector_init [util]: Initialize NVIC interrupt vector table and enable interrupts
// irq_vector_init [util]: Initialize NVIC interrupt vector table and enable interrupts
int irq_vector_init()
{
  _DWORD *v0; // r2
  _BYTE *v1; // r3
  int v2; // r1
  int v3; // r0
  int v4; // r4
  int v5; // r0
  int v6; // r1
  unsigned __int8 *v7; // r2
  int v8; // r2
  _DWORD *v9; // r2
  _DWORD *v10; // r3

  v0 = off_102C80;
  v1 = off_102C84;
  *(_DWORD *)(*((_DWORD *)off_102C80 + 2) + 80) = dword_102C88;
  *(_DWORD *)v1 = 16;
  v2 = dword_102C8C;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 84) = dword_102C8C;
  *(_DWORD *)v1 = 32;
  v3 = dword_102C90;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 92) = v2;
  *(_DWORD *)v1 = 128;
  v4 = dword_102C94;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 72) = v3;
  *(_DWORD *)v1 = 4;
  v5 = dword_102C98;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 88) = v4;
  *(_DWORD *)v1 = 64;
  v6 = *(_DWORD *)(v0 + 0x8);
  v7 = (unsigned __int8 *)off_102C9C;
  *(_DWORD *)(v6 + 76) = v5;
  v8 = *(_DWORD *)(v7 + 0x674);
  *(_DWORD *)(v1 + 0xc0c) = -8;
  *(_DWORD *)v1 = 8;
  if ( v8 )
    *(_DWORD *)v1 = 512;
  v9 = off_102C80;
  v10 = off_102C84;
  *(_DWORD *)(*((_DWORD *)off_102C80 + 2) + 208) = off_102CA0;
  *(_DWORD *)(v10 + 0x4) = 16;
  *(_DWORD *)(*(_DWORD *)(v9 + 0x8) + 212) = off_102CA4;
  *(_DWORD *)(v10 + 0x4) = 32;
  *v10 = 0x800000;
  *(_DWORD *)(v10 + 0x4) = 64;
  __enable_irq();
  return 32;
}

