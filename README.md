# Edge Computing Video Boards

> NVIDIA P3541

- name: Asymmetrica
- hostname: asymmetrica-nvidia-p3541
- username: asymmetrica

- Setup Guide --> [https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-2gb-devkit#intro]
- Firmware Image --> [https://developer.nvidia.com/jetson-nano-2gb-sd-card-image]


> AUVIDEA JNX30D
- Setup Guide --> [https://auvidea.eu/download/Software]
- Firmware Version --> [https://auvidea.eu/firmware/]
- Firmware Image --> [https://auvidea.eu/download/firmware/Jetpack_4.6/Jetpack_4_6_TX2NX_JNX30.tar.bz2]

Download & Installation
```
tar xvzf bootloader.tar.gz
cd ./bootloader
lsusb
sudo bash ./flashcmd.txt
```

>  PATRIOT P300

- name: Asymmetrica
- hostname: patriot-p300
- username: asymmetrica

- Setup Guide --> [https://wiki.seeedstudio.com/reComputer_J1020_A206_Flash_JetPack/#flashing-jetpack-os-via-command-line]
- Firmware Image --> [https://developer.nvidia.com/downloads/embedded/l4t/r32_release_v7.4/t210/jetson-210_linux_r32.7.4_aarch64.tbz2]
- Filesystem --> [https://developer.nvidia.com/downloads/embedded/l4t/r32_release_v7.4/t210/tegra_linux_sample-root-filesystem_r32.7.4_aarch64.tbz2]

Packages & IMG Creation
```
tar xf jetson-210_linux_r32.7.4_aarch64.tbz2
cd Linux_for_Tegra/rootfs/
sudo tar xpf ../../tegra_linux_sample-root-filesystem_r32.7.4_aarch64.tbz2
cd ..
sudo ./apply_binaries.sh
```

Mounting IMG & Installation
```
sudo ./flash.sh jetson-nano-devkit-emmc mmcblk0p1
```
