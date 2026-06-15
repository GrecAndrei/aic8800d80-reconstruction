// v23 annotated: sub_110C7C @ 0x110c7c
// Original: 110c7c_sub_110C7C.c
// Primary struct: group_20 (cluster 20)
//
// sub_110C7C @ 0x110c7c, size 124 bytes
// Doc: rf_bus_mark_n_4da [rf]: Marks RF bus region by ORing 0x800000 flag into control register
// rf_bus_mark_n_4da [rf]: Marks RF bus region by ORing 0x800000 flag into control register
int __fastcall sub_110C7C(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)rf_bus_mark_n_494;
  v2 = a1 & 0x3FFFFF;
  v3 = *(_DWORD *)rf_bus_mark_n_494 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(_DWORD *)rf_bus_mark_n_494 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(_DWORD *)rf_bus_mark_n_494 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return sub_10DA6C(rf_bus_mark_n_490, *(_DWORD *)rf_bus_mark_n_494 & 0x3FFFFF);
}

