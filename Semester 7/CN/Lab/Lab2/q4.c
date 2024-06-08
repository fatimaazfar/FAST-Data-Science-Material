#include <stdio.h>

int main() {
    short num = 0x3412;

    unsigned char *bytePtr = (unsigned char *)&num;

    printf("Original number: 0x%04x\n", num);

    if (*bytePtr == 0x12 && *(bytePtr + 1) == 0x34) {
        printf("Byte ordering: Little Endian\n");
    } else if (*bytePtr == 0x34 && *(bytePtr + 1) == 0x12) {
        printf("Byte ordering: Big Endian\n");
    } else {
        printf("Byte ordering: Unknown\n");
    }

    printf("Bytes stored in memory:\n");
    for (int i = 0; i < sizeof(short); i++) {
        printf("Byte %d: 0x%02x\n", i, *(bytePtr + i));
    }

    return 0;
}