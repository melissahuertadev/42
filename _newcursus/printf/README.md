# PRINTF
> Because putnbr and putstr aren’t enough

### How does Printf work? 🤔

"Printf takes a string and input arguments, then it creates an internal buffer for constructing output string. Printf iterates through each characters of input string and copies the character to the output string. Printf only stops at "%". "%" means there is an argument to convert. Arguments are in the form of char, int, long, float, double or string. It converts it to string and appends to output buffer. If the argument is string then it does a string copy. Finally printf may reach at the end of user sting and it copies the entire buffer to the stdout file."
[+ Read more](http://www.equestionanswers.com/c/c-printf-scanf-working-principle.php)

"When printf processes its arguments, it starts printing the characters it finds in the first argument, one by one. When it finds a percent it knows it has a format specification. It goes to the next ar- gument and uses its value, printing it according to that format specification. It then returns to printing a character at a time (from the first argument)."
[+ Read more](https://www.cypress.com/file/54441/download)


*"You will mainly learn how to use variadic arguments."*

## Solving ~
---
Flow chart 1.0   
   
<img src="https://github.com/piratelicorne/42/blob/master/_newcursus/printf/img/printf-fc-0.png" width="1020px">  

<br><br>

## Testing ~
----
Testers I used :)

https://github.com/Mazoise/42TESTERS-PRINTF
https://github.com/cclaude42/PFT_2019

Tester I didn't use but it was used on my corrections 😭 and I passed it 😏

https://github.com/t0mm4rx/ftprintfdestructor

### Requirements

#### 🍙 For character
---

Those are the posible combinations

| Case  | format        | args_list       | output expected        |   
| ------|-------------- | --------------- | ---------------------- |
| 0     | %c %-4cM      | '?', 42         | <pre>? *   M</pre>     |
| 1     | %c %c         | '?', 42         | ? *                    |   
| 2     | %-3c.         | 'm'             | <pre>m  .</pre>        |
| 3     | %-11c         | 'm'             | <pre>m          .</pre>|   
| 3     | %*c.          | 5, 'm'          | <pre>    m.</pre>      |  
| 4     | %-*c.         | 5, 'm'          | <pre>m    .</pre>      |  
| 5     | %03c.         | 'f'             | 00f.                   |

Once there is % found, the order to analyze is:
1. Check if there is a '-' flag
2. Check if there is a '0' flag
3. Check the width or if there is * (next arg will take the value)
4. Check the specifier


## Learning ~
To do this project you need to understand how variadic functions and arguments work, here I'll leave a summary and resources links.


### variadic functions
---
Ordinary C functions take a fixed number of arguments, to declare a function, the arguments's data types are defined and everytime that function is called, you must supply the expected number and type of arguments.

e.g.
   ```int foo (int, char *);``` >> You must call it with two arguments, a number and a string pointer.  

But some functions perform operations that can *meaningfully* accept an unlimited number of arguments. </br>
In some cases a function can handle N number of values by operating on all of them as a block, for example, a function that allocates a one-dimensional array, without facilities for variable arguments, you would have *to define a separate function for each possible array size.* ⁉️ (nonsense)

The library function printf is an example of another class of function where **variable arguments** are useful. This function prints its arguments (which can vary in type as well as number) under the control of a format template string.

```
int pct = 37;
char filename[] = "foo.txt";
printf ("Processing of `%s' is %d%% finished.\nPlease be patient.\n",
	filename, pct);
```
Produces output like

```
Processing of `foo.txt' is 37% finished.
Please be patient.
```
**printf** accepts a pointer to char('string') and as many arguments as are needed to replace the type (%s , %d ...)

These are good reasons to define a variadic function which can handle as many arguments as the caller chooses to pass.

[+ More info](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html#Variadic-Functions)

### variadic arguments
---

Variadic function >> ```int functionName (int b, …)```
Variadic arguments >> ```…```

In C, the three dots means that there is an unknown amount of arguments, this make the code more flexible.

#### How to use?

In order to start creating a program that uses this structure you must include ```<stdarg.h>``` in the header section of your program along with the following macros so you can access all those data points:

   ```va_list``` >> to initialize the arguments pointer.  
   ```va_start``` >> this will point to the first element (of the mandatory one(s)).  
   ```va_arg``` >> this will point to the first of the optional arguments the user entered and every time it is called it will move over to the next argument.  
   ```va_end``` >> not really necessary since GCC will not even notice it, use it in order to close the list up.  

[+ Reference](https://medium.com/@SergioPietri/what-are-variadic-functions-in-c-6205e26c729f)
