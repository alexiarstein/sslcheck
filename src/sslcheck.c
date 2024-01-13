// SSL CHECKER v1.0.1
// Autora: Alexia Michelle Steinberg <alexia@rockylinux.org>
// -------------------------------------------------------
// Notas:
// Requiere LibSSL (sudo apt install libssl-dev (debian) sudo dnf install openssl-devel (RockyLinux/CentOS/Fedora et al)) 
// compilar (gcc) con argumentos -lssl -lcrypto (e.g: gcc sslcheck -o sslcheck -lssl -lcrypto)
// Licencia: GNU GPL 3.0 (ver LICENSE para mas info)
// to do: regional settings (English Translation)
// USO: ./sslcheck example.com 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>


// defini el buffer size
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <dominio>\n", argv[0]);
        return 1;
    }

    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        fprintf(stderr, "SSL_CTX_new error\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (!server) {
        fprintf(stderr, "gethostbyname error\n");
        return 1;
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(443);
    memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        return 1;
    }

    SSL *ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "SSL_new error\n");
        return 1;
    }

    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return 1;
    }

    X509 *cert = SSL_get_peer_certificate(ssl);
    if (!cert) {
        fprintf(stderr, "SSL_get_peer_certificate error\n");
        return 1;
    }

    ASN1_TIME *expire_time = X509_get_notAfter(cert);
    struct tm expire_tm;
    memset(&expire_tm, 0, sizeof(expire_tm));
    ASN1_TIME_to_tm(expire_time, &expire_tm);
    time_t expire = mktime(&expire_tm);
    time_t current_time = time(NULL);
    int diff_in_days = (expire - current_time) / (60 * 60 * 24);

    //printf("Dominio: %s ", argv[1]);
    printf("Dominio: %s | Días restantes hasta expirar: %d\n", argv[1], diff_in_days);

    X509_free(cert);
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}
