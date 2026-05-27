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

## 제출 파일

구름에는 최종적으로 `main.c` 파일을 제출합니다.

## 진행 기록

- Initial commit: 과제 요구사항 정리 및 기본 파일 구조 생성
