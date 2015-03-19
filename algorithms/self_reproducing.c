#include <stdio.h>
int main() { char dq = '"'; char program[] = "#include <stdio.h> int main() { char dq = '%c' char program[] = %c%s%c; printf(program, dq, dq, program, dq); return 0; }"; printf(program, dq, dq, program, dq); return 0; }
