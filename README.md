# Embedded RTOS Project

[임베디드 OS 개발 프로젝트] 책을 따라가며 ARM 기반 RTOS를 직접 구현하고 동작 원리를 학습한 프로젝트입니다.  
QEMU의 RealViewPB 보드를 기반으로 부팅부터 태스크 스케줄링까지 직접 구현하며, 임베디드 시스템과 운영체제의 기초를 공부했습니다.

---

## 프로젝트 목표

- ARMv7-A 기반 시스템의 부팅 과정 이해
- 메모리 맵 및 익셉션 벡터 테이블 구성
- UART 드라이버 구현 및 printf 동작 원리 학습
- 인터럽트 및 타이머 제어
- 태스크(Task) 및 스케줄러 구현
- 컨텍스트 스위칭(Context Switching) 이해
- RTOS의 기본 구조와 동작 방식 학습

---

## 개발 환경

- ARM Cortex-A8
- QEMU RealViewPB
- arm-none-eabi-gcc
- GDB
- Ubuntu Linux

---

## 학습 내용

### ARM 아키텍처

- ARM CPU 모드(SVC, IRQ, SYS 등)
- CPSR / SPSR 레지스터
- Stack Pointer 및 Link Register 동작
- Exception / Interrupt 처리 과정

### 부팅 과정

- Reset Vector
- Exception Vector Table 구성
- Stack 초기화
- Main 함수 진입 과정

### 실행 파일 및 빌드 시스템

- ELF 파일 구조
- Linker Script 작성
- Makefile 기반 빌드 자동화
- ABI / EABI 개념 학습

### UART

- UART 레지스터 직접 제어
- 문자 송수신 구현
- printf 직접 구현

### 인터럽트 & 타이머

- GIC(Generic Interrupt Controller) 초기화
- IRQ 처리
- Timer Interrupt 기반 카운터 구현
- delay 함수 구현

### RTOS 핵심 기능

- Task Control Block(TCB)
- Round Robin Scheduler
- Context Switching
- Yield 기반 Cooperative Scheduling

---

## 구현 기능

- [x] UART Driver
- [x] Interrupt Controller
- [x] Timer Driver
- [x] Task Creation
- [x] Scheduler
- [x] Context Switching
- [x] Cooperative Multitasking

---

## 프로젝트 구조

```text
boot/       # 부팅 코드 및 벡터 테이블
hal/        # 하드웨어 제어 계층(UART, Timer, Interrupt)
kernel/     # Task, Scheduler, Context Switching
lib/        # printf 등 유틸리티
include/    # 공통 헤더
```

---
