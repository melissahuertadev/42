#! /usr/bin/bash

pCPU=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vCPU=$(grep processor /proc/cpuinfo | wc -l)
lvmOut=$(cat /etc/fstab | grep -c "/dev/mapper/")
tcp=$(cat /proc/net/tcp | grep -c '^ *[0-9]\+: [0-9A-F: ]\{27\} 01 ')
users=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "link/ether" | awk '{print $2}')
sudo=$(journalctl -q _COMM=sudo | grep "COMMAND" | wc -l)

if [ $lvmOut -gt 0 ]
then
	lvm='yes'
else
	lvm='no'
fi

wall << .
        #Architecture: $(uname -a)
        #CPU physical : $pCPU
        #vCPU : $vCPU
        #Memory Usage: $(free -m | awk '/Mem:/{printf "%s/%sMB (%.2f%%)\n", $3,$2, $3/$2*100 }')
        #Disk Usage: $(df -h --total | awk '/total/{printf "%s/%s (%.2f%%)\n", $3,$2, $5 }')
        #CPU load: $(top -bn1 | awk '/Cpu/{printf "%s%%\n", $2}')
        #Last boot: $(last reboot | head -1 | awk '{print $5, $6, $7, $8}') 
        #LVM use: yes
        #Connexions TCP : $tcp ESTABLISHED
        #User log: $users
        #Network: IP $ip($mac)
        #Sudo : $sudo cmd
.