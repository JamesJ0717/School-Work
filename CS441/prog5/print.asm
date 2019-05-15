.constant TERM 0x4000

.address 0x2000

# print_str(!hello)
    MOVI r140 = !hello
    ADD  r141 = PC + 2
    BRA [!print_str]

# print_str(!CRLF)
    MOVI r140 = !CRLF
    ADD  r141 = PC + 2
    BRA [!print_str]

!inf
    BRA [!inf]

#############################
# r140: address of the string to print
# r141: return address
# r142: char loading
#############################
!print_str
    LOAD r142 = [r140] 
    BRAE [!found_null], r142 == r0
    STOR [TERM] = r142
    INC r140
    BRA [!print_str]
!found_null 
    BRA [r141]

#############################
!hello 
    "Hello, World!"
    'Hello, World!'

!CRLF
    0xd 0xa 0