#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x588eb51a, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa39a9e2e, __VMLINUX_SYMBOL_STR(param_ops_short) },
	{ 0xce20b40, __VMLINUX_SYMBOL_STR(param_ops_long) },
	{ 0x24ff2e82, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x35f3bc20, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x590c5dd3, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x8dc1a6f6, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0x5f636e1, __VMLINUX_SYMBOL_STR(fs_bio_set) },
	{ 0x5f38cf03, __VMLINUX_SYMBOL_STR(blkdev_get_by_path) },
	{ 0xc1f54d2d, __VMLINUX_SYMBOL_STR(get_fs_type) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

