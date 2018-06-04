#include <linux/printk.h>
#include <drm/drmP.h>
#include <drm/drm_gem.h>
#include <drm/amdgpu_drm.h>
#include <drm/gpu_scheduler.h>

#include <linux/version.h>

#ifndef __DTU_H__
#define __DTU_H__

#define DRIVER_AUTHOR		"Ding Shengge"
#define DRIVER_NAME		"dtu"
#define DRIVER_DESC		"Deep Thought Unit"
#define DRIVER_DATE		"20180611"

#define KMS_DRIVER_MAJOR	3
#define KMS_DRIVER_MINOR	24
#define KMS_DRIVER_PATCHLEVEL	0

#define TODO \
	pr_info("%s to be implemented\n", __func__);

/* PCI */
int dtu_pci_init(void);
void dtu_pci_exit(void);

/* debug */
int dtu_debugfs_init(struct drm_minor *minor);

/* IRQ */
void dtu_irq_preinstall(struct drm_device *dev);
int dtu_irq_postinstall(struct drm_device *dev);
void dtu_irq_uninstall(struct drm_device *dev);
irqreturn_t dtu_irq_handler(int irq, void *arg);

/* DRM */
int dtu_drm_get_driver(struct drm_driver **drv);

#endif	/* __DTU_H__ */
