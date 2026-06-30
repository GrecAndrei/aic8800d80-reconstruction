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

extern uint32_t off_102BD0;

// crypto_hw_disable @ 0x102b64, size 106 bytes
// Doc: crypto_hw_disable [mac]: Disable hardware crypto engine (clear enable bits)
// crypto_hw_disable [mac]: Disable hardware crypto engine (clear enable bits)
int  crypto_hw_disable(int result)
{
  int v1; // r4
  int v2; // zf
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3

  v2 = result == 0;
  if ( result )
    v3 = -5;
  else
    v3 = -65;
  v4 = *(uint32_t *)off_102BD0 & v3;
  if ( !result )
    result = 32;
  *(uint32_t *)off_102BD0 = v4;
  if ( v2 )
    v1 = -17;
  else
    result = 2;
  if ( v2 )
    v3 = 16;
  else
    v1 = -2;
  if ( !v2 )
    v3 = 1;
  LOBYTE(v5) = -56;
  do
    v5 = (uint8_t)(v5 - 1);
  while ( v5 );
  v6 = v4 & v1;
  *(uint32_t *)off_102BD0 = v6;
  LOBYTE(v7) = 50;
  do
    v7 = (uint8_t)(v7 - 1);
  while ( v7 );
  v8 = v6 | result;
  *(uint32_t *)off_102BD0 = v8;
  LOBYTE(v9) = 50;
  do
    v9 = (uint8_t)(v9 - 1);
  while ( v9 );
  *(uint32_t *)off_102BD0 = v8 | v3;
  return result;
}

