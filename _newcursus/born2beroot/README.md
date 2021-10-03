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

### SELinux | Security-Enhanced Linux
> "SELinux is a security architecture for Linux® systems that allows administrators to have more control over who can access the system. (applications, processes, and files)"
[+ Read more](https://www.redhat.com/en/topics/linux/what-is-selinux)


### AppArmor
> AppArmor is an effective and easy-to-use Linux application security system. AppArmor proactively protects the operating system and applications from external or internal threats, even zero-day attacks, by enforcing good behavior and preventing both known and unknown application flaws from being exploited.

[A comparison of AppArmor and SELinux](https://www.redhat.com/sysadmin/apparmor-selinux-isolation)

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

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/hostname.png" alt="install hostname" width="680"/><br/>


Create 2 partition disks:

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/partition-disks.png" alt="install partition" width="680"/><br/>


partition | size | use as
--- | --- | ---
root | 2G | Ext4 (mount: /)
swap | 1G | swap area
home | 1G | Ext4 (mount: /home)
var | 1G | Ext4 (mount: /var)
srv | 1G | Ext4 (mount: /srv)
tmp | 1G | Ext4 (mount: /tmp)
var-log | all disk space that left | Ext4 (manually mount: /var/log)

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/encr-volumes-1.png" alt="encryption volumes" width="560"/>    <img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/lsblk_results.png" alt="lsblk results" width="560"/><br/>

### Requirements

**General**
- [x] A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.
  
> SSH stands for Secure Shell. SSH is used for connecting to a remote computer accessing files and perform administrative tasks.

```
$ sudo apt install openssh-server
$ sudo nano /etc/ssh/sshd_config
$ sudo service ssh status
$ sudo systemctl restart ssh
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/sshd_config.png" alt="lsblk results" width="560"/><br/>

[SSH configuration](https://phoenixnap.com/kb/how-to-enable-ssh-on-debian)
<br/>


- [x] You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.

> UFW (Uncomplicated Firewall) is a user-friendly front-end for managing iptables firewall rules. Its main goal is to make managing iptables easier or, as the name says, uncomplicated

```
$ sudo apt install ufw
$ sudo ufw status
$ sudo ufw allow 4242
$ sudo ufw enable
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/ufw.png" alt="ufw results" width="560"/><br/>

[+ UFW configuration](https://linuxize.com/post/how-to-setup-a-firewall-with-ufw-on-debian-10/)
<br/>

- [x] Implement a strong password policy. (check process above ⬇️⬇️)
- [x] Install and configure sudo following strict rules. (check process above ⬇️⬇️)
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

<br/>

- [x] Create a script ```monitoring.sh```


----
<br/>

**Password policy:**

> PAM (Pluggable Authentication Modules) module to check password strength: ```libpwquality```'s purpose is to provide common functions for password quality checking and also scoring them based on their apparent randomness. The library also provides a function for generating random passwords with good pronounceability.

[+ Read more](https://ostechnix.com/force-users-use-strong-passwords-debian-ubuntu/)


```
$ sudo apt -y install libpam-pwquality
```

- [x] Your password has to expire every 30 days.
- [x] The minimum number of days allowed before the modification of a password will be set to 2.
- [x] The user has to receive a warning message 7 days before their password expires.

To modify the parameters mentioned above, we need to edit the file `login.defs` by:
```
$ sudo nano /etc/login.defs
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/passw_policy-1.png" alt="password policy" width="580"/><br/>


- [x] Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
- [x] The password must not include the name of the user. ⚠️ Add ```reject_username``` at the end of the file.
- [x] The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password. Of course, your root password has to comply with this policy. ⚠️ Also uncomment the line ```enforce_for_root``` at the end of the file.

To modify the parameters mentioned above, we need to edit the file `pwquality.conf` by:
```
$ sudo nano /etc/security/pwquality.conf
```
<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/passw_policy-2.png" alt="password policy" width="580" class="center"/>

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/passw_policy-3.png" alt="password policy" width="580" class="center"/>

[More commands](https://www.server-world.info/en/note?os=Debian_10&p=password)

----
<br/>

**Sudo group:**

> Sudo (sometimes considered as short for Super-user do) is a program designed to let system administrators allow some users to execute some commands as root (or another user). The basic philosophy is to give as few privileges as possible but still allow people to get their work done. Sudo is also an effective way to log who ran which command and when.

- [x] Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
- [x] A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
- [x] Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
- [x] The TTY mode has to be enabled for security reasons.
- [x] For security reasons too, the paths that can be used by sudo must be restricted. Example: ```/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin```

To modify the parameters mentioned above, we need to edit the `sudoers` file by:
```
$ sudo visudo
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/sudo_config.png" alt="sudo config" width="580" class="center"/>

[Sudo insults](https://www.tecmint.com/sudo-insult-when-enter-wrong-password/)


⚠️ Switching to root using ```sudo -i``` (or ```sudo su```) is usually deprecated because it cancels the below features:
- Nobody needs to know the root password (sudo prompts for the current user's password). Extra privileges can be granted to individual users temporarily, and then taken away without the need for a password change.
- It's easy to run only the commands that require special privileges via sudo; the rest of the time, you work as an unprivileged user, which reduces the damage that mistakes can cause.
- Auditing/logging: when a sudo command is executed, the original username and the command are logged.

----
<br/>

**Script ```monitoring.sh```**

> [wall](https://www.geeksforgeeks.org/wall-command-in-linux-with-examples/) 

- [x] It must be developed in bash. At server startup, the script will display some information (listed below) on all terminals every 10 minutes. No error must be visible.
- [x] Your script must always be able to display the following information:
  - [x] The architecture of your operating system and its kernel version.
  - [x] The number of physical processors.
  - [x] The number of virtual processors.
  - [x] The current available RAM on your server and its utilization rate as a percentage.
  - [x] The current available memory on your server and its utilization rate as a percentage
  - [x] The current utilization rate of your processors as a percentage.
  - [x] The date and time of the last reboot.
  - [x] Whether LVM is active or not.
  - [x] The number of active connections.
  - [x] The number of users using the server.
  - [x] The IPv4 address of your server and its MAC (Media Access Control) address.
  - [x] The number of commands executed with the sudo program.

[CPU](https://developpaper.com/how-to-view-the-physical-cpu-logical-cpu-and-cpu-number-of-linux-servers/)
[vCPU](https://webhostinggeeks.com/howto/how-to-display-the-number-of-processors-vcpu-on-linux-vps/)
[LVM partitions](https://askubuntu.com/questions/202613/how-do-i-check-whether-i-am-using-lvm)
[TCP connections](https://serverfault.com/questions/646729/get-number-of-tcp-established-connections?noredirect=1&lq=1)
[Sudo commands](https://unix.stackexchange.com/questions/167935/details-about-sudo-commands-executed-by-all-user)

We'd need a task scheduler as [CRON](https://linuxhint.com/schedule_linux_task/)
<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/crontab.png" alt="crontab" width="580" class="center"/>

## Testing ~

- The use of SSH by setting up a new account.
- Creation of a new user and assign it to a group.
- Explain how this script works, interrupt it without modifying it.
