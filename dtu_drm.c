#include "dtu.h"

union drm_dtu_test {
	int test;
};

#define DRM_DTU_TEST 0x1
#define DRM_IOCTL_DTU_TEST DRM_IOWR(DRM_COMMAND_BASE + DRM_DTU_TEST, union drm_dtu_test)
int dtu_test_ioctl(struct drm_device *dev, void *data, struct drm_file *filp)
{
	TODO
	return 0;
}
const struct drm_ioctl_desc dtu_ioctls[] = {
	DRM_IOCTL_DEF_DRV(DTU_TEST, dtu_test_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
};
const int dtu_ioctls_count = ARRAY_SIZE(dtu_ioctls);


static const struct file_operations dtu_drm_fops = {
	.owner = THIS_MODULE,
	.open = drm_open,
	.release = drm_release,
	.unlocked_ioctl = drm_ioctl,
	/* .mmap = dtu_mmap, */
	.poll = drm_poll,
	.read = drm_read,
};

static int
dtu_drm_load(struct drm_device *dev, unsigned long flags)
{
	TODO
	return 0;
}

static int
dtu_drm_open(struct drm_device *dev, struct drm_file *file_priv)
{
	TODO
	return 0;
}

static void
dtu_drm_postclose(struct drm_device *dev,
		  struct drm_file *file_priv)
{
	TODO
}

static void
dtu_drm_lastclose(struct drm_device *dev)
{
	TODO
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 11, 0)
static int dtu_drm_unload(struct drm_device *dev)
{
	TODO
	return 0;
}
#else
static void dtu_drm_unload(struct drm_device *dev)
{
	TODO
}
#endif

static struct drm_driver dtu_driver = {
	.driver_features = DRIVER_HAVE_IRQ | DRIVER_IRQ_SHARED |
	DRIVER_RENDER,
	.load = dtu_drm_load,
	.open = dtu_drm_open,
	.postclose = dtu_drm_postclose,
	.lastclose = dtu_drm_lastclose,
	.set_busid = drm_pci_set_busid,
	.unload = dtu_drm_unload,

#if defined(CONFIG_DEBUG_FS)
	.debugfs_init = dtu_debugfs_init,
#endif

	.irq_preinstall = dtu_irq_preinstall,
	.irq_postinstall = dtu_irq_postinstall,
	.irq_uninstall = dtu_irq_uninstall,
	.irq_handler = dtu_irq_handler,

	/* .gem_free_object_unlocked = dtu_gem_object_free, */
	/* .gem_open_object = dtu_gem_object_open, */
	/* .gem_close_object = dtu_gem_object_close, */

	/* .dumb_create = dtu_dumb_create, */
	/* .dumb_map_offset = dtu_dumb_mmap, */
	/* .dumb_destroy = dtu_dumb_destroy, */

	/* .prime_handle_to_fd = drm_gem_prime_handle_to_fd, */
	/* .prime_fd_to_handle = drm_gem_prime_fd_to_handle, */
	/* .gem_prime_export = dtu_prime_export, */
	/* .gem_prime_import = drm_gem_prime_import, */
	/* .gem_prime_pin = dtu_gem_prime_pin, */
	/* .gem_prime_unpin = dtu_gem_prime_unpin, */
	/* .gem_prime_res_obj = dtu_gem_prime_res_obj, */
	/* .gem_prime_get_sg_table = dtu_gem_prime_get_sg_table, */
	/* .gem_prime_import_sg_table = dtu_gem_prime_import_sg_table, */
	/* .gem_prime_vmap = dtu_gem_prime_vmap, */
	/* .gem_prime_vunmap = dtu_gem_prime_vunmap, */
	/* .gem_prime_mmap = dtu_gem_prime_mmap, */

	.fops = &dtu_drm_fops,
	.ioctls = dtu_ioctls,

	.name = DRIVER_NAME,
	.desc = DRIVER_DESC,
	.date = DRIVER_DATE,
	.major = KMS_DRIVER_MAJOR,
	.minor = KMS_DRIVER_MINOR,
	.patchlevel = KMS_DRIVER_PATCHLEVEL,
};

int dtu_drm_get_driver(struct drm_driver **drv)
{
	if (!drv)
		return -EINVAL;

	*drv = &dtu_driver;

	return 0;
}
