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


extern uint32_t dword_102A14;
extern uint32_t off_102A08;
extern uint32_t off_102A0C;
extern uint32_t off_102A10;

// check_boot_flag @ 0x102970, size 152 bytes
int  check_boot_flag(uint16_t *a1, int a2, int a3, int a4, int _18, int a6, int a7)
{
  uint8_t *v8; // r0
  int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r2
  int a5; // r3
  int result; // r0
  int v14; // r1
  int v15; // r3

  if ( a2 )
    return alloc_tx_event("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  if ( *(uint8_t *)off_102A08 )
    goto LABEL_4;
  v8 = (uint8_t *)off_102A10;
  v9 = *((uint16_t *)off_102A10 + 18);
  *(uint32_t *)off_102A0C &= ~0x200u;
  if ( v9 != *a1 )
    goto LABEL_4;
  a5 = *((uint8_t *)a1 + 9);
  v10 = a1[1];
  if ( v8[45] != a5 )
  {
    v11 = a1[2];
    goto LABEL_5;
  }
  v11 = a1[2];
  if ( *((uint16_t *)v8 + 19) != v10
    || *((uint16_t *)v8 + 20) != v11
    || *((uint16_t *)v8 + 21) != a1[3] )
  {
    goto LABEL_5;
  }
  if ( hci_cmd_handler(7u) == 1 || hci_cmd_handler(6u) == 3 )
  {
LABEL_4:
    v10 = a1[1];
    v11 = a1[2];
    LOBYTE(a5) = *((uint8_t *)a1 + 9);
LABEL_5:
    rf_calibrate_tx(*(uint8_t *)a1, v10, v11, *((uint8_t *)a1 + 1), a5, 0);
    result = *(uint32_t *)a1;
    v14 = *((uint32_t *)a1 + 1);
    v15 = dword_102A14;
    *(uint32_t *)dword_102A14 = *(uint32_t *)a1;
    *(uint32_t *)(v15 + 4) = v14;
    *(uint16_t *)(v15 + 8) = a1[4];
    return result;
  }
  return alloc_tx_event("\x9D\x87%s: Setting same channel, do nothing\n", aPhySetChannel);
}
