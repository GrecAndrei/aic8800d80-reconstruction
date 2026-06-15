// Auto-generated struct definitions from v19 + v20 + v22 analysis
// v19: 6 known structs from LLM passes
// v20: 8 new structs from access pattern analysis
// v22: 14 new structs from second LLM pass

#pragma pack(1)
struct vif_info {
    uint32_t idx;  // 0x0
    uint32_t flags;  // 0x4
    uint8_t mac_addr;  // 0x8
    uint8_t bssid;  // 0xe
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

struct delay_timer {
    uint32_t us;  // 0x0
    uint32_t ticks;  // 0x4
};

struct mmio_clock_gate {
    uint32_t reg_addr;  // 0x0
    uint32_t bit_idx;  // 0x0
    uint32_t mask;  // 0x18
    uint32_t value;  // 0x1c
};

struct ke_dispatch_ctx {
    uint32_t msg_id;  // 0x4
    uint32_t task_id;  // 0x6
    uint32_t param;  // 0x8
    uint32_t status;  // 0x6d
};

struct vif_bssid_ref {
    uint32_t vif;  // 0x0
    uint8_t bssid;  // 0xe
};

struct vif_set_state_req {
    uint32_t vif_idx;  // 0x0
    uint32_t vif;  // 0x0
    uint32_t flags;  // 0x4
    uint8_t mac;  // 0x8
    uint8_t mac_hi;  // 0xa
    uint8_t bssid_lo;  // 0xc
    uint8_t bssid_hi;  // 0xe
    uint32_t op;  // 0x18
    uint32_t state;  // 0x1c
};

struct bt_hci_cmd {
    uint32_t ogf;  // 0x0
    uint32_t ocf;  // 0x1
};

struct mmio_reg_poll {
    uint32_t addr;  // 0x0
    uint32_t mask;  // 0xa
    uint32_t val;  // 0xc
    uint32_t expected;  // 0xe
    uint32_t ret;  // 0x1c
};

struct tx_pkt_buf {
    uint32_t addr;  // 0x0
    uint32_t len;  // 0x4
    uint32_t ctrl;  // 0x8
    uint8_t bssid;  // 0xe
    uint32_t payload_end;  // 0x320
};

struct irq_prio_set {
    uint32_t prio;  // 0x2
    uint32_t enable;  // 0x5
};

struct bitmask_state {
    uint32_t prev_base;  // 0x-c
    uint32_t mask0;  // 0x0
    uint32_t mask1;  // 0x4
    uint32_t mask2;  // 0x8
};

struct rf_state {
    uint32_t flags;  // 0x0
    uint32_t sub_flag0;  // 0x6
    uint32_t sub_flag1;  // 0x9
    uint32_t sub_flag2;  // 0xb
    uint32_t value;  // 0xc
    uint32_t cfg;  // 0x58
};

struct ipc_shared_buf {
    uint32_t ptr;  // 0x0
    uint32_t state;  // 0x1f8
};

struct rf_chan_cfg {
    uint32_t base;  // 0x0
    uint32_t cfg;  // 0x8
};

struct log_state {
    uint32_t enable;  // 0x0
    uint32_t state;  // 0x0
    uint32_t level;  // 0x4
    uint32_t flag;  // 0x7
    uint32_t count;  // 0x8
    uint32_t tick;  // 0xa
    uint32_t buf;  // 0x14
    uint32_t status;  // 0x16a
};

struct phy_reg_param {
    uint32_t addr;  // 0x0
    uint32_t status;  // 0x6a
};

struct rf_param_tbl {
    uint32_t field1;  // 0x26
    uint32_t field2;  // 0x2c
    uint32_t field3;  // 0x4c
};

struct irq_status {
    uint32_t prev_ptr;  // 0x-8
    uint32_t status;  // 0x0
};

struct rf_stream {
    uint32_t state;  // 0x0
    uint32_t kick;  // 0x2
};

struct rf_subsys {
    uint32_t base;  // 0x8
    uint32_t cfg;  // 0xc
};

struct rf_calib_tbl {
    uint32_t base;  // 0x0
    uint32_t idx;  // 0xa
    uint32_t count;  // 0xb
};

#pragma pack()