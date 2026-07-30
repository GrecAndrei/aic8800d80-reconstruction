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

extern uint32_t off_11C77C;
extern uint32_t dword_11C74C;
extern uint32_t dword_11C760;
extern uint32_t dword_11C75C;
extern uint32_t off_11C750;
extern uint32_t dword_11C754;
extern uint32_t dword_11C758;
extern uint32_t dword_11C764;
extern uint32_t dword_11C770;
extern uint32_t dword_11C774;
extern uint32_t off_11C768;
extern uint32_t dword_11C76C;
extern uint32_t dword_11C778;

// lmac_table_lookup_n540 @ 0x11c540, size 522 bytes
// Doc: lmac_table_lookup_n540 [mac]: LMAC table lookup with index scaling
// lmac_table_lookup_n540 [mac]: LMAC table lookup with index scaling
int  lmac_table_lookup_n540(int a1)
{
  int16_t **v1; // r8
  int v2; // r6
  uint8_t *v3; // r5
  int v5; // r10
  int v6; // r9
  char *v7; // r7
  int v8; // r1
  char v9; // r3
  char v10; // r3
  int v11; // r6
  int v12; // r3
  uint8_t v13; // r4
  int v15; // r1
  int16_t *v16; // r2
  unsigned int v17; // r3
  int v18; // r1
  int v19; // r3
  int v20; // r2
  char *v21; // r1
  int v22; // r0
  int v23; // r3
  int v24; // r3
  char *v25; // r4
  int v26; // r2
  int v27; // r3

  v1 = (int16_t **)off_11C77C;
  v2 = dword_11C74C;
  v3 = *(uint8_t **)(dword_11C74C + 224 * a1 + 72);
  v5 = 8 * a1;
  if ( **(int16_t **)off_11C77C < 0 && !v3 )
    rf_cmd_send_n264(dword_11C760, dword_11C75C, 3149);
  v6 = v2 + 32 * (v5 - a1);
  v7 = (char *)off_11C750;
  sub_11F74C(256, dword_11C754, v3[25], *((uint8_t *)off_11C750 + 91));
  list_remove_node(v7 + 16, v2 + 224 * a1 + 76);
  v9 = *(uint8_t *)(v6 + 85);
  *(uint8_t *)(v6 + 85) = v9 & 0xFE;
  if ( (v9 & 2) != 0 )
  {
    v10 = v7[91] - 1;
    v7[91] = v10;
    if ( !v10 && (v7[88] & 0x40) != 0 )
    {
      msg_parse(dword_11C758, v8);
      rf_mailbox_post_n44(*((uint32_t *)v7 + 20));
    }
  }
  v11 = v2 + 32 * (v5 - a1);
  *(uint8_t *)(v11 + 85) = 0;
  *(uint32_t *)(v11 + 72) = 0;
  v12 = v3[16];
  v13 = v3[25] - 1;
  v3[25] = v13;
  if ( v12 && !v13 )
  {
    list_remove_node(dword_11C764, v3);
    v3[16] = 0;
    v16 = *v1;
    v17 = (uint8_t)(v7[90] - 1);
    v7[90] = v17;
    if ( *v16 < 0 && v17 > 1 )
    {
      rf_cmd_send_n264(dword_11C770, dword_11C75C, 3210);
      v17 = (uint8_t)v7[90];
    }
    if ( v17 )
    {
      sub_11E71C(dword_11C774);
      v23 = dword_11C74C;
      v15 = dword_11C74C + 896;
      do
      {
        *(uint8_t *)(v23 + 85) &= ~1u;
        v23 += 224;
      }
      while ( v15 != v23 );
      if ( !*((uint32_t *)v7 + 20) )
        rf_init_or_query();
    }
    if ( *((uint8_t **)v7 + 10) != v3 )
    {
      if ( *((uint8_t **)v7 + 11) != v3 )
        return rf_get_status_byte_n_a24((int)v3);
      v18 = v3[24];
      v19 = v18 + 1;
      if ( v18 == 2 )
      {
        if ( *((uint8_t *)off_11C768 + 24) != 255 )
        {
          v19 = 0;
          v20 = 0;
          goto LABEL_41;
        }
        v19 = 1;
      }
      else
      {
        v20 = 8 * v19;
        if ( *((uint8_t *)off_11C768 + 28 * v19 + 24) != 255 )
          goto LABEL_41;
        v19 = v18 + 2;
        if ( v18 == 1 )
          v19 = 0;
      }
      v20 = 8 * v19;
      if ( *((uint8_t *)off_11C768 + 28 * v19 + 24) == 255 )
      {
        v21 = 0;
LABEL_22:
        v22 = dword_11C76C;
        *((uint32_t *)v7 + 11) = v21;
        msg_parse(v22, v21);
        return rf_get_status_byte_n_a24((int)v3);
      }
LABEL_41:
      v21 = (char *)off_11C768 + 4 * (v20 - v19);
      goto LABEL_22;
    }
    v24 = (uint8_t)v7[90];
    *((uint32_t *)v7 + 10) = 0;
    if ( !v24 )
      return rf_get_status_byte_n_a24((int)v3);
    v25 = *((char **)v7 + 11);
    if ( v25 )
      return rf_get_status_byte_n_a24((int)v3);
    msg_parse(dword_11C778, v15);
    v26 = v3[24];
    v27 = v26 + 1;
    if ( v26 == 2 )
    {
      if ( *((uint8_t *)off_11C768 + 24) == 255 )
      {
        v27 = 1;
        goto LABEL_35;
      }
      v27 = 0;
    }
    else if ( *((uint8_t *)off_11C768 + 28 * v27 + 24) == 255 )
    {
      v27 = v26 + 2;
      if ( v26 == 1 )
        v27 = 0;
LABEL_35:
      if ( *((uint8_t *)off_11C768 + 28 * v27 + 24) == 255 )
        goto LABEL_36;
    }
    v25 = (char *)off_11C768 + 28 * v27;
LABEL_36:
    if ( *((uint32_t *)v7 + 11) )
      *((uint32_t *)v7 + 11) = v25;
    else
      sub_11ADD0((int)v25);
  }
  return rf_get_status_byte_n_a24((int)v3);
}

