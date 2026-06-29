// fwstruct annotate: 12d2d0_rf_bus_mark_n100_d2d0.c
// rf_bus_mark_n100_d2d0 @ 0x12d2d0, size 22 bytes
// Doc: rf_bus_mark_n100_d2d0 [rf]: Marks a tagged slot on the RF shared bus structure
// rf_bus_mark_n100_d2d0 [rf]: Marks a tagged slot on the RF shared bus structure
_DWORD *__fastcall rf_bus_mark_n100_d2d0(int a1)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r2

  v1 = *(_DWORD **)a1;
  if ( *(_DWORD *)a1 )
  {
    v2 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)a1 = *v1;
    if ( v2 == v1 )
      *(_DWORD *)(a1 + 4) = 0;
  }
  return v1;
}

