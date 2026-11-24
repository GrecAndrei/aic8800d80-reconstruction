#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))


extern uint32_t dword_12569C;
extern uint32_t dword_1256A4;
extern uint32_t off_1256B4;
extern uint32_t off_1256B8;
extern uint32_t off_1256C8;

// process_bt_connection_event @ 0x1253bc, size 730 bytes
int  process_bt_connection_event(int a1, uint32_t *a2)
{
  int v4; // r0
  int v5; // r7
  int v6; // r0
  int v7; // r7
  uint32_t *v8; // r4
  int v9; // r10
  int m; // r5
  uint8_t *v11; // t1
  char v12; // r0
  int v13; // r6
  int v14; // r11
  int v15; // r0
  uint32_t *v16; // r4
  int v17; // r8
  unsigned int k; // r6
  uint8_t *v19; // t1
  int v20; // r5
  char *v21; // r9
  uint8_t *v22; // r10
  char *v23; // r6
  int i; // r4
  int v25; // r5
  int v26; // t1
  char *v27; // r9
  int v28; // r8
  char *v29; // r6
  unsigned int j; // r4
  int v31; // r5
  int v32; // t1
  int v34; // r0
  int v35; // r6
  BOOL v36; // r5
  char v37; // r0
  char *v38; // r2
  char v39; // r3
  const char *v40; // r0
  char *v41; // r2
  int v42; // r0
  char v43; // r0

  v4 = parse_number((uint8_t *)a2[1], nullptr, 0);
  v5 = v4;
  switch ( v4 )
  {
    case 0:
      v21 = (char *)off_1256C8;
      v22 = off_1256B4;
      dispatch_event_handler_1(aTxpwrLevel24g0);
      do
      {
        dispatch_event_handler_1("  [%x] =", v5);
        v23 = v21;
        for ( i = 0; i != 12; ++i )
        {
          v26 = *v23++;
          v25 = v26;
          if ( v26 != -128 )
          {
            if ( i && !(i << 30) )
              uart_tx_byte(32);
            dispatch_event_handler_1(" %2d", v25);
          }
        }
        ++v5;
        uart_tx_string(v22);
        v21 += 12;
      }
      while ( v5 != 3 );
      v27 = (char *)off_1256B8;
      dispatch_event_handler_1(aTxpwrLevel5g01);
      v28 = 0;
      while ( 1 )
      {
        dispatch_event_handler_1("  [%x] =", v28);
        v29 = v27;
        for ( j = 0; ; ++j )
        {
          v32 = *v29++;
          v31 = v32;
          if ( v32 != -128 )
            break;
          if ( j > 3 )
            goto LABEL_48;
          dispatch_event_handler_1(aNa);
LABEL_49:
          ;
        }
        if ( j && !(j << 30) )
          uart_tx_byte(32);
        dispatch_event_handler_1(" %2d", v31);
LABEL_48:
        if ( j != 11 )
          goto LABEL_49;
        ++v28;
        uart_tx_string(off_1256B4);
        v27 += 12;
        if ( v28 == 3 )
          return 0;
      }
    case 1:
      if ( a1 > 4 )
      {
        v15 = parse_number((uint8_t *)a2[2], nullptr, 0);
        v7 = v15;
        if ( v15 > 2 )
        {
          dispatch_event_handler_1("wrong lvl grp:%d\n", v15);
          return 0;
        }
        if ( a1 > 12 )
        {
          dispatch_event_handler_1("set txpwr_level_2.4g:\n  [%d] =", v15);
          v16 = a2 + 2;
          v17 = dword_1256A4 + 12 * v7;
          for ( k = 0; v7 != 1 || k <= 9; ++k )
          {
            v19 = (uint8_t *)v16[1];
            ++v16;
            v20 = (char)parse_number(v19, nullptr, 0);
            if ( v20 >= 32 )
              v20 = 32;
            *(uint8_t *)++v17 = v20;
            if ( k )
            {
              if ( !(k << 30) )
                uart_tx_byte(32);
              dispatch_event_handler_1(" %2d", v20);
              if ( k == 11 )
                goto LABEL_63;
            }
            else
            {
              dispatch_event_handler_1(" %2d", v20);
            }
          }
          goto LABEL_63;
        }
        v42 = parse_number((uint8_t *)a2[3], nullptr, 0);
        v35 = v42;
        if ( v7 == 1 )
          v36 = v42 <= 9;
        else
          v36 = v42 <= 11;
        if ( v36 )
        {
          v43 = parse_number((uint8_t *)a2[4], nullptr, 0);
          v38 = (char *)off_1256C8;
          v39 = v43;
          v40 = aSetTxpwrLevel2;
          goto LABEL_59;
        }
        goto LABEL_65;
      }
      goto LABEL_72;
    case 2:
      if ( a1 > 4 )
      {
        v6 = parse_number((uint8_t *)a2[2], nullptr, 0);
        v7 = v6;
        if ( v6 > 2 )
        {
          dispatch_event_handler_1("wrong lvl grp:%d\n", v6);
          return 0;
        }
        if ( a1 > 12 )
        {
          dispatch_event_handler_1("set txpwr_level_5g:\n  [%d] =", v6);
          v8 = a2 + 2;
          v9 = dword_12569C + 12 * v7;
          for ( m = 0; m != 12; ++m )
          {
            if ( v7 == 1 && m > 9 )
              break;
            v11 = (uint8_t *)v8[1];
            ++v8;
            v12 = parse_number(v11, nullptr, 0);
            v13 = v12;
            v14 = v12;
            if ( v12 >= 32 )
              v14 = 32;
            *(uint8_t *)++v9 = v14;
            if ( m && !(m << 30) )
              uart_tx_byte(32);
            if ( v13 == -128 )
              dispatch_event_handler_1(aNa, v14);
            else
              dispatch_event_handler_1(" %2d", v14);
          }
LABEL_63:
          uart_tx_string(off_1256B4);
          return 0;
        }
        v34 = parse_number((uint8_t *)a2[3], nullptr, 0);
        v35 = v34;
        if ( v7 == 1 )
          v36 = v34 <= 9;
        else
          v36 = v34 <= 11;
        if ( v36 )
        {
          v37 = parse_number((uint8_t *)a2[4], nullptr, 0);
          v38 = (char *)off_1256B8;
          v39 = v37;
          v40 = aSetTxpwrLevel5;
LABEL_59:
          v41 = &v38[12 * v7];
          if ( v39 >= 32 )
            v39 = 32;
          v41[v35] = v39;
          dispatch_event_handler_1(v40, v7, v35);
          return 0;
        }
LABEL_65:
        dispatch_event_handler_1("wrong grp idx:%d\n", v35);
        return v36;
      }
LABEL_72:
      dispatch_event_handler_1(aWrongArgs_0);
      return -1;
  }
  dispatch_event_handler_1(aWrongFunc);
  return -1;
}
