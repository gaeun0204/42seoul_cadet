## ft_printf
Library의 printf 함수와 똑같이 동작하는 함수를 구현합니다.

#### 프로그램 이름
- libftprintf.a

#### 제출할 파일
- `*.c`, `*/*.c`, `*.h`, `*/*.h`, `Makefile`

#### Makefile에 포함해야 하는 규칙
- all, clean, fclean, re, bonus

#### 허용된 함수
- malloc, free, write, va_start, va_arg, va_copy, va_end

#### Return 값
- 출력된 글자 수에 대한 바이트 수 (\n, \t, \b, 공백과 같은 문자 포함)

#### 세부 조건
- ft_printf의 프로토타입은 `int ft_printf(const char *, …);` 이어야 합니다.
- 라이브러리의 실제 printf 함수를 recode해야 합니다.
- 원래의 printf 함수처럼 buffer 관리를 하면 안 됩니다.
- 다음의 서식지정자들을 처리해야 합니다. : `cspdiuxX%`
- 모든 서식지정자에서 `-0` 플래그, 폭, 정밀도의 조합을 처리해야 합니다.
- man 3 printf / man 3 stdarg 을 참고하세요.

### printf 함수 구조
- `%[플래그(flag)][폭(width)][.정밀도][크기(length)]서식 문자(specifier)`
