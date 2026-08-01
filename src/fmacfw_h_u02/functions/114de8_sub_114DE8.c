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

extern uint32_t dword_114EA4;
extern uint32_t dword_114EA8;
extern uint32_t dword_114EAC;
extern uint32_t dword_114EB0;
extern uint32_t off_114EB4;
extern uint32_t off_114EB8;
extern uint32_t dword_114EBC;
extern uint32_t off_114EC0;
extern uint32_t off_114EC4;
extern uint32_t off_114EC8;
extern uint32_t off_114ED0;
extern uint32_t off_114ECC;
extern uint32_t dword_114ED4;
extern uint32_t off_114ED8;
extern uint32_t off_114EDC;

// is_patch_loaded @ 0x114de8, size 184 bytes
void __noreturn is_patch_loaded()
{
  uint32_t *v0; // r2
  unsigned int v1; // r3
  int v2; // r1
  char *v3; // r2
  char *v4; // r3
  uint32_t *v5; // r0
  int v6; // t1
  uint32_t *v7; // r2
  int v8; // r0
  int i; // r3
  int v10; // r2
  int v11; // r3
  uint8_t *v12; // r2

  v0 = (uint32_t *)dword_114EA4;
  if ( dword_114EA4 < (unsigned int)dword_114EA8 )
  {
    v1 = ((dword_114EA8 - 1 - dword_114EA4) & 0xFFFFFFFC) + 4 + dword_114EA4;
    do
      *v0++ = 0;
    while ( v0 != (uint32_t *)v1 );
  }
  v2 = dword_114EAC;
  if ( dword_114EAC < (unsigned int)dword_114EB0 )
  {
    v3 = (char *)off_114EB4;
    v4 = (char *)off_114EB4 + ((dword_114EB0 - 1 - dword_114EAC) & 0xFFFFFFFC) + 4;
    v5 = (uint32_t *)dword_114EAC;
    do
    {
      v6 = *(uint32_t *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_114EB8;
  v8 = dword_114EBC;
  *((uint32_t *)off_114EB8 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(uint8_t *)(v10 + 768) = -1;
  }
  if ( (uint16_t)*(uint32_t *)off_114EB8 == 49729 )
    *(uint32_t *)off_114EC0 = 1;
  v11 = HIBYTE(*(uint32_t *)off_114EC4);
  *(uint8_t *)off_114EC8 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_114ED0;
    *(uint32_t *)off_114ECC = dword_114ED4;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(uint32_t *)off_114ED8 &= ~0x4000u;
  *(uint8_t *)off_114EDC = BYTE2(*(uint32_t *)off_114EC4);
  aes_load_key();
  check_patch_signature();
  mac_state_init();
}

