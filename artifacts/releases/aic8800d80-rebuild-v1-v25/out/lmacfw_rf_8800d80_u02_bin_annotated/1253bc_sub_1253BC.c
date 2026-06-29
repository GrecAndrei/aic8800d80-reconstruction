// fwstruct annotate: 1253bc_sub_1253BC.c
// sub_1253BC @ 0x1253bc, size 730 bytes
int __fastcall sub_1253BC(int a1, unsigned __int8 **a2)
{
  int v4; // r0
  int v5; // r7
  int v6; // r0
  int v7; // r7
  int v8; // r9
  int v9; // r8
  unsigned __int8 **v10; // r4
  int v11; // r10
  int m; // r5
  unsigned __int8 *v13; // t1
  char v14; // r0
  int v15; // r6
  int v16; // r11
  int v17; // r0
  int v18; // r9
  unsigned __int8 **v19; // r4
  int v20; // r8
  unsigned int k; // r6
  unsigned __int8 *v22; // t1
  int v23; // r5
  int v24; // r9
  int v25; // r11
  int v26; // r8
  _BYTE *v27; // r10
  char *v28; // r6
  int i; // r4
  int v30; // r5
  int v31; // t1
  int v32; // r9
  int v33; // r11
  int v34; // r10
  int v35; // r7
  int v36; // r8
  char *v37; // r6
  unsigned int j; // r4
  int v39; // r5
  int v40; // t1
  int v42; // r0
  int v43; // r6
  BOOL v44; // r5
  char v45; // r0
  int v46; // r2
  char v47; // r3
  int v48; // r0
  int v49; // r2
  int v50; // r0
  char v51; // r0

  v4 = parse_int(a2[1], nullptr, 0);
  v5 = v4;
  switch ( v4 )
  {
    case 0:
      v24 = dword_1256C8;
      v25 = dword_1256DC;
      v26 = dword_1256B0;
      v27 = (_BYTE *)dword_1256B4;
      msg_parse(dword_1256A8);
      do
      {
        msg_parse(v25, v5);
        v28 = (char *)v24;
        for ( i = 0; i != 12; ++i )
        {
          v31 = *v28++;
          v30 = v31;
          if ( v31 != -128 )
          {
            if ( i && !(i << 30) )
              uart_putc(32);
            msg_parse(v26, v30);
          }
        }
        ++v5;
        uart_puts(v27);
        v24 += 12;
      }
      while ( v5 != 3 );
      v32 = dword_1256B8;
      v33 = dword_1256DC;
      v34 = dword_1256D8;
      v35 = dword_1256B0;
      msg_parse(dword_1256AC);
      v36 = 0;
      while ( 1 )
      {
        msg_parse(v33, v36);
        v37 = (char *)v32;
        for ( j = 0; ; ++j )
        {
          v40 = *v37++;
          v39 = v40;
          if ( v40 != -128 )
            break;
          if ( j > 3 )
            goto LABEL_48;
          msg_parse(v34);
LABEL_49:
          ;
        }
        if ( j && !(j << 30) )
          uart_putc(32);
        msg_parse(v35, v39);
LABEL_48:
        if ( j != 11 )
          goto LABEL_49;
        ++v36;
        uart_puts((_BYTE *)dword_1256B4);
        v32 += 12;
        if ( v36 == 3 )
          return 0;
      }
    case 1:
      if ( a1 > 4 )
      {
        v17 = parse_int(a2[2], nullptr, 0);
        v7 = v17;
        if ( v17 > 2 )
        {
          msg_parse(dword_1256C0, v17);
          return 0;
        }
        if ( a1 > 12 )
        {
          v18 = dword_1256B0;
          msg_parse(dword_1256A0, v17);
          v19 = a2 + 2;
          v20 = dword_1256A4 + 12 * v7;
          for ( k = 0; v7 != 1 || k <= 9; ++k )
          {
            v22 = v19[1];
            ++v19;
            v23 = (char)parse_int(v22, nullptr, 0);
            if ( v23 >= 32 )
              v23 = 32;
            *(_BYTE *)++v20 = v23;
            if ( k )
            {
              if ( !(k << 30) )
                uart_putc(32);
              msg_parse(v18, v23);
              if ( k == 11 )
                goto LABEL_63;
            }
            else
            {
              msg_parse(v18, v23);
            }
          }
          goto LABEL_63;
        }
        v50 = parse_int(a2[3], nullptr, 0);
        v43 = v50;
        if ( v7 == 1 )
          v44 = v50 <= 9;
        else
          v44 = v50 <= 11;
        if ( v44 )
        {
          v51 = parse_int(a2[4], nullptr, 0);
          v46 = dword_1256C8;
          v47 = v51;
          v48 = dword_1256CC;
          goto LABEL_59;
        }
        goto LABEL_65;
      }
      goto LABEL_72;
    case 2:
      if ( a1 > 4 )
      {
        v6 = parse_int(a2[2], nullptr, 0);
        v7 = v6;
        if ( v6 > 2 )
        {
          msg_parse(dword_1256C0, v6);
          return 0;
        }
        if ( a1 > 12 )
        {
          v8 = dword_1256D8;
          v9 = dword_1256B0;
          msg_parse(dword_125698, v6);
          v10 = a2 + 2;
          v11 = dword_12569C + 12 * v7;
          for ( m = 0; m != 12; ++m )
          {
            if ( v7 == 1 && m > 9 )
              break;
            v13 = v10[1];
            ++v10;
            v14 = parse_int(v13, nullptr, 0);
            v15 = v14;
            v16 = v14;
            if ( v14 >= 32 )
              v16 = 32;
            *(_BYTE *)++v11 = v16;
            if ( m && !(m << 30) )
              uart_putc(32);
            if ( v15 == -128 )
              msg_parse(v8, v16);
            else
              msg_parse(v9, v16);
          }
LABEL_63:
          uart_puts((_BYTE *)dword_1256B4);
          return 0;
        }
        v42 = parse_int(a2[3], nullptr, 0);
        v43 = v42;
        if ( v7 == 1 )
          v44 = v42 <= 9;
        else
          v44 = v42 <= 11;
        if ( v44 )
        {
          v45 = parse_int(a2[4], nullptr, 0);
          v46 = dword_1256B8;
          v47 = v45;
          v48 = dword_1256BC;
LABEL_59:
          v49 = v46 + 12 * v7;
          if ( v47 >= 32 )
            v47 = 32;
          *(_BYTE *)(v49 + v43) = v47;
          msg_parse(v48, v7, v43);
          return 0;
        }
LABEL_65:
        msg_parse(dword_1256C4, v43);
        return v44;
      }
LABEL_72:
      msg_parse(dword_1256D0);
      return -1;
  }
  msg_parse(dword_1256D4);
  return -1;
}

