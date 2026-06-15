// v23 annotated: sub_130018 @ 0x130018
// Original: 130018_sub_130018.c
// Primary struct: <unclustered>
//
// sub_130018 @ 0x130018, size 288 bytes
int __fastcall sub_130018(unsigned int a1)
{
  int v1; // r0
  int v2; // r4
  _DWORD *v4; // r0
  _DWORD *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r3
  _BYTE *v11; // r2
  int v12; // r0
  int v13; // r8
  int v14; // r7
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // t1
  int v18; // r7
  int v19; // r6
  unsigned int v20; // r4
  unsigned int v21; // r5
  int v22; // t1
  unsigned int v23; // [sp+8h] [bp-8h]

  v1 = sub_12F810(a1, (_BYTE *)dword_130138, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( sub_143E40(dword_130140) != v1 || sub_143AA8(dword_130140, dword_130138) )
      {
        v4 = rf_bus_mark_n100_d2d0(dword_130144);
        v5 = v4;
        if ( v4 )
        {
          memcpy_aligned_n7c(v4 + 1, dword_130138);
          list_push_tail(dword_130148, v5);
        }
        else
        {
          uart_puts((_BYTE *)dword_13015C);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        v10 = __get_CPSR();
        v23 = __get_CPSR();
        sub_10DC24(dword_13014C, CPSR, v7, v8, v9, v10, v23);
        if ( v9 )
        {
          v13 = dword_13016C;
          v14 = dword_130164;
          v15 = v9 & 0xFFFFFFF0;
          uart_puts((_BYTE *)dword_130160);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              sub_10DC24(v13, v15);
            v17 = *(_DWORD *)v15;
            v15 += 4;
            sub_10DC24(v14, v17);
          }
          while ( v16 != v15 );
        }
        if ( v8 )
        {
          v18 = dword_13016C;
          v19 = dword_130164;
          v20 = v8 & 0xFFFFFFF0;
          uart_puts((_BYTE *)dword_130168);
          v21 = v20 + 256;
          do
          {
            if ( !(v20 << 28) )
              sub_10DC24(v18, v20);
            v22 = *(_DWORD *)v20;
            v20 += 4;
            sub_10DC24(v19, v22);
          }
          while ( v21 != v20 );
        }
        uart_puts((_BYTE *)dword_130150);
        v11 = off_130154;
        v12 = *(unsigned __int8 *)off_130154;
        if ( *(_BYTE *)off_130154 )
        {
          *((_BYTE *)off_130158 + 783) = -4;
          v2 = 0;
          *v11 = 0;
        }
        else
        {
          *((_BYTE *)off_130158 + 783) = -12;
          v2 = v12;
          *v11 = 1;
        }
      }
    }
    else
    {
      uart_puts((_BYTE *)dword_13013C);
    }
    sub_12F810(0x30u, (_BYTE *)dword_130138, dword_13013C);
  }
  return v2;
}

