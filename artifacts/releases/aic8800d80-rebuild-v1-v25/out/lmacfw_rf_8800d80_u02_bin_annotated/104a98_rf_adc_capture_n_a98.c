// fwstruct annotate: 104a98_rf_adc_capture_n_a98.c
// rf_adc_capture_n_a98 @ 0x104a98, size 172 bytes
// Doc: rf_adc_capture_n_a98 [rf]: Capture RF ADC samples for crypto/calibration
// rf_adc_capture_n_a98 [rf]: Capture RF ADC samples for crypto/calibration
int __fastcall rf_adc_capture_n_a98(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r4
  int *v5; // r9
  int v6; // r5
  _DWORD *v7; // r11
  _DWORD *v12; // r2
  int v13; // r1
  unsigned int v14; // r5
  unsigned int v15; // r0
  int result; // r0
  int v17; // r1

  v4 = (unsigned int *)off_104B44;
  v5 = (int *)off_104B58;
  v6 = dword_104B48;
  v7 = off_104B5C;
  *(_DWORD *)off_104B44 &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  delay_us(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  delay_us(2);
  *v7 = 8;
  delay_us(300);
  v12 = off_104B4C;
  v13 = dword_104B50;
  *v4 |= 0x40000000u;
  v14 = HIWORD(*v12) & 0x3FFF;
  v15 = *v4 & 0xBFFFFFFF;
  *(_WORD *)(a2 + 2 * (a3 + 16 * a4)) = v14;
  *v4 = v15;
  result = sub_11F74C(1, v13, a1, a4);
  if ( v14 > 0x3E80 )
    return msg_parse(dword_104B54, v17);
  return result;
}

