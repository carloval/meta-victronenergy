DESCRIPTION = "Generic Victron image"

IMAGE_INSTALL = "packagegroup-core-boot packagegroup-base packagegroup-venus-base packagegroup-venus-machine ${ROOTFS_PKGMANAGE_BOOTSTRAP} ${CORE_IMAGE_EXTRA_INSTALL}"
IMAGE_INSTALL += "packagegroup-ve-console-apps"
IMAGE_FEATURES += "package-management ssh-server-openssh"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_NAME = "${IMAGE_BASENAME}-${MACHINE}-${DATETIME}-${DISTRO_VERSION}"

IMAGE_ROOTFS_SIZE = "327680"
IMAGE_ROOTFS_SIZE_raspberrypi2 = "512000"
