#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void process_file(const char *input_file, const char *output_file, const char *key, int encrypt) {
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
    if (!in || !out) {
        perror("File opening failed");
        if (in) fclose(in);
        if (out) fclose(out);
        exit(1);
    }

    size_t key_len = strlen(key);
    unsigned char buffer[1024]; // 1KB chunks
    size_t bytes_read;
    size_t key_pos = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ key[key_pos % key_len]; // XOR with key
            key_pos++;
        }
        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    int encrypt = (strcmp(argv[1], "encrypt") == 0);
    if (!encrypt && strcmp(argv[1], "decrypt") != 0) {
        printf("Mode must be 'encrypt' or 'decrypt'\n");
        return 1;
    }

    process_file(argv[2], argv[3], argv[4], encrypt);
    printf("%s complete: %s -> %s\n", encrypt ? "Encryption" : "Decryption", argv[2], argv[3]);
    return 0;
}

int main() {
    
}