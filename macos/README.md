for ease of use I compiled it for mac (ARM SILLICON)
OpenSSL might be required (brew install openssl)


To compile on mac, install openssl and compile it this way, assuming you installed openssl via homebrew

Alexia

gcc sslcheck.c -o sslcheck \
  -I/opt/homebrew/opt/openssl@3/include \
  -L/opt/homebrew/opt/openssl@3/lib \
  -lssl -lcrypto
