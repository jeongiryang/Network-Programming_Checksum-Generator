#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int read_input(uint8_t **input, size_t *length) {
    size_t capacity = 64;
    uint8_t *buffer = malloc(capacity);
    int ch;

    if (buffer == NULL) {
        return -1;
    }

    *length = 0;

    while ((ch = getchar()) != EOF) {
        uint8_t *next;

        if (ch == '\n') {
            break;
        }

        if (ch == '\r') {
            continue;
        }

        if (*length == capacity) {
            if (capacity > (SIZE_MAX / 2U)) {
                free(buffer);
                return -1;
            }

            capacity *= 2U;
            next = realloc(buffer, capacity);
            if (next == NULL) {
                free(buffer);
                return -1;
            }
            buffer = next;
        }

        buffer[*length] = (uint8_t)ch;
        (*length)++;
    }

    *input = buffer;
    return 0;
}

static uint8_t add_even_parity(uint8_t value) {
    uint8_t ascii = (uint8_t)(value & 0x7FU);
    unsigned int ones = 0;

    for (unsigned int bit = 0; bit < 7U; bit++) {
        if ((ascii & (uint8_t)(1U << bit)) != 0U) {
            ones++;
        }
    }

    return (uint8_t)((ascii << 1U) | (ones % 2U));
}

static uint32_t fold_carry(uint32_t sum) {
    while (sum > 0xFFFFU) {
        sum = (sum & 0xFFFFU) + (sum >> 16U);
    }

    return sum;
}

static uint16_t calculate_checksum(const uint8_t *input, size_t length) {
    uint32_t sum = 0;

    for (size_t i = 0; i < length; i += 2U) {
        uint8_t high = add_even_parity(input[i]);
        uint8_t low = 0;
        uint16_t word;

        if ((i + 1U) < length) {
            low = add_even_parity(input[i + 1U]);
        }

        word = (uint16_t)(((uint16_t)high << 8U) | low);
        sum += word;
        sum = fold_carry(sum);
    }

    return (uint16_t)(~fold_carry(sum) & 0xFFFFU);
}

static void print_binary16(uint16_t value) {
    for (int bit = 15; bit >= 0; bit--) {
        putchar((value & (uint16_t)(1U << bit)) != 0U ? '1' : '0');
    }
    putchar('\n');
}

int main(void) {
    uint8_t *input = NULL;
    size_t length = 0;
    uint16_t checksum;

    if (read_input(&input, &length) != 0) {
        return 1;
    }

    checksum = calculate_checksum(input, length);
    print_binary16(checksum);

    free(input);
    return 0;
}
