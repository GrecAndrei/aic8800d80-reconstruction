// fwstruct annotate: 10d3ac_irq_event_set.c
// irq_event_set @ 0x10d3ac, size 66 bytes
// Doc: irq_event_set [ipc]: Set/raise IRQ event flag
// irq_event_set [ipc]: Set/raise IRQ event flag
int __fastcall irq_event_set(int result)
{
  if ( result == 1 )
  {
    *(_DWORD *)off_10D3F0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(_DWORD *)off_10D3F0 = 0x80000;
  }
  else if ( **(__int16 **)off_10D3F8 < 0 )
  {
    result = sub_12F46C(dword_10D400, dword_10D3FC, 2118);
  }
  *((_DWORD *)off_10D3F4 + 1) |= 0x400000u;
  return result;
}

