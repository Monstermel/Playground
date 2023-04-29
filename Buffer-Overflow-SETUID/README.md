#Buffer Overflow Set UID

Note: It is not guaranteed that the codes will run on your machines, since the addresses can vary

##Level 1
For this level, the solution is straightforward. Using gdb, we need to obtain the offset to the return address ($ebp - &buffer). Then, we can guess the correct value for the return address (since gdb adds variables to the stack), we have to aim for a location with a NOP operation or the shellcode.

##Level 2
For this level, we are aware that the buffer size falls within the range of a to b, then, using gdb to only get addres of buffer, we copy the return address b + c times starting on the buffer address.

##Level 3
Since 64 bits addresses start with two NULL bytes we can copy the shellcode before the return address, so it cat get within the buffer variable and then guess a proper return address

##Level 4
For this level, we can follow most of the steps taken in previous levels, but instead of targeting the shellcode in the buffer variable, we need to target the one stored in the str variable in the main function.