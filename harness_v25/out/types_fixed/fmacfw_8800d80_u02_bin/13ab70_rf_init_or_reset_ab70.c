// rf_init_or_reset_ab70 @ 0x13ab70, size 54 bytes
// Doc: rf_init_or_reset_ab70 [rf]: RF subsystem initialization or reset sequence
// rf_init_or_reset_ab70 [rf]: RF subsystem initialization or reset sequence
int __fastcall rf_init_or_reset_ab70(int a1, _WORD *a2)
{
  unsigned int v2; // r2
  _WORD *v4; // r1

  v2 = *(unsigned __int16 *)(a1 + 24);
  if ( (unsigned __int16)__rev16(v2) >= 0x600u )
  {
    *(a2 - 4) = -21846;
    a2 -= 4;
    *(_DWORD *)(a2 + 0xc) = v2;
    *(_DWORD *)(a2 + 0x4) = 3;
    *(_DWORD *)(a2 + 0x8) = 0;
  }
  v4 = sub_13A980(a1, a2, 1);
  return fmac_init_handler(a1, (int)v4);
}

