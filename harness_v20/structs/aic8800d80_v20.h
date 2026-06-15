// Auto-generated struct definitions from v20 access pattern analysis
// Cross-referenced with v19 known structs

struct vif_info {
    uint32_t idx;  // 0x0
    uint32_t flags;  // 0x4
    uint32_t mac_addr;  // 0x8
    uint32_t bssid;  // 0xe
    uint32_t ssid;  // 0x14
    uint32_t channel;  // 0x34
    uint32_t band;  // 0x38
    uint32_t type;  // 0x3c
    uint32_t state;  // 0x40
    uint32_t tx_power;  // 0x44
};

struct tx_queue {
    uint32_t head;  // 0x0
    uint32_t tail;  // 0x4
    uint32_t count;  // 0x8
    uint32_t lock;  // 0xc
    uint32_t max_len;  // 0x10
};

struct rx_desc {
    uint32_t addr;  // 0x0
    uint32_t len;  // 0x4
    uint32_t status;  // 0x8
    uint32_t next;  // 0xc
};

struct tx_desc {
    uint32_t addr;  // 0x0
    uint32_t len;  // 0x4
    uint32_t ctrl;  // 0x8
    uint32_t next;  // 0xc
    uint32_t status;  // 0x10
};

struct ke_env {
    uint32_t task_head;  // 0x0
    uint32_t task_tail;  // 0x4
    uint32_t msg_queue;  // 0x8
    uint32_t state;  // 0x10
};

struct scan_req {
    uint32_t ssid;  // 0x0
    uint32_t ssid_len;  // 0x20
    uint32_t channels;  // 0x24
    uint32_t n_channels;  // 0x64
    uint32_t flags;  // 0x68
};

// From v20 analysis
struct delay_timer {
    uint32_t us;  // 0x0
    uint32_t ticks;  // 0x4
};

// From v20 analysis
struct mmio_clock_gate {
    uint8_t bit;  // 0x0
    uint32_t addr;  // 0x0
};

// From v20 analysis
struct ke_dispatch_ctx {
    uint32_t handler;  // 0x0
    uint32_t arg;  // 0x4
    uint32_t next;  // 0x8
    uint32_t state;  // 0xc
};

// From v20 analysis
struct vif_bssid_ref {
    uint32_t vif;  // 0x0
    uint16_t bssid;  // 0xe
};

// From v20 analysis
struct vif_set_state_req {
    uint8_t vif_idx;  // 0x0
    uint32_t vif;  // 0x0
    uint32_t flags;  // 0x4
    uint32_t mac;  // 0x8
    uint32_t mac_hi;  // 0xa
    uint32_t bssid_lo;  // 0xc
    uint32_t bssid_hi;  // 0xe
    uint8_t op;  // 0x18
    uint16_t state;  // 0x1c
};

// From v20 analysis
struct bt_hci_cmd {
    uint8_t ogf;  // 0x0
    uint8_t ocf;  // 0x1
};

// From v20 analysis
struct mmio_reg_poll {
    uint32_t addr;  // 0x0
    uint32_t mask;  // 0xa
    uint32_t val;  // 0xc
    uint32_t expected;  // 0xe
    uint32_t ret;  // 0x1c
};

// From v20 analysis
struct tx_pkt_buf {
    uint32_t addr;  // 0x0
    uint32_t len;  // 0x4
    uint32_t ctrl;  // 0x8
    uint32_t bssid;  // 0xe
    uint32_t payload_end;  // 0x320
};
