sudo mkdir ssh-vnc 
cd /home/asymmetrica/ssh-vnc/

sudo wget https://downloads.remote.it/remoteit/v5.1.1/remoteit-5.1.1.arm64.jetson.deb
sudo dpkg -i remoteit-5.1.1.arm64.jetson.deb

sudo wget https://www.nomachine.com/free/arm/v8/deb -O nomachine.deb
sudo dpkg -i nomachine.deb

sudo wget https://archive.raspberrypi.org/debian/pool/main/r/realvnc-vnc/realvnc-vnc-server_7.5.1.50075_arm64.deb
sudo wget https://archive.raspberrypi.org/debian/pool/main/r/realvnc-vnc/realvnc-vnc-viewer_7.5.1.50075_arm64.deb

sudo dpkg -i realvnc-vnc-server_7.5.1.50075_arm64.deb
sudo dkpg -i realvnc-vnc-viewer_7.5.1.50075_arm64.deb