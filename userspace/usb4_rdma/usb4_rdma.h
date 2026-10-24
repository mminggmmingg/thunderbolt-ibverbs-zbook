/* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause */
#ifndef USB4_RDMA_H
#define USB4_RDMA_H

#include <inttypes.h>
#include <stddef.h>
#include <pthread.h>

#include <infiniband/driver.h>
#include <infiniband/kern-abi.h>

#include "usb4_rdma_abi.h"

struct usb4_rdma_device {
	struct verbs_device base_dev;
};

struct usb4_rdma_context {
	struct verbs_context base;
	/* 커널이 제공하는 공유 완료카운터 페이지(read-only, pgoff 0). NULL 이면 기존 syscall 경로. */
	volatile uint64_t *cq_counters;
};

/* poll_cq 빠른경로용 CQ 래퍼: 마지막으로 본 전역 완료카운터를 기억한다. */
struct usb4_rdma_cq {
	struct ibv_cq base;
	uint64_t last_seen;
};

struct usb4_rdma_pd {
	struct ibv_pd base;
};

#endif /* USB4_RDMA_H */
