# 42 Project : Libft

Libft is the first project when you entered 42: you have to re-create some standard C library functions including some additional ones that can be used later to build a library of useful functions for the rest of the program.

Disclaimer: *Reinventing the wheel is bad, 42 makes us do this just so we can have a deeper understanding of data structures and basic algorithms. At 42 we're not allowed to use some standard libraries on our projects, so we have to keep growing this library with our own functions as we go farther in the program.*

## List of functions

Libc & additional functions :

+ **"INT"**
atoi.c itoa.c ft_itoa_ull.c ft_itoa_ull_base.c

+ **"CHAR"**
isalnum.c isalpha.c isascii.c isdigit.c
isprint.c tolower.c toupper.c

+ **"STR"**
ft_split.c strchr.c ft_strcpy.c strdup.c
strjoin.c strlcat.c strlcpy.c strlen.c
strmapi.c strncmp.c strnstr.c strrchr.c
strtrim.c substr.c

+ **"MEM"**
bzero.c calloc.c ft_memalloc.c memccpy.c
memchr.c memcmp.c memcpy.c memmove.c
memset.c

+ **"PUT"**
putchar_fd.c putendl_fd.c putnbr_fd.c putstr_fd.c

Linked list functions (bonus) :

+ **"LST"**
lstadd_back.c lstadd_front.c lstclear.c lstdelone.c
lstiter.c lstlast.c lstmap.c lstnew.c
lstsize.c

## Usage

Download the project and create the library :
```
  git clone https://github.com/slabelle42/libft.git
  cd libft
  make
```

With linked list functions :
```
  make bonus
```

## More

This is [42](https://www.42.fr/).
