// fwstruct annotate: 1189f8_fmac_buffer_init_n_setup.c
// fmac_buffer_init_n_setup @ 0x1189f8, size 102 bytes
// Doc: fmac_buffer_init_n_setup [unknown]: Initialize FMAC buffer structures and call sub-init with large constant
// fmac_buffer_init_n_setup [unknown]: Initialize FMAC buffer structures and call sub-init with large constant
int __fastcall fmac_buffer_init_n_setup(int a1, int a2)
{
  __int16 **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0

  v2 = (__int16 **)off_118A60;
  v3 = dword_118A64;
  v4 = dword_118A68;
LABEL_2:
  v6 = rf_bus_mark_n100_d2d0(a2);
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(v8 + 76);
      if ( *(_DWORD *)(v8 + 68) )
        goto LABEL_4;
      if ( *(int *)(v9 + 4) >= 0 )
        break;
LABEL_5:
      if ( !*(_WORD *)(v8 + 4) )
      {
        sub_118CE0(v8);
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      sub_12F46C(v4, v3, 1147);
      v10 = rf_bus_mark_n100_d2d0(a2);
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return sub_118D28();
    }
    v7 = 0x40000000;
LABEL_4:
    *(_DWORD *)(v9 + 4) = v7;
    goto LABEL_5;
  }
  return sub_118D28();
}

