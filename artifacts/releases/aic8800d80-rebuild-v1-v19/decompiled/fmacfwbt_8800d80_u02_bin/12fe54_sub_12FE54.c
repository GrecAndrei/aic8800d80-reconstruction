// sub_12FE54 @ 0x12fe54, size 144 bytes
// Doc: sub_122FE54 [util]: Allocate/initialize object with 10-byte memset call
// sub_122FE54 [util]: Allocate/initialize object with 10-byte memset call
int __fastcall sub_12FE54(int a1, int a2)
{
  int v4; // r0
  unsigned __int16 v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = sub_12FB74(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = sub_12FB74(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      **(_WORD **)off_12FEE8 = v6;
      sub_12ECB0(dword_12FEEC, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        sub_12ECB0(dword_12FEE4);
        return 0;
      }
      v8 = sub_12FB74(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      sub_12ECB0(dword_12FEFC, v8);
      sub_12EC54(v8);
      return 0;
    }
    else
    {
      sub_12ECB0(dword_12FEF8, v4);
      return 0;
    }
  }
  else
  {
    sub_12ECB0(dword_12FEF0, **(unsigned __int16 **)off_12FEE8);
    v7 = rf_cmd_process_n4e();
    sub_12ECB0(dword_12FEF4, v7);
    return 0;
  }
}

