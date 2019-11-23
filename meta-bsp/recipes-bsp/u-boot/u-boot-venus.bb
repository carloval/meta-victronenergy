require u-boot-venus.inc
require ${COREBASE}/meta/recipes-bsp/u-boot/u-boot.inc

DEPENDS += "bc-native dtc-native"

SRC_URI_append_rpi += "file://config.txt"

do_deploy_append_rpi() {
    install -m 640 ${WORKDIR}/config.txt ${DEPLOYDIR}/config.txt
}
