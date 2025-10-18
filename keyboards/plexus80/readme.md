Given this repo is an external QMK userspace, the keyboard.json file needs to also be copied to the local `qmk_firmware` directory:
1. Check for `qmk_firmware` location with `qmk doctor`.
2. Copy keyboard.json to the main QMK firmware directory: `cp ~/github/qmk_userspace/keyboards/plexus80/keyboard.json ~/qmk_firmware/keyboards/plexus80/`
3. Maybe copy readme too: `cp ~/github/qmk_userspace/keyboards/plexus80/readme.md ~/qmk_firmware/keyboards/plexus80/`
4. Compile: `qmk compile -kb plexus80 -km default`
5. Flash: `qmk flash -kb plexus80 -km default`


## Alternative VIA

- VIA compatible firmware (.hex file) is available at <https://github.com/npspears/VIA-Firmware/tree/main/plexus80> under an MIT license.
- The .hex file can be flashed from command line using `dfu-programmer`, as described here: <https://morphykuffour.github.io/linux/qmk/keyboards/dfu-programmer/2022/07/29/Flashing-QMK-hex-files-on-linux.html>
- Subsequently the keymap can be modified from the VIA GUI. Note that "Show Design Tab" needs to be enabled in VIA. Additionally, to load the npspears' .hex file from the Design tab, enable "Use V2 definitions" toggle.
