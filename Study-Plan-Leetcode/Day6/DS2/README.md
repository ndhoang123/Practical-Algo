# Note
- If you want to calculate the number from the char, the operation will help you to do it:
```
char a = '1';
int c = a - '0' // this operation will show you the integer value wanting to retrieve from the char.
```
- Otherwise, if you want to convert the num to char:
```
int holder = 1;
char ans = (char)(holder % 10 + '0'); // this operation will help you to take the interger value from char value.
```