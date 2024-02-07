sudo mkdir VCAnx
cd /home/asymmetrica/VCAnx/

sudo wget https://updates.networkoptix.com/metavms/5.1.2.37996/arm/metavms-client-5.1.2.37996-linux_arm64.deb
sudo wget https://updates.networkoptix.com/metavms/5.1.2.37996/arm/metavms-server-5.1.2.37996-linux_arm64.deb

sudo dpkg -i metavms-client-5.1.2.37996-linux_arm64.deb
sudo dpkg -i metavms-server-5.1.2.37996-linux_arm64.deb

sudo systemctl daemon-reload 

sudo systemctl enable networkoptix-metavms-mediaserver.service
sudo systemctl start networkoptix-metavms-mediaserver.service
sudo systemctl status networkoptix-metavms-mediaserver.service

sudo systemclt enable networkoptix-metavms-root-tool.service
sudo systemclt start networkoptix-metavms-root-tool.service
sudo systemclt status networkoptix-metavms-root-tool.service