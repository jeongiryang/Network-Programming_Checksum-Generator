#!/usr/bin/env bash

set -euo pipefail

gcc -std=c11 -Wall -Wextra -Werror main.c -o checksum

run_case() {
    local input="$1"
    local expected="$2"
    local actual

    actual="$(printf '%s\n' "$input" | ./checksum)"

    if [[ "$actual" != "$expected" ]]; then
        echo "FAIL: input=$input"
        echo "expected: $expected"
        echo "actual:   $actual"
        exit 1
    fi
}

run_case "abc" "0111011000111001"
run_case "A" "0111110111111111"
run_case "AB" "0111110101111011"

echo "All tests passed."
