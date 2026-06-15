// v23 annotated: sub_116188 @ 0x116188
// Original: 116188_sub_116188.c
// Primary struct: <unclustered>
//
// sub_116188 @ 0x116188, size 472 bytes
// Doc: sub_1216188 [patch]: Initialization routine loading multiple config pointers and calling setup
// sub_1216188 [patch]: Initialization routine loading multiple config pointers and calling setup
void __noreturn sub_116188()
{
  int *v0; // r5
  _BYTE **v1; // r8
  int v2; // r3
  int v3; // r0
  _BYTE *v4; // r7
  int *v5; // r9
  int *v6; // r4
  int *v7; // r6
  _BYTE *v8; // r11
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3

  v0 = (int *)off_11636C;
  sub_12ECB0(dword_116368, dword_116364, dword_116360);
  if ( *(_DWORD *)off_116370 )
  {
    sub_10ED6C();
    if ( *(_WORD *)(*v0 + 8) )
      sub_10ED30(*(unsigned __int16 *)(*v0 + 8));
  }
  v1 = (_BYTE **)off_11639C;
  if ( **(_BYTE **)off_11639C == 2 )
  {
    v2 = *v0;
    *(_BYTE *)(v2 + 6) = 2;
    *(_BYTE *)(v2 + 3) = 1;
  }
  v3 = sub_114498(*(unsigned __int16 *)(*v0 + 4));
  if ( !*(_BYTE *)(*v0 + 3) )
    mmio_clear_bit1_n_524();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v4 = off_116374;
  v5 = (int *)off_1163A0;
  v6 = (int *)off_116378;
  v7 = (int *)off_11637C;
  v8 = off_1163A4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(_BYTE *)(*v0 + 3) )
        sub_114514();
      if ( !*v4 )
        v3 = bt_msg_handler_122D3B8(v3);
      v3 = sub_13038C(v3);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v5 = 1;
      }
      v10 = *v7;
      v11 = *v6 + 1;
      *v6 = v11;
      if ( !v10 )
        break;
      if ( v11 )
        goto LABEL_15;
    }
    if ( *((_BYTE *)off_116380 + 18) )
    {
      *(_BYTE *)off_11638C = 0;
      if ( *(_BYTE *)(*v0 + 3) )
LABEL_39:
        mmio_clear_bit1_n_524();
    }
    else
    {
      sub_116034();
      if ( *(_BYTE *)(*v0 + 3) )
        goto LABEL_39;
    }
    if ( **v1 == 1 && *(_BYTE *)off_116384 )
    {
      v14 = **(unsigned __int8 **)off_116388;
      if ( v14 == 3 )
      {
        v3 = state_flag_check();
        if ( !v3 )
        {
          v14 = **(unsigned __int8 **)off_116388;
          goto LABEL_32;
        }
      }
      else
      {
LABEL_32:
        if ( v14 == 1 )
        {
          if ( !v8[1] || *(_BYTE *)off_116398 )
            goto LABEL_21;
        }
        else if ( v14 || !*(_BYTE *)off_11638C || !v8[1] )
        {
          goto LABEL_21;
        }
      }
      sdio_wait_busy(v3);
      while ( 1 )
        ;
    }
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
      v3 = sub_115B00(v3, v9);
    }
    while ( !v3 );
    if ( !*(_BYTE *)(*v0 + 3) )
      goto LABEL_23;
LABEL_28:
    mmio_set_flag_bit1();
    if ( v8[1] )
LABEL_29:
      v3 = sub_115B90();
LABEL_24:
    v11 = *v6;
    if ( *v6 )
    {
LABEL_15:
      v12 = v11 - 1;
      v13 = *v5;
      *v6 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
  }
}

