// SSLCHECK - A simple tool to check for the remainder
// of life of a TLS/SSL Certificate
// USAGE: sslcheck domain.com (e.g: sslcheck goldendoglinux.org)
// Author: Alexia Michelle <alexia@goldendoglinux.org>
// LICENSE: GNU GPL 3.0 (See LICENSE for more info)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <locale.h>
#include <libintl.h>

#define SSLCHECK_VERSION "1.0"
#define AUTHOR "Alexia Michelle <alexia@goldendoglinux.org>"

#ifdef __APPLE__
    #define BUILD_OS "macOS"
#elif __linux__
    #define BUILD_OS "Linux"
#else
    #define BUILD_OS "Unknown OS"
#endif



#define _(STRING) gettext(STRING)

int days_until_expiration(X509 *cert) {
    const ASN1_TIME *notAfter = X509_get0_notAfter(cert);

    ASN1_TIME *asn1_now = ASN1_TIME_new();
    ASN1_TIME_set(asn1_now, time(NULL));

    int days = 0, seconds = 0;
    if (!ASN1_TIME_diff(&days, &seconds, asn1_now, notAfter)) {
        fprintf(stderr, _("Error al calcular la diferencia de tiempo\n"));
        ASN1_TIME_free(asn1_now);
        return -1;
    }

    ASN1_TIME_free(asn1_now);
    return days;
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain("sslcheck", "/usr/local/share/locale");
    textdomain("sslcheck");

    if (argc == 2 && (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)) {
        printf(_("SSLCHECK v%s\n"), SSLCHECK_VERSION);
        printf(_("Author: %s\n"), AUTHOR);
        printf(_("Built for: %s\n"), BUILD_OS);
        return EXIT_SUCCESS;
    }


    if (argc != 2) {
        fprintf(stderr, _("Uso: %s <dominio>\n"), argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *port = "443";

    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    const SSL_METHOD *method = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    if (!ctx) {
        fprintf(stderr, _("Error al crear el contexto SSL\n"));
        return EXIT_FAILURE;
    }

    SSL *ssl = SSL_new(ctx);
    BIO *bio;
    char target[512];
    snprintf(target, sizeof(target), "%s:%s", hostname, port);

    bio = BIO_new_ssl_connect(ctx);
    BIO_get_ssl(bio, &ssl);
    if (!ssl) {
        fprintf(stderr, _("Error al obtener objeto SSL\n"));
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    SSL_set_tlsext_host_name(ssl, hostname);
    BIO_set_conn_hostname(bio, target);

    if (BIO_do_connect(bio) <= 0) {
        fprintf(stderr, _("Error al conectar con %s\n"), hostname);
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    X509 *cert = SSL_get_peer_certificate(ssl);
    if (!cert) {
        fprintf(stderr, _("No se pudo obtener el certificado de %s\n"), hostname);
        BIO_free_all(bio);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    int days = days_until_expiration(cert);
    if (days >= 0) {
        printf(_("Dominio: %s | Días hasta que expire el Cert: %d\n"), hostname, days);
    } else {
        fprintf(stderr, _("No se pudo calcular la fecha de expiración\n"));
    }

    X509_free(cert);
    BIO_free_all(bio);
    SSL_CTX_free(ctx);
    EVP_cleanup();
    ERR_free_strings();

    return EXIT_SUCCESS;
}
