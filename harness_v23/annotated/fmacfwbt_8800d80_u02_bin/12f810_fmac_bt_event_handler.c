// v23 annotated: fmac_bt_event_handler @ 0x12f810
// Original: 12f810_fmac_bt_event_handler.c
// Primary struct: <unclustered>
//
// fmac_bt_event_handler @ 0x12f810, size 78 bytes
// Doc: fmac_bt_event_handler [bt]: BT event dispatcher in FMAC firmware
// fmac_bt_event_handler [bt]: BT event dispatcher in FMAC firmware
int __fastcall fmac_bt_event_handler(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F860 = 1;
  }
  v2 = (int *)off_12F864;
  ++*(_DWORD *)off_12F864;
  result = sub_116484();
  if ( a1 <= 4 )
    --*(_BYTE *)(dword_12F868 + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(_DWORD *)off_12F860;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  --*((_DWORD *)off_12F86C + 126);
  return result;
}

