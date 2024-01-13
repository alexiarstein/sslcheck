# SSL-Check

Thi is a very simple tool to check for the expiration date of a ssl certificate on a website, similar to performing an openssl s_client
but with the difference that this is much simpler for humans to read. 

If the certificate expires after today's date it shows as ACTIVE, and it shows the remainder of days until expiring.

It might not be very useful but I release it anyway, for learning purposes, in the hopes that someone might find any educational value in it. I'd like to see something nice and fun created out of this. 
It uses openssl within a C application and that could give students of the C programming language some ideas, I hope!

Feel free to expand, fix bugs or anything you wish! Please do create a new branch and send me a merge request. 

```
git clone https://github.com/alexiarstein/sslcheck.git
cd sslcheck/
git checkout -b "your-fancy-branch-name"
And commit and push to your branch. Once you are happy with the changes send me a merge request over github!
```

It is currently printing the output in Spanish, but it shouldn't be too hard to implement an array for translation and a config for language selection. Feel free to add a config to select language or hard-code the language of your choice as a fork. 

If you do use it or find it useful, you don't really have to, but I'd apprecite if you credit me. 


This is licensed under a GNU GPL 3.0 License.


### USAGE:
Instructions: 

Requires GCC and libssl 
```
Debian Ecosystem: sudo apt install libssl-dev
RockyLinux/Fedora/CentOS Stream et al: sudo dnf install openssl-devel
```
### Compiling:
```gcc sslcheck.c -o sslcheck -lssl -lcrypto```

### Usage: 
./sslcheck example.com

### Author
Alexia Rivera steinberg <alexiarstein@aol.com>
---
### Additional Notes

This is a very early release for personal use. If you want to contribute to it, please by all means do so, feel free to clone it, do your fixes, create a new branch and send me a merge request!!

```
git clone https://github.com/alexiarstein/sslcheck.git

cd sslcheck

git checkout -b "your-fancy-branch-name"

Push to your branch and then send me a merge request over github
```

For ease of use it could be moved to /usr/local/bin and set the mode excecutable for everyone
```
sudo mv sslcheck /usr/local/bin
sudo chmod a+x /usr/local/bin/sslcheck
```
