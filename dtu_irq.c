#include <linux/irq.h>
#include "dtu.h"

void dtu_irq_preinstall(struct drm_device *dev)
{
	TODO
}

int dtu_irq_postinstall(struct drm_device *dev)
{
	TODO
	return 0;
}

void dtu_irq_uninstall(struct drm_device *dev)
{
	TODO
}

irqreturn_t dtu_irq_handler(int irq, void *arg)
{
	TODO
	return 0;
}
