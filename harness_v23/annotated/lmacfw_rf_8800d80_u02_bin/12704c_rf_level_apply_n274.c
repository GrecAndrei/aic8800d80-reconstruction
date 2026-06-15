// v23 annotated: rf_level_apply_n274 @ 0x12704c
// Original: 12704c_rf_level_apply_n274.c
// Primary struct: <unclustered>
//
// rf_level_apply_n274 @ 0x12704c, size 174 bytes
// Doc: rf_level_apply_n31e [rf]: Apply RF level/tx power setting
// rf_level_apply_n31e [rf]: Apply RF level/tx power setting
void rf_level_apply_n274()
{
  _BYTE *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char n; // r0
  int v5; // r1
  char v6; // r3
  int v7; // r0
  unsigned __int8 v8; // [sp+3h] [bp-Dh] BYREF
  int v9; // [sp+4h] [bp-Ch] BYREF
  int v10; // [sp+8h] [bp-8h] BYREF
  int v11; // [sp+Ch] [bp-4h] BYREF

  v0 = rf_level_apply_n324;
  v1 = *(char *)rf_level_apply_n324;
  if ( *(_BYTE *)rf_level_apply_n324 )
    return;
  v8 = *(_BYTE *)rf_level_apply_n324;
  v2 = *(_DWORD *)rf_level_apply_n328;
  v9 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    sub_113B88(&v8);
    sub_1140B8(&v9);
    goto LABEL_4;
  }
  v10 = 0;
  v11 = 0;
  if ( !sub_114558((int)&v10) )
    v8 = v10;
  if ( sub_1145C4((int)&v11) )
  {
LABEL_4:
    v3 = v8;
    if ( v8 )
      goto LABEL_5;
    goto LABEL_19;
  }
  v9 = (char)v11;
  v3 = v8;
  if ( v8 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      LOBYTE(v3) = 31;
      v8 = 31;
    }
    goto rf_level_apply_n2aa;
  }
LABEL_19:
  LOBYTE(v3) = 15;
rf_level_apply_n2aa:
  v0[4] = v3;
  n = mmio_bit_extract_n();
  v5 = v9;
  v0[6] = n;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      v9 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      v9 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v7 = rf_level_apply_2;
    v0[2] = v6;
    msg_parse(v7, v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}

