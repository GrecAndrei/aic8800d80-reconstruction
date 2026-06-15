// v23 annotated: parse_int @ 0x121e3c
// Original: 121e3c_parse_int.c
// Primary struct: <unclustered>
//
// parse_int @ 0x121e3c, size 172 bytes
// Doc: rf_cmd_dispatch_n_87 [rf]: Dispatch RF command from command queue entry
// rf_cmd_dispatch_n_87 [rf]: Dispatch RF command from command queue entry
int __fastcall parse_int(unsigned __int8 *a1, _DWORD *a2, unsigned int a3)
{
  int v3; // r5
  int v4; // r7
  int i; // r6
  unsigned int v6; // r3
  int v8; // t1
  int v9; // r3
  int v10; // r3

  v3 = *a1;
  if ( v3 == 48 )
  {
    v3 = a1[1];
    if ( (unsigned int)(v3 - 65) > 0x19 )
      v9 = a1[1];
    else
      v9 = (unsigned __int8)(v3 + 32);
    if ( v9 == 120 && ((v10 = a1[2], (unsigned int)(v10 - 48) <= 9) || (v10 & 0xFFFFFFDF) - 65 <= 5) )
    {
      a1 += 2;
      v3 = v10;
      a3 = 16;
    }
    else
    {
      ++a1;
      if ( !a3 )
      {
        a3 = 8;
        if ( v3 != 45 )
          goto LABEL_5;
LABEL_25:
        v4 = 1;
        v3 = *++a1;
        goto rf_mem_write_field_n1db;
      }
    }
  }
  else if ( !a3 )
  {
    a3 = 10;
  }
  if ( v3 == 45 )
    goto LABEL_25;
LABEL_5:
  v4 = 0;
rf_mem_write_field_n1db:
  for ( i = 0; ; i = v6 + i * a3 )
  {
    v6 = v3 - 48;
    if ( (unsigned __int8)(v3 - 48) > 9u )
    {
      if ( (v3 & 0xFFFFFFDF) - 65 > 5 )
        break;
      if ( (unsigned int)(v3 - 97) > 0x19 )
        v6 = v3 - 55;
      else
        v6 = (unsigned __int8)(v3 - 32) - 55;
    }
    if ( a3 <= v6 )
      break;
    v8 = *++a1;
    v3 = v8;
  }
  if ( v4 )
    i = -i;
  if ( a2 )
    *a2 = a1;
  return i;
}

