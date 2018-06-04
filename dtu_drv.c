/* Kernel headers */
#include <linux/module.h>
#include <linux/printk.h>

/* TTM headers */
#include <drm/ttm/ttm_bo_api.h>
#include <drm/ttm/ttm_bo_driver.h>
#include <drm/ttm/ttm_placement.h>
#include <drm/ttm/ttm_module.h>
#include <drm/ttm/ttm_execbuf_util.h>

/* Internal headers */
#include "dtu.h"

/* module params */
int dtu_test = 0;

MODULE_PARM_DESC(test, "Test param");
module_param_named(test, dtu_test, int, 0600);

/* module */
static int __init dtu_init(void)
{
	pr_info("DTU initialized\n");
	dtu_pci_init();

	return 0;
}

static void __exit dtu_exit(void)
{
	pr_info("DTU finalized\n");
	dtu_pci_exit();
}

module_init(dtu_init);
module_exit(dtu_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL and additional rights");
MODULE_VERSION("0.0.0.1");

