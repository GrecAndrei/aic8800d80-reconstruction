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

extern uint32_t off_113FB0;
extern uint32_t dword_113FBC;
extern uint32_t off_113FB4;
extern uint32_t off_113FB8;
extern uint32_t dword_113FC0;

// dispatch_function_ptr @ 0x113f70, size 64 bytes
int dispatch_function_ptr()
{
  int v0; // r0
  uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((uint32_t *)off_113FB0 + 2) + 16))(*((uint32_t *)off_113FB0 + 1));
  if ( !v0 )
    return printf_wrapper(dword_113FBC);
  v1 = (uint32_t *)v0;
  result = global_env_init(*(uint32_t *)off_113FB4 + v0, *(uint32_t *)off_113FB8);
  if ( result < 0 )
  {
    memory_pool_free(v1);
    return printf_wrapper(dword_113FC0);
  }
  return result;
}

