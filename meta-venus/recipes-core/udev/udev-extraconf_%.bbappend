FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI += " \
	file://mount.sh \
	file://rtl8192cu.rules \
"

SRC_URI_append_beaglebone += "file://mount.blacklist.beaglebone"

# note: PRINC is needed in danny/ccgx
PRINC ?= "666000"
PRINC := "${@int(PRINC) + 4}"

do_install_append() {
	install -m 0755 ${WORKDIR}/mount.sh ${D}${sysconfdir}/udev/scripts

	if [ -e ${WORKDIR}/mount.blacklist.${MACHINE} ]; then
		install -d ${D}/${sysconfdir}/udev/mount.blacklist.d
		install -m 0644 ${WORKDIR}/mount.blacklist.beaglebone \
			${D}/${sysconfdir}/udev/mount.blacklist.d/${MACHINE}
	fi
}

do_install_append_bpp3() {
	install -m 0644 ${WORKDIR}/rtl8192cu.rules ${D}${sysconfdir}/udev/rules.d
}

do_install_append_ccgx() {
	install -m 0644 ${WORKDIR}/rtl8192cu.rules ${D}${sysconfdir}/udev/rules.d
}

FILES_${PN} = "${sysconfdir}/udev \"
