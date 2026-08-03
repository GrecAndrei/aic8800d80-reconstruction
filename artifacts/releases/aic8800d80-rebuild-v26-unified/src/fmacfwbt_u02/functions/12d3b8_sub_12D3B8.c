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

extern uint32_t off_12D420;
extern uint32_t off_12D42C;
extern uint32_t dword_12D424;
extern uint32_t off_12D428;
extern uint32_t dword_12D430;
extern uint32_t dword_12D434;

// sub_12D3B8 @ 0x12d3b8, size 104 bytes
void sub_12D3B8()
{
  unsigned int *v0; // r6
  unsigned int v1; // r4
  int16_t **v2; // r8
  int v3; // r5
  void *v4; // r7
  int v5; // r10
  int v6; // r9
  int v7; // r4
  void ( *v8)(uint32_t); // r3

  v0 = (unsigned int *)off_12D420;
  v1 = *(uint32_t *)off_12D420;
  if ( *(uint32_t *)off_12D420 )
  {
    v2 = (int16_t **)off_12D42C;
    v3 = dword_12D424;
    v4 = off_12D428;
    v5 = dword_12D430;
    v6 = dword_12D434;
    while ( 1 )
    {
      v7 = __clz(v1);
      if ( **v2 < 0 )
      {
        if ( v7 <= 27 )
        {
          v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
          if ( v8 )
            goto LABEL_5;
        }
        sub_12F694(v6, v5, 230);
      }
      v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
LABEL_5:
      v8(*(uint32_t *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
      {
        sub_114514();
        if ( !v1 )
          return;
      }
      else if ( !v1 )
      {
        return;
      }
    }
  }
}

