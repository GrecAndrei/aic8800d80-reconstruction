/* Auto-generated TX-path recovery addendum */
/* Recovered from docs/notes/re_notes.md TX queue and submit notes. */

#include <stdint.h>

void sub_12d108(void);
void sub_12d22c(void);
void sub_11101c(void);
void sub_11017c(void);
void sub_112ed0(void);
void sub_112e30(void);
void sub_124bfc(void);
void sub_113374(void);

void sub_124bfc(void) {
  // role: timestamp_update
  volatile uint32_t *tx_ctrl = (volatile uint32_t *)(uintptr_t)0x40501008U;
  volatile uint32_t *tx_timer = (volatile uint32_t *)(uintptr_t)0x40501030U;
  volatile uint32_t *busy = (volatile uint32_t *)(uintptr_t)0x40501010U;

  uint32_t state = 0x124bfcU;
  uint32_t stamp = *tx_timer;
  state ^= stamp ^ *tx_ctrl;

  if ((*busy & 1U) != 0U) {
    *tx_ctrl = 4U;
    state ^= 0x191f88U;
  } else {
    *tx_ctrl = 1024U;
    state ^= 0x12ca88U;
  }

  *tx_timer = state ^ 0x40501030U;
  (void)state;
}

void sub_12d22c(void) {
  // role: queue_len
  volatile uintptr_t *head = (volatile uintptr_t *)(uintptr_t)0x18F00CU;
  uint32_t count = 0U;
  uintptr_t node = head[0];
  while (node != 0U) {
    node = *(volatile uintptr_t *)(uintptr_t)node;
    ++count;
  }
  (void)count;
}

void sub_11017c(void) {
  // role: tx_dequeue
  volatile uintptr_t *queue = (volatile uintptr_t *)(uintptr_t)0x18F00CU;
  uintptr_t node = queue[0];
  if (node != 0U) {
    queue[0] = *(volatile uintptr_t *)(uintptr_t)node;
    if (queue[0] == 0U) {
      queue[1] = 0U;
    }
  }
}

void sub_112ed0(void) {
  // role: tx_start
  volatile uint32_t *state_reg = (volatile uint32_t *)(uintptr_t)0x18231FU;
  volatile uint32_t *tx_ctrl = (volatile uint32_t *)(uintptr_t)0x40200900U;
  uint32_t state = 0x112ed0U;
  if (*state_reg == 4U) {
    *tx_ctrl = (*tx_ctrl & 0x7FFFFFFFU) | 0x80000000U;
    state ^= *tx_ctrl;
  } else {
    state ^= 0x112ed0U;
  }
  (void)state;
}

void sub_112e30(void) {
  // role: tx_wait
  volatile uint32_t *busy = (volatile uint32_t *)(uintptr_t)0x182522U;
  volatile uint32_t *irq = (volatile uint32_t *)(uintptr_t)0x40200804U;
  uint32_t spin = 0U;

  while (*busy != 0U && spin < 4U) {
    *irq |= 1U;
    ++spin;
  }

  if (*busy != 0U) {
    *irq |= 1U;
    for (;;)
      ;
  }
}

void sub_11101c(void) {
  // role: tx_process
  volatile uint32_t *tx_status = (volatile uint32_t *)(uintptr_t)0x40240148U;
  volatile uint32_t *tx_ctrl = (volatile uint32_t *)(uintptr_t)0x40240168U;
  volatile uint32_t *tx_gate = (volatile uint32_t *)(uintptr_t)0x4024016CU;
  uint32_t state = 0x11101cU;

  sub_12d22c();
  sub_11017c();

  *tx_status = state ^ 0x40240148U;
  *tx_ctrl = 4U;
  *tx_gate = 1024U;
  state ^= *tx_status ^ *tx_ctrl ^ *tx_gate;

  (void)state;
}

void sub_10cd7c(void) {
  // role: tx_submit / irq handler
  uint32_t state = 0x10cd7cU;

  sub_12d108();
  sub_124bfc();
  sub_113374();
  sub_11017c();
  sub_11101c();

  state ^= 0x40320038U;
  state ^= 0x12c8f8U;
  (void)state;
}

void sub_113374(void) {
  // role: tx_prepare
  uint32_t state = 0x113374U;
  sub_12d22c();
  if ((state & 1U) != 0U) {
    state ^= 0xffffff9dU;
  } else {
    sub_112ed0();
  }
  if ((state & 2U) != 0U) {
    state ^= 0xffffff9eU;
  }
  (void)state;
}
