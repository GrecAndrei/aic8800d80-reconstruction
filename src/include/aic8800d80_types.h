/*
 * AIC8800D80 Firmware Reconstruction — Standard Types Header
 */

#ifndef AIC8800D80_TYPES_H
#define AIC8800D80_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>

#define LOBYTE(x)  ((uint8_t)((x) & 0xFF))
#define HIBYTE(x)  ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x)  ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x)  ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

#endif /* AIC8800D80_TYPES_H */
