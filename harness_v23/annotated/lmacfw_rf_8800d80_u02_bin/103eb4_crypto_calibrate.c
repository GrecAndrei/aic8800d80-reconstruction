// v23 annotated: crypto_calibrate @ 0x103eb4
// Original: 103eb4_crypto_calibrate.c
// Primary struct: <unclustered>
//
// crypto_calibrate @ 0x103eb4, size 212 bytes
// Doc: rf_init_hw_regs [patch]: Initialize RF hardware MMIO registers at boot
// rf_init_hw_regs [patch]: Initialize RF hardware MMIO registers at boot
int crypto_calibrate()
{
  int *v0; // r1
  _DWORD *v1; // r3
  int v2; // r0
  int v3; // r5
  _DWORD *v4; // r6
  int *v5; // r4
  void *v6; // r3
  int v7; // r1
  int v8; // r3
  int result; // r0
  _DWORD *v10; // r3
  _DWORD *v11; // r1

  v0 = (int *)off_103F88;
  v1 = off_103F90;
  v2 = dword_103F94;
  v3 = *(_DWORD *)off_103F8C;
  *(_DWORD *)off_103F8C = dword_103F98;
  *v0 = v2;
  v4 = off_103F9C;
  v5 = (int *)off_103FA0;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  delay_us(10);
  *v4 = dword_103FA4;
  delay_us(125);
  *v4 = dword_103FA8;
  while ( *v5 < 0 )
    delay_us(1);
  sub_11F74C(1, dword_103FAC, *(_DWORD *)off_103FA0, off_103FA0);
  v6 = off_103F9C;
  v7 = dword_103FB0;
  *(_DWORD *)off_103F9C = 0;
  sub_11F74C(1, v7, 0, v6);
  *(_DWORD *)off_103F8C = v3;
  sub_103DA8();
  result = sub_11F74C(1, dword_103FB4, 0x4000, v8);
  v10 = off_103F90;
  v11 = off_103FB8;
  *(_DWORD *)off_103F90 &= 0xF3FFFFFF;
  *v11 |= 0xF0u;
  *v10 &= ~0x10000000u;
  *v10 &= 0x3FFFFFFFu;
  return result;
}

