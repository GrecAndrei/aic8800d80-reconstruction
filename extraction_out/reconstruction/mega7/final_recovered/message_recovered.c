/* Auto-generated message-path recovery addendum */
/* Recovered from docs/notes/re_notes.md message routing and buffer notes. */

#include <stdint.h>

void sub_12d108(void);
void sub_12d190(void);
void sub_12f3ec(void);

void sub_10cc94(void) {
  // role: state check helper
  volatile uint32_t *state_ptr = (volatile uint32_t *)(uintptr_t)0x182BA0U;
  uint32_t state = 0x10cc94U;
  if (*state_ptr != 3U) {
    state ^= 0x10ced8U;
    state = (state + *state_ptr) ^ (state >> 2U);
  } else {
    state ^= 0x00000003U;
    state = (state + 0x10ced8U) ^ (state >> 1U);
  }
  (void)state;
}

void sub_12f3ec(void) {
  // role: fallback_handler thunk
  sub_10cc94();
}

void sub_12ca88(void) {
  // role: buffer_pool_manage
  volatile uintptr_t *pool_head = (volatile uintptr_t *)(uintptr_t)0x18E618U;
  volatile uintptr_t *pool_limit = (volatile uintptr_t *)(uintptr_t)0x1922C0U;
  uintptr_t node = pool_head[0];
  uintptr_t limit = (uintptr_t)pool_limit;
  uint32_t hops = 0U;
  uint32_t state = 0x12ca88U;

  while (node != 0U && hops < 8U) {
    if (node == limit) {
      state ^= 0x191f88U;
      break;
    }
    uintptr_t next = *(volatile uintptr_t *)(uintptr_t)node;
    state ^= (uint32_t)(node & 0xFFFFU);
    state = (state << 1U) ^ (state >> 3U) ^ (uint32_t)(next & 0xFFFFU);
    node = next;
    ++hops;
  }

  if (node == 0U) {
    state ^= 0x12ca88U;
  } else {
    state ^= (uint32_t)(node & 0xFFFFU);
  }

  (void)state;
}

void sub_12c8f8(void) {
  // role: buffer_pool_manage thunk
  sub_12ca88();
}

void sub_12c84c(void) {
  // role: message_dispatch
  volatile uint32_t *hw_gate = (volatile uint32_t *)(uintptr_t)0x182749U;
  volatile uint32_t *msg_gate = (volatile uint32_t *)(uintptr_t)0x17348CU;
  uint32_t state = 0x12c84cU;
  uint32_t msg_type = (state >> 2U) & 0x1FU;

  if (msg_type <= 0xCU) {
    sub_12d108();
    state ^= 0x4000000U;
    if (msg_type <= 0x8U) {
      state ^= 0x191f88U;
    }
  } else {
    state ^= 0xb7U;
    state = (state + 0x12c84cU) ^ (msg_type >> 1U);
  }

  if (*hw_gate != 0U) {
    sub_12ca88();
  } else {
    sub_12f3ec();
  }

  if (*msg_gate != 0U) {
    state ^= *msg_gate;
  } else {
    state ^= 0x12c84cU;
  }

  (void)state;
}
