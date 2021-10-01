# BORN 2 BE ROOT
> Introduction to the wonderful world of virtualization.

### What to do? 🤔

To set up a server with the minimum of services, ⚠️ a graphical interface is of no use here.

- The use of VirtualBox (or UTM if you can’t use VirtualBox) is mandatory.
- For a OS: choose either the latest stable version of Debian (no testing/unstable), or the latest stable version of CentOS.
- Create at least 2 encrypted partitions using LVM
- SELinux must be running at startup and its configuration has to be adapted for the project’s needs. AppArmor for Debian must be running at startup too.

[1. Notes](#Notes)   
[2. Evaluation](#Evaluation)   
[3. Solving](#Solving)   

# Notes

## SELinux | Security-Enhanced Linux
"SELinux is a security architecture for Linux® systems that allows administrators to have more control over who can access the system. (applications, processes, and files)"
[+ Read more](https://www.redhat.com/en/topics/linux/what-is-selinux)


## AppArmor   
<br/>
   
# Evaluation ~
- Questions about the operating chosen (the differences between aptitude and apt, or what SELinux or AppArmor is).
- Modification of the hostname.
- Creation of a new user and assign it
to a group.
- The use of SSH will be tested during the defense by setting up a new account.
- Explain how this script works. Interrupt it without modifying it.


# Solving ~

- [x] The hostname of your virtual machine must be your login ending with 42 ```(mhuerta42)```.
  
Name and OS: ```"born2beroot"  Linux-Debian(64-bit)```  
Hard disk file type: ```VDI```  
Storage and physical hard disk: ```Dynamically allocated```  

### Installation & Setting up

```
hostname: mhuerta42
domain name: (empty)
username: mhuerta
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/hostname.png" alt="install hostname" width="200"/>

![install hostname](https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/hostname.png)

Create 2 partition disks:

![install partition](https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/partition-disks.png)


partition | size | use as
--- | --- | ---
root | 2G | Ext4 (mount: /)
swap | 1G | swap area
home | 1G | Ext4 (mount: /home)
var | 1G | Ext4 (mount: /var)
srv | 1G | Ext4 (mount: /srv)
tmp | 1G | Ext4 (mount: /tmp)
var-log | all disk space that left | Ext4 (manually mount: /var/log)

![encryption volumes](https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/encr-volumes-1.png)

![encryption volumes mounted](https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/encr-volumes-2.png)

![encryption volumes mounted](https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/lsblk_results.png)


### Requirements

**General**
- [x] A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.
```
$ sudo apt install openssh-server
$ sudo nano /etc/ssh/sshd_config
$ sudo service ssh status
$ sudo systemctl restart ssh
```

![sshd_config](https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/sshd_config.png)
<br/><br/>


- [ ] You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.

<br/><br/>
- [ ] Implement a strong password policy.
- [ ] Install and configure sudo following strict rules.
- [x] In addition to the root user, a user with your login as username has to be present. This user has to belong to the user42 and sudo groups.
```
$ su -l
$ su - root
```
To add the user ```mhuerta``` into the ```sudo``` group:
```
$ usermod -aG sudo mhuerta
OR
$ sudo adduser mhuerta sudo
```
To check all the users that belongs to the ```sudo``` and ```user42``` groups:
```
$ getent group sudo
$ getent group user42
```

To check all the groups the current user belongs to:
```
$ groups
```

[Read about sudo](https://wiki.debian.org/sudo/)  
[Read about sudo users](https://phoenixnap.com/kb/create-a-sudo-user-on-debian)   
[Read about sudo vs su](https://phoenixnap.com/kb/sudo-vs-su-differences)

<br/><br/>


- [ ] Create a script ```monitoring.sh```



  



**Password policy:**

- [ ] Your password has to expire every 30 days.
- [ ] The minimum number of days allowed before the modification of a password will be set to 2.
- [ ] The user has to receive a warning message 7 days before their password expires.
- [ ] Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
- [ ] The password must not include the name of the user.
- [ ] The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password. Of course, your root password has to comply with this policy.

**Sudo group:**
- [ ] Authentication using sudo has to be limited to 3 attempts in the event of an incor- rect password.
- [ ] A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
- [ ] Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
- [ ] The TTY mode has to be enabled for security reasons.
- [ ] For security reasons too, the paths that can be used by sudo must be restricted. Example: ```/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin```

**Script ```monitoring.sh```**
- [ ] It must be developed in bash. At server startup, the script will display some information (listed below) on all terminals every 10 minutes. No error must be visible.
- [ ] Your script must always be able to display the following information:
  - [ ] The architecture of your operating system and its kernel version.
  - [ ] The number of physical processors.
  - [ ] The number of virtual processors.
  - [ ] The current available RAM on your server and its utilization rate as a percentage.
  - [ ] The current available memory on your server and its utilization rate as a percentage
  - [ ] The current utilization rate of your processors as a percentage.
  - [ ] The date and time of the last reboot.
  - [ ] Whether LVM is active or not.
  - [ ] The number of active connections.
  - [ ] The number of users using the server.
  - [ ] The IPv4 address of your server and its MAC (Media Access Control) address.
  - [ ] The number of commands executed with the sudo program.


## Learning ~

## Testing ~

- The use of SSH by setting up a new account.
- Creation of a new user and assign it to a group.
- Explain how this script works, interrupt it without modifying it.
