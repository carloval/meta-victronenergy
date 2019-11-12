SOC_FAMILY = "rpi"
include conf/machine/include/soc-family.inc

WKS_FILE ?= "sdimage-raspberrypi.wks"

RPI_KERNEL_DEVICETREE_OVERLAYS ?= ""
RPI_KERNEL_DEVICETREE ?= ""

KERNEL_DEVICETREE ?= " \
    ${RPI_KERNEL_DEVICETREE} \
    ${RPI_KERNEL_DEVICETREE_OVERLAYS} \
"

KERNEL_PACKAGES ?= "kernel-image kernel-modules"
KERNEL_IMAGETYPE ?= "zImage"
UBOOT_BINARY ?= "u-boot.bin"

MACHINE_FEATURES += "apm usbhost keyboard vfat ext2 screen touchscreen alsa bluetooth wifi sdio ${@bb.utils.contains('DISABLE_VC4GRAPHICS', '1', '', 'vc4graphics', d)}"

# Raspberry Pi has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

IMAGE_BOOT_FILES ?= " \
    bcm2835-bootfiles/* \
    config.txt \
    ${KERNEL_DEVICETREE} \
    ${UBOOT_BINARY} \
"

do_image_wic[depends] += " \
    bcm2835-bootfiles:do_deploy \
    virtual/bootloader:do_deploy \
"

do_image_wic[recrdeps] = "do_deploy"
