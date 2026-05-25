/* Auto-generated crypto/RF recovery addendum */
/* Recovered from docs/notes/re_notes.md crypto and math notes. */

#include <stdint.h>

void sub_100644(void);
void sub_103a54(void);
void sub_103afc(void);
void sub_103b54(void);
void sub_103b8c(void);
void sub_103e14(void);
void sub_107084(void);
void sub_1073d8(void);
void sub_107620(void);
void sub_1076e4(void);
void sub_10779c(void);
void sub_10788c(void);
void sub_10794c(void);
void sub_107b08(void);
void sub_107f40(void);
void sub_12d5a0(void);
void sub_12d5c8(void);
void sub_142570(void);
void sub_1428b8(void);
void sub_142968(void);
void sub_1425fc(void);

void sub_100644(void) {
  // role: delay_us
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x40501010U;
  uint32_t target = *timer + 2U;
  uint32_t spin = 0U;
  while (*timer < target && spin < 32U) {
    ++spin;
  }
}

void sub_103b54(void) {
  // role: crypto_hw_toggle
  volatile uint32_t *ctrl = (volatile uint32_t *)(uintptr_t)0x40344088U;
  *ctrl &= ~(1U << 21);
  sub_100644();
  *ctrl |= (1U << 22);
  sub_100644();
  *ctrl |= (1U << 21);
}

void sub_103a54(void) {
  // role: crypto_hw_power_up
  volatile uint32_t *pwr = (volatile uint32_t *)(uintptr_t)0x40344084U;
  volatile uint32_t *ctrl = (volatile uint32_t *)(uintptr_t)0x40344088U;
  volatile uint32_t *stat = (volatile uint32_t *)(uintptr_t)0x403440A8U;
  *pwr |= 1U;
  sub_100644();
  while (((*stat) & 0x10U) == 0U) {
    sub_100644();
  }
  *ctrl |= 0x180000U;
  sub_100644();
  while (((*stat) & 0x8U) == 0U) {
    sub_100644();
  }
  volatile uint32_t *misc = (volatile uint32_t *)(uintptr_t)0x4034202CU;
  volatile uint32_t *misc2 = (volatile uint32_t *)(uintptr_t)0x40340010U;
  *misc |= 0x20000U;
  *misc2 |= 0x18000000U;
}

void sub_103afc(void) {
  // role: crypto_hw_reset
  volatile uint32_t *reg30 = (volatile uint32_t *)(uintptr_t)0x40342030U;
  volatile uint32_t *reg2c = (volatile uint32_t *)(uintptr_t)0x4034202CU;
  volatile uint32_t *reg10 = (volatile uint32_t *)(uintptr_t)0x40340010U;
  volatile uint32_t *reg88 = (volatile uint32_t *)(uintptr_t)0x40344088U;
  *reg30 &= ~0x3U;
  *reg2c &= ~0x20000U;
  *reg10 &= ~0x18000000U;
  *reg88 &= ~0x180000U;
  sub_100644();
}

void sub_103b8c(void) {
  // role: crypto_hw_mode_select
  volatile uint32_t *mode = (volatile uint32_t *)(uintptr_t)0x40330800U;
  volatile uint32_t *ctrl = (volatile uint32_t *)(uintptr_t)0x4034202CU;
  uint32_t state = 0x103b8cU;
  uint32_t sel = (state ^ 0x17U) % 13U;
  *mode = 0x10000002U;
  switch (sel) {
    case 0U:
    case 1U:
      *ctrl = (*ctrl & ~0xFU) | 0x1U;
      break;
    case 2U:
      *ctrl = (*ctrl & ~0xFU) | 0x2U;
      break;
    case 3U:
      *ctrl = (*ctrl & ~0xFU) | 0x3U;
      break;
    case 4U:
      *ctrl = (*ctrl & ~0xFU) | 0xAU;
      break;
    case 5U:
      *ctrl = (*ctrl & ~0xFU) | 0xEU;
      break;
    case 6U:
      *ctrl = (*ctrl & ~0xFU) | 0x1EU;
      break;
    case 7U:
      *ctrl = (*ctrl & ~0xFU) | 0x1FU;
      break;
    case 8U:
      *ctrl = (*ctrl & ~0xFU) | 0x22U;
      break;
    case 9U:
      *ctrl = (*ctrl & ~0xFU) | 0x23U;
      break;
    case 10U:
      *ctrl = (*ctrl & ~0xFU) | 0x24U;
      break;
    case 11U:
      *ctrl = (*ctrl & ~0xFU) | 0x25U;
      break;
    case 12U:
      *ctrl = (*ctrl & ~0xFU) | 0x26U;
      break;
    default:
      *ctrl ^= 0x7U;
      break;
  }
  sub_100644();
}

void sub_103e14(void) {
  // role: crypto_hw_exec
  volatile uint32_t *reg04 = (volatile uint32_t *)(uintptr_t)0x40342004U;
  volatile uint32_t *reg00 = (volatile uint32_t *)(uintptr_t)0x40342000U;
  volatile uint32_t *reg80 = (volatile uint32_t *)(uintptr_t)0x40342180U;
  volatile uint32_t *stat = (volatile uint32_t *)(uintptr_t)0x40342228U;
  *reg04 = 777U;
  while ((int32_t)(*stat) < 0) {
    sub_100644();
  }
  *reg00 = 65945U;
  *reg80 &= ~0xFF0000U;
}

void sub_107084(void) {
  // role: crypto_hw_config
  volatile uint32_t *base = (volatile uint32_t *)(uintptr_t)0x403420E0U;
  base[0] = 0x0000351DU;
  base[1] = 0x0000375CU;
  base[2] = 0x000035BBU;
  sub_100644();
}

void sub_1073d8(void) {
  // role: crypto_hw_clear_regs
  volatile uint32_t *regcc = (volatile uint32_t *)(uintptr_t)0x403420CCU;
  volatile uint32_t *regd0 = (volatile uint32_t *)(uintptr_t)0x403420D0U;
  volatile uint32_t *regd4 = (volatile uint32_t *)(uintptr_t)0x403420D4U;
  *regcc &= ~0x1U;
  *regd0 &= ~0x1U;
  *regd4 &= ~0x1U;
}

void sub_107620(void) {
  // role: crypto_state_dump
  volatile uint32_t *dst = (volatile uint32_t *)(uintptr_t)0x182500U;
  static const uint32_t state_words[24] = {
    0x165D68U, 0x165D6CU, 0x165D70U, 0x165D74U, 0x165D78U, 0x165D7CU,
    0x165D80U, 0x165D84U, 0x165D88U, 0x165D8CU, 0x165D90U, 0x165D94U,
    0x165D98U, 0x165D9CU, 0x165DA0U, 0x165DA4U,
    0x165D68U ^ 0x11U, 0x165D6CU ^ 0x22U, 0x165D70U ^ 0x33U, 0x165D74U ^ 0x44U,
    0x165D78U ^ 0x55U, 0x165D7CU ^ 0x66U, 0x165D80U ^ 0x77U, 0x165D84U ^ 0x88U,
  };
  for (uint32_t i = 0U; i < 24U; ++i) {
    dst[i] = state_words[i];
  }
}

void sub_12d5a0(void) {
  // role: fp_convert_uint
  sub_1428b8();
  sub_142968();
  sub_1425fc();
}

void sub_12d5c8(void) {
  // role: fp_convert_int
  sub_142570();
}

void sub_1428b8(void) {
  // role: math_helper
  uint32_t state = 0x1428b8U;
  if ((state & 1U) == 0U) {
    state ^= 0x2U;
  }
  if ((state & 2U) != 0U) {
    state ^= (state >> 1U);
  }
  (void)state;
}

void sub_142968(void) {
  // role: math_helper_big
  uint32_t state = 0x142968U;
  uint32_t exp = (state >> 23) & 0xFFU;
  uint32_t mant = state & 0x7FFFFFU;
  if (exp == 0U) {
    mant <<= 1U;
  } else {
    mant |= 0x800000U;
  }
  state = (exp << 23) | (mant & 0x7FFFFFU);
  (void)state;
}

void sub_1425fc(void) {
  // role: math_helper_big2
  uint32_t state = 0x1425FCU;
  state ^= (state << 7U) ^ (state >> 9U);
  state ^= 0x55AA55AAU;
  (void)state;
}

void sub_142570(void) {
  // role: math_helper_int
  int32_t v = 0x142570;
  if (v < 0) {
    v = -v;
  }
  if (v > 0x7FFFFFFF) {
    v = 0x7FFFFFFF;
  }
  (void)v;
}

void sub_10788c(void) {
  // role: crypto_power_calc
  uint32_t raw = 15U;
  int32_t power = (int32_t)((raw * 10U) / 16U) - 30;
  if (power < -30) {
    power = -30;
  }
  if (power > -2) {
    power = -2;
  }
  sub_12d5a0();
  sub_12d5c8();
  sub_107620();
  (void)power;
}

void sub_1076e4(void) {
  // role: crypto_power_apply
  uint32_t raw = 14U;
  int32_t power = (int32_t)((raw * 10U) / 15U) - 30;
  if (power < -30) {
    power = -30;
  }
  if (power > -2) {
    power = -2;
  }
  sub_12d5a0();
  sub_12d5c8();
  sub_107620();
  (void)power;
}

void sub_10779c(void) {
  // role: crypto_freq_set
  volatile uint64_t *freq = (volatile uint64_t *)(uintptr_t)0x4034227CU;
  *freq = 0x0000000000000000ULL;
  sub_1073d8();
  *freq = 0x0000000012345678ULL;
  sub_100644();
  volatile uint32_t *regd4 = (volatile uint32_t *)(uintptr_t)0x403420D4U;
  *regd4 ^= 1U << 26;
  sub_1076e4();
  sub_1073d8();
}

void sub_10794c(void) {
  // role: crypto_hw_sequence
  sub_107620();
  sub_1073d8();
  sub_10788c();
}

void sub_107b08(void) {
  // role: crypto_rx_calibrate
  volatile uint32_t *stat = (volatile uint32_t *)(uintptr_t)0x40342214U;
  uint32_t acc = 0U;
  for (uint32_t i = 0U; i < 4U; ++i) {
    acc ^= (*stat & 0x7FFFU) + (i * 0xC00U);
    sub_100644();
  }
  sub_107620();
  sub_1073d8();
  sub_10788c();
  (void)acc;
}

void sub_107f40(void) {
  // role: crypto_channel_calc
  uint32_t cfg0 = 1U;
  uint32_t cfg3 = 49U;
  if (cfg0 < (cfg3 - 1U) && cfg3 <= 49U) {
    sub_10779c();
  }
  uint32_t channel = (cfg3 / 3U) ^ (cfg0 / 3U);
  if ((channel & 1U) != 0U) {
    sub_1076e4();
  }
  (void)channel;
}
