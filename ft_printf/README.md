## ft_printf
Library의 printf 함수와 동일하게 동작하는 함수를 구현하기

#### ◾ 프로그램 이름
`libftprintf.a`
#### 제출할 파일
`*.c`, `*/*.c`, `*.h`, `*/*.h`, `Makefile`
#### Makefile에 포함해야 하는 규칙
all, clean, fclean, re, bonus
#### 허용된 함수
malloc, free, write, va_start, va_arg, va_copy, va_end
#### Return 값
출력된 바이트 수 (\n, \t, \b, 공백과 같은 문자 포함)
#### 세부 조건
- ft_printf의 프로토타입은 `int ft_printf(const char *, …);` 이어야 한다.
- 라이브러리의 실제 printf 함수를 recode 해야 한다.
- 원래의 printf 함수처럼 buffer를 관리하면 안 된다.
- 다음의 서식문자들을 사용할 수 있어야 한다. : `cspdiuxX%`
- 모든 서식문자에서 `-0`플래그, 폭, 정밀도의 조합을 처리해야 한다.
- 추가적인 내용은 man 3 printf / man 3 stdarg 을 참고한다.

#### 📌printf 함수 구조
👉`%[플래그(flag)][폭(width)][.정밀도][크기(length)]서식 문자(specifier)`
