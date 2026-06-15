// v23 annotated: sub_12FC38 @ 0x12fc38
// Original: 12fc38_sub_12FC38.c
// Primary struct: <unclustered>
//
// sub_12FC38 @ 0x12fc38, size 144 bytes
// Doc: sub_122FC38 [util]: Calls helper with args from struct, sets up state
// sub_122FC38 [util]: Calls helper with args from struct, sets up state
int __fastcall sub_12FC38(int a1, int a2)
{
  int v4; // r0
  unsigned __int16 v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = sub_12F958(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = sub_12F958(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      **(_WORD **)off_12FCCC = v6;
      msg_parse(dword_12FCD0, v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        msg_parse(dword_12FCC8);
        return 0;
      }
      v8 = sub_12F958(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
      msg_parse(dword_12FCE0, v8);
      sub_12EA2C(v8);
      return 0;
    }
    else
    {
      msg_parse(dword_12FCDC, v4);
      return 0;
    }
  }
  else
  {
    msg_parse(dword_12FCD4, **(unsigned __int16 **)off_12FCCC);
    v7 = fmacfw_version_get();
    msg_parse(dword_12FCD8, v7);
    return 0;
  }
}

