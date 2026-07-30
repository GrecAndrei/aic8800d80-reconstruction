/*
 * AIC8800D80 Firmware Reconstruction — Data Structures Header
 */

#ifndef AIC8800D80_STRUCTS_H
#define AIC8800D80_STRUCTS_H

#include "aic8800d80_types.h"

/* Common C Struct Layouts inferrred from access fingerprints */

typedef struct {
    uint32_t flags;
    uint32_t rate_idx;
    uint32_t buf_ptr;
    uint32_t len;
} tx_descriptor_t;

typedef struct {
    uint32_t status;
    uint32_t len;
    uint32_t rssi;
    uint32_t timestamp;
} rx_descriptor_t;

typedef struct {
    uint32_t state;
    uint32_t channel;
    uint32_t bandwidth;
    uint8_t  bssid[6];
} wifi_config_t;

#endif /* AIC8800D80_STRUCTS_H */
