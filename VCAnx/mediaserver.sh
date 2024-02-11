sudo mkdir VCAnx
cd /home/asymmetrica/VCAnx/
sudo mkdir CUDA
sudo mkdir NetOpt
cd /home/asymmetrica/VCAnx/NetOpt/

sudo wget https://updates.networkoptix.com/default/5.1.2.37996/arm/nxwitness-client-5.1.2.37996-linux_arm64.deb
sudo wget https://updates.networkoptix.com/default/5.1.2.37996/arm/nxwitness-server-5.1.2.37996-linux_arm64.deb

sudo dpkg -i nxwitness-client-5.1.2.37996-linux_arm64.deb
sudo dpkg -i nxwitness-server-5.1.2.37996-linux_arm64.deb

sudo systemctl daemon-reload 

sudo systemctl enable networkoptix-mediaserver.service
sudo systemctl start networkoptix-mediaserver.service
sudo systemctl status networkoptix-mediaserver.service

sudo systemctl enable networkoptix-root-tool.service
sudo systemctl start networkoptix-root-tool.service
sudo systemctl status networkoptix-root-tool.service