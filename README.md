# school_member-management
# 학교 구성원 관리 프로그램

C++로 제작한 학교 구성원 관리 프로그램입니다.
텍스트 파일에서 학교와 구성원 정보를 읽어 객체로 저장하고,
교수·학부생·대학원생·졸업생의 정보를 출력합니다.

## 주요 기능

- 학교명, 설립 연도, 총장, 전체 구성원 수 출력
- 교수의 직급과 담당 학생 목록 출력
- 학부생의 GPA와 학기 출력
- 대학원생의 GPA와 학위 과정 출력
- 졸업생의 GPA와 졸업 연도 출력
- 구성원 ID를 이용한 정보 등록 및 조회

## 사용 기술

- C++
- 클래스, 상속, 추상 클래스와 가상 함수
- 파일 입출력 및 문자열 처리
- STL 컨테이너 `map`, `vector`
- 동적 메모리 할당과 가상 소멸자

## 파일 구성

| 파일 | 역할 |
|---|---|
| `main.cpp` | 입력 파일을 읽고 객체를 생성합니다. |
| `School.h` / `School.cpp` | 학교 정보와 구성원의 등록·조회·출력을 관리합니다. |
| `SchoolMember.h` / `SchoolMember.cpp` | 구성원 클래스와 유형별 출력 기능을 정의합니다. |
| `input.txt` | 실행에 사용할 학교 및 구성원 정보입니다. |

## 클래스 구조

```text
SchoolMember
├── Professor
└── Student
    ├── UndergraduateStudent
    ├── GraduateStudent
    └── Alumni
```

`SchoolMember`와 `Student`는 추상 클래스입니다.
`School`은 구성원 객체를 ID 기준으로 관리하며,
가상 함수 `print()`를 통해 각 유형에 맞는 정보를 출력합니다.

## 입력 예시

실행할 작업 폴더에 다음 내용의 `input.txt`를 준비합니다.
각 구역 사이에는 빈 줄을 둡니다.

```text
School:
01P,Jeonbuk National University,1947

Professors:
01P,Jung,Full,16S,19S
02P,Lee,Full,13S
09P,Hong,Associate

Students:
U,13S,Choi,3.0,2
U,16S,Oh,2.1,4
G,19S,Kang,3.7,Ph.D
A,20S,Ko,1.2,2007
```

학생 유형은 `U`가 학부생, `G`가 대학원생, `A`가 졸업생입니다.
마지막 필드는 유형에 따라 학기, 학위 과정, 졸업 연도를 의미합니다.

## 빌드 및 실행

Visual Studio의 **Developer Command Prompt**에서 실행합니다.

```bat
cl /EHsc /std:c++17 main.cpp School.cpp SchoolMember.cpp /Fe:school.exe
school.exe
```

프로그램은 현재 작업 폴더의 `input.txt`를 읽습니다.

## 실행 결과

예시 입력으로 실행해 다음 내용을 확인했습니다.

- 전체 구성원 7명 등록 및 출력
- 총장 ID를 이름으로 변환하여 출력
- 교수별 담당 학생 조회
- 담당 학생이 없는 경우 `No Student` 출력
- 학생 유형별 추가 정보와 소수점 한 자리의 GPA 출력
