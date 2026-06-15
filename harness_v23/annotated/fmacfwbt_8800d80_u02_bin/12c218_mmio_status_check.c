// v23 annotated: mmio_status_check @ 0x12c218
// Original: 12c218_mmio_status_check.c
// Primary struct: <unclustered>
//
// mmio_status_check @ 0x12c218, size 402 bytes
// Doc: mmio_status_check [mmio]: Read MMIO status registers (0x4032806c/74) and mask with 0x40001
// mmio_status_check [mmio]: Read MMIO status registers (0x4032806c/74) and mask with 0x40001
int __fastcall mmio_status_check(int result, int a2, int a3, int a4)
{
  int v4; // r1
  int v5; // r4
  int v6; // r3
  int v7; // r5

  v4 = *(_DWORD *)off_12C3AC;
  v5 = *(_DWORD *)off_12C3B0 & *(_DWORD *)off_12C3AC;
  v6 = dword_12C3B4 & v5;
  *((_DWORD *)off_12C3AC + 1) = v5;
  if ( v6 )
    result = irq_nesting_or(0x1000000);
  if ( (dword_12C3B8 & v5) != 0 )
    result = irq_nesting_or(0x800000);
  if ( (v5 & 4) != 0 )
    result = sub_12B764();
  if ( (v5 & 8) != 0 )
    result = sub_12C0B4(result, v4);
  if ( (v5 & 0x10000000) != 0 )
  {
    v7 = *(_DWORD *)off_12C3C8;
    *((_BYTE *)off_12C3CC + 30) |= *(_BYTE *)off_12C3C8 & 0x3F;
    result = irq_nesting_or(0x40000);
    *(_DWORD *)off_12C3D0 = v7;
  }
  if ( **(__int16 **)off_12C3BC < 0 )
  {
    if ( (v5 & 0x400000) != 0 )
    {
      return sub_12F630(dword_12C3D4, dword_12C3C0, 847, a4);
    }
    else if ( (v5 & 0x200000) != 0 )
    {
      return sub_12F630(dword_12C3D8, dword_12C3C0, 848, a4);
    }
    else if ( (v5 & 0x40) != 0 )
    {
      return sub_12F630(dword_12C3DC, dword_12C3C0, 849, a4);
    }
    else if ( (v5 & 0x100) != 0 )
    {
      return sub_12F630(dword_12C3E0, dword_12C3C0, 850, a4);
    }
    else if ( (v5 & 0x1000) != 0 )
    {
      return sub_12F630(dword_12C3E4, dword_12C3C0, 851, a4);
    }
    else if ( (v5 & 0x2000) != 0 )
    {
      return sub_12F630(dword_12C3E8, dword_12C3C0, 852, a4);
    }
    else if ( (v5 & 0x4000) != 0 )
    {
      return sub_12F630(dword_12C3EC, dword_12C3C0, 853, a4);
    }
    else if ( (v5 & 0x8000) != 0 )
    {
      return sub_12F630(dword_12C3F0, dword_12C3C0, 854, a4);
    }
    else if ( (v5 & 0x10000) != 0 )
    {
      return sub_12F630(dword_12C3F4, dword_12C3C0, 855, a4);
    }
    else if ( (v5 & 0x20000) != 0 )
    {
      return sub_12F630(dword_12C3F8, dword_12C3C0, 856, a4);
    }
    else
    {
      result = v5 << 7;
      if ( (v5 & 0x1000000) != 0 )
      {
        return sub_12F630(dword_12C3FC, dword_12C3C0, 857, a4);
      }
      else if ( (v5 & 0x2000000) != 0 )
      {
        return sub_12F630(dword_12C400, dword_12C3C0, 858, a4);
      }
      else if ( (v5 & 0x100000) != 0 )
      {
        return sub_12F630(dword_12C404, dword_12C3C0, 859, a4);
      }
      else if ( (v5 & 0x8000000) != 0 )
      {
        return sub_12F630(dword_12C3C4, dword_12C3C0, 860, a4);
      }
    }
  }
  return result;
}

