#include <linux/pci.h>
#include <linux/module.h>
#include "dtu.h"

static const struct pci_device_id did_list[] = {
	{0x1002, 0x686c, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0},
	{0, 0, 0},
};

MODULE_DEVICE_TABLE(pci, did_list);

static int
dtu_pci_probe(struct pci_dev *pdev,
	      const struct pci_device_id *ent)
{
	struct drm_device *ddev;
	struct drm_driver *ddriver;
	int ret;

	ret = dtu_drm_get_driver(&ddriver);
	if (ret)
		goto err_out;

	ddev = drm_dev_alloc(ddriver, &pdev->dev);
	if (IS_ERR(ddev))
		return PTR_ERR(ddev);

	ret = pci_enable_device(pdev);
	if (ret)
		goto err_free;

	ddev->pdev = pdev;
	pci_set_drvdata(pdev, ddev);

	ret = drm_dev_register(ddev, ent->driver_data);
	if (ret)
		goto err_pci;

	return 0;

err_pci:
	pci_disable_device(pdev);
err_free:
	drm_dev_unref(ddev);
err_out:
	return ret;
}

static void
dtu_pci_remove(struct pci_dev *pdev)
{
	struct drm_device *ddev = pci_get_drvdata(pdev);

	drm_dev_unregister(ddev);
	drm_dev_unref(ddev);
	pci_disable_device(pdev);
	pci_set_drvdata(pdev, NULL);
}

static void
dtu_pci_shutdown(struct pci_dev *pdev)
{
	TODO
}

static struct pci_driver dtu_pci_driver = {
	.name = DRIVER_NAME,
	.id_table = did_list,
	.probe = dtu_pci_probe,
	.remove = dtu_pci_remove,
	.shutdown = dtu_pci_shutdown,
	/* .driver.pm = &dtu_pm_ops, */
};

int dtu_pci_init(void)
{
	return pci_register_driver(&dtu_pci_driver);
}

void dtu_pci_exit(void)
{
	pci_unregister_driver(&dtu_pci_driver);
}
