# INIT
> Initiation to System and Network Administration

## Instructions

|  | Description |
| ----------- | ----------- |
| Part 1 | Network |
| Part 2 | System* |
| Part 3 | Scripting* |

*must be done on a Debian virtual machine.

## Commands
`ping` send packets of data
 + Put a delay in your pings << `ping -i 5 192.168.210.1`
 + Ping the hostname 5 times and then stop the ping << `ping -c 5 google.com`
 + Flood ping the host << `ping -f localhost`
 + Set the packet size during your ping << `ping -s 100 google.com`

`ifconfig`: Configure network interface parameters. The ifconfig utility is used to assign an address to a network interface and/or configure network interface parameters; display, change your MAC address, {en0: ethernet connection, en1: wireless network, fw: fireware connection}

`netstat`: network information. `-r`: access to the ip address of the router
 + View information on all sockets >> `netstat -at`
 + View network information for ipv6 >> `netstat -lt`


## Sources:
https://gist.github.com/jjnilton/add1eeeb3a9616f53e4c
https://ss64.com/osx/ifconfig.html
