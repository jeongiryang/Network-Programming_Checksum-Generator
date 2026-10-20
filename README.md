# 16-bit Checksum Generator

입력 문자열에 even parity를 붙이고, 16-bit 1의 보수 덧셈으로 checksum을 계산하는 C 프로그램입니다.

![C](https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=c&logoColor=black)
![Standard Library](https://img.shields.io/badge/Dependencies-C%20Standard%20Library-555555?style=flat-square)

[실행](#실행) · [알고리즘](#계산-규칙) · [소스](main.c) · [기존 테스트](tests/run_tests.sh) · [과제 보고서](#과제-보고서)

## 실행

저장소 루트에서 C11 컴파일러로 빌드합니다.

```bash
gcc -std=c11 -Wall -Wextra -Werror main.c -o checksum
echo "abc" | ./checksum
```

```text
0111011000111001
```

프로그램은 checksum 이진 문자열 한 줄을 출력합니다.

## 계산 규칙

1. 첫 입력 줄의 각 문자를 7-bit ASCII로 읽습니다.
2. 오른쪽에 even parity bit를 붙여 8-bit 값으로 만듭니다.
3. 두 값을 16-bit word로 묶습니다. 홀수 길이면 오른쪽을 8-bit `0`으로 채웁니다.
4. carry를 다시 더하는 1의 보수 덧셈 후, 합계의 1의 보수를 출력합니다.

| 입력 | 출력 |
| --- | --- |
| `abc` | `0111011000111001` |
| `A` | `0111110111111111` |
| `AB` | `0111110101111011` |

## 테스트

기존 Bash 테스트는 위 3개 입력을 컴파일·실행해 예상 출력과 비교합니다.

```bash
bash tests/run_tests.sh
```

## 과제 보고서

<details>
<summary>기존 과제 보고서 펼치기</summary>

# Network-Programming_Checksum-Generator

## 과제 개요

네트워크프로그래밍 HW02 과제입니다.

입력 문자열을 기반으로 각 문자를 8bit 값으로 변환하고, 16bit 단위로 checksum을 계산하는 C 프로그램을 작성합니다.

## 과제 요구사항

### Input

- Alphabet(대문자, 소문자)과 숫자로 이루어진 문장을 입력
- 문장 길이는 정해져 있지 않음
- 예: `abc`

### Character 변환 조건

- 입력된 각 character를 8bit 값으로 변환
- ASCII 값은 7bit이므로, even parity bit를 추가해 8bit로 변환
- Even parity는 오른쪽에 추가함

### Checksum 계산 조건

- Checksum 계산 시, 16bit 단위로 떨어지지 않는 데이터는 오른쪽에 8bit를 `0`으로 추가해 계산함
- `A`만 입력되면 `A0`라고 가정하고 계산함
- 16bit를 단위로 checksum 계산 후 결과값을 출력함

### 출력 예시

```text
0111011000111001
```

### 구현 및 제출 조건

- C 프로그래밍 언어로 작성
- 구름 플랫폼을 통해 제출
- 제출 기한: 5월 31일 오후 11:55까지

## 알고리즘 요약

1. 표준 입력에서 첫 줄 전체를 읽고, `\n`은 입력 데이터에서 제외합니다.
2. Windows CRLF 입력을 고려해 `\r`은 무시합니다.
3. 각 문자를 7bit ASCII 값으로 처리합니다.
4. 7bit ASCII 값의 `1` 개수를 센 뒤, even parity가 되도록 오른쪽에 parity bit를 붙여 8bit 값으로 변환합니다.
5. 변환된 8bit 값 2개를 묶어 16bit word를 만듭니다.
6. 마지막 8bit 값이 하나만 남으면 오른쪽에 8bit `0`을 붙여 16bit word를 만듭니다.
7. 16bit 1의 보수 덧셈 방식으로 모든 word를 더합니다.
8. 덧셈 중 carry가 발생하면 하위 16bit에 다시 더합니다.
9. 최종 합계의 1의 보수를 계산해 16bit 이진 문자열로 출력합니다.

## 컴파일 방법

```bash
gcc -std=c11 -Wall -Wextra -Werror main.c -o checksum
```

## 실행 방법

```bash
echo "abc" | ./checksum
```

출력은 16bit checksum 이진 문자열 한 줄만 나와야 합니다.

```text
0111011000111001
```

불필요한 안내 문구, 디버그 출력, 프롬프트 출력은 넣지 않습니다.

## 테스트 방법

```bash
bash tests/run_tests.sh
```

테스트 스크립트는 `main.c`를 컴파일한 뒤 필수 예시를 자동으로 확인합니다.

## Goorm 제출 방법

구름에는 최종적으로 루트 디렉터리의 `main.c` 파일만 제출합니다.

`main.c`는 C 표준 라이브러리만 사용하며, 단일 파일로 컴파일 및 실행될 수 있도록 작성되어 있습니다.

## 제출 파일

구름에는 최종적으로 `main.c` 파일을 제출합니다.

## 진행 기록

- Initial commit: 과제 요구사항 정리 및 기본 파일 구조 생성
- Feature commit: HW02 checksum 알고리즘 구현 및 테스트 스크립트 추가

</details>
