// fwstruct annotate: 115d60_sub_115D60.c
// sub_115D60 @ 0x115d60, size 452 bytes
void __noreturn sub_115D60()
{
  int *v0; // r5
  _BYTE **v1; // r10
  int v2; // r3
  int v3; // r0
  _BYTE *v4; // r7
  int *v5; // r8
  int *v6; // r4
  int *v7; // r6
  _BYTE *v8; // r11
  int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r1
  int v14; // r3

  v0 = (int *)off_115F30;
  sub_12EA88(dword_115F2C, dword_115F28, dword_115F24);
  if ( *(_DWORD *)off_115F34 )
  {
    sub_10EF14();
    if ( *(_WORD *)(*v0 + 8) )
      sub_10EED8(*(unsigned __int16 *)(*v0 + 8));
  }
  v1 = (_BYTE **)off_115F5C;
  if ( **(_BYTE **)off_115F5C == 2 )
  {
    v2 = *v0;
    *(_BYTE *)(v2 + 6) = 2;
    *(_BYTE *)(v2 + 3) = 1;
  }
  v3 = sub_11463C(*(unsigned __int16 *)(*v0 + 4));
  if ( !*(_BYTE *)(*v0 + 3) )
    sub_1146C8();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v4 = off_115F38;
  v5 = (int *)off_115F60;
  v6 = (int *)off_115F3C;
  v7 = (int *)off_115F40;
  v8 = off_115F64;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(_BYTE *)(*v0 + 3) )
        sub_1146B8();
      if ( !*v4 )
        v3 = sub_12D190(v3);
      v3 = sub_130170(v3);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v5 = 1;
      }
      v9 = *v7;
      v10 = *v6 + 1;
      *v6 = v10;
      if ( !v9 )
        break;
      if ( v10 )
        goto LABEL_15;
    }
    v3 = sub_115AE4(v3);
    if ( *(_BYTE *)(*v0 + 3) )
      sub_1146C8();
    if ( **v1 == 1 && *(_BYTE *)off_115F44 )
      break;
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v1 != 3 )
      {
        if ( *(_BYTE *)(*v0 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( v8[1] )
          goto LABEL_29;
        goto LABEL_24;
      }
      v3 = sub_1155B0(v3, v13);
    }
    while ( !v3 );
    if ( !*(_BYTE *)(*v0 + 3) )
      goto LABEL_23;
LABEL_28:
    sub_1146DC();
    if ( v8[1] )
LABEL_29:
      v3 = sub_115640();
LABEL_24:
    v10 = *v6;
    if ( *v6 )
    {
LABEL_15:
      v11 = v10 - 1;
      v12 = *v5;
      *v6 = v11;
      if ( !v11 )
      {
        if ( v12 )
          __enable_irq();
      }
    }
  }
  v14 = **(unsigned __int8 **)off_115F48;
  if ( v14 == 3 )
  {
    v3 = sub_1112F4();
    if ( v3 )
      goto LABEL_36;
    v14 = **(unsigned __int8 **)off_115F48;
  }
  if ( v14 == 1 )
  {
    if ( !v8[1] || *(_BYTE *)off_115F58 )
      goto LABEL_21;
  }
  else if ( v14 || !*(_BYTE *)off_115F4C || !v8[1] )
  {
    goto LABEL_21;
  }
LABEL_36:
  sub_12EA10(v3);
  while ( 1 )
    ;
}

