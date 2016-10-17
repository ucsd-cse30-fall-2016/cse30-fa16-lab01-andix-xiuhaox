.syntax unified

.text

.align 8
.global bitAnd_ARM
.func bitAnd_ARM, bitAnd_ARM
.type bitAnd_ARM, %function

bitAnd_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------
    
    MVN r0, r0
    MVN r1, r1
    ORR r0, r0, r1
    MVN r0, r0
    
    @ (your code)

    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc



.global getByte_ARM
.func getByte_ARM, getByte_ARM
.type getByte_ARM, %function

getByte_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @ YOUR CODE GOES HERE 
    @-----------------------
    
    LSL r0, r0, #3
    LSR r1, r1, r0
    AND r0, r0, 0xFF
    
    @ (your code)
    @ put your return value in r0 here:

    @-----------------------

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

@ TO DO: Add the function definitions for all the following functions
@ logicalShift_ARM
@ bitCount_ARM
@ fitsBits_ARM
@ negate_ARM
@ isLessOrEqual_ARM

.global logicalShift_ARM
.func logicalShift_ARM, logicalShift_ARM
.type logicalShift_ARM, %function

logicalShift_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    
    LSR r2, r0, r1
    MOV r3, 0x80000000
    AND r4, r0, r3
    LSR r5, r4, r1
    LSL r6, r5, #1
    EOR r0, r2, r6
    
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.global bitCount_ARM
.func bitCount_ARM, bitCount_ARM
.type bitCount_ARM, %function

bitCount_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
       
    MOV r1, 0x11
    LSL r2, r1, 8
    //mask1 = r3
    ORR r3, r1, r2
    LSL r4, r3, #16
    //mask2 = r5
    ORR r5, r3, r4
    //sum = r6
    AND r6, r0, r5
    LSR r7, r0, #1
    AND r8, r7, r5
    ADD r6, r6, r8
    
    LSR r7, r0, #2
    AND r8, r7, r5
    ADD r6, r6, r8
    
    LSR r7, r0, #3
    AND r8, r7, r5
    ADD r6, r6, r8
    
    LSR r9, r6, #16
    ADD r6, r6, r9
   
    //update mask1
    MOV r10, 0xF
    LSL r11, r10, #8
    ORR r3, r10, r11
    
    AND r12, r6, r3
    LSR r13, r6, #4
    AND r14, r13, r3
    ADD r6, r12, r14
    
    LSR r15, r6, #8
    AND r15, r6, r15
    MOV r14, #0x3F
    AND r0, r15, r14
    
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.global fitsBits_ARM
.func fitsBits_ARM, fitsBits_ARM
.type fitsBits_ARM, %function

fitsBits_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    LSR r2, r0, #31
    MVN r3, r0
    AND r4, r2, r3
    MVN r5, r2
    AND r6, r0, r5
    ADD r7, r6, r4
    MVN r8, #0
    ADD r9, r1, r8
    MVN r0, r9
    
    
    
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.global negate_ARM
.func negate_ARM, negate_ARM
.type negate_ARM, %function

negate_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    NEG r0, r0
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.global negate_ARM
.func negate_ARM, negate_ARM
.type negate_ARM, %function

isLessOrEqual_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    LSR r3, r0, #31
    AND r2, r3, 0x01
    LSR r4, r1, #31
    AND r5, r4, 0x01
    EOR r6, r2, r5
    AND r7, r6, r2
    MVN r8, r6
    MVN r9, r1
    ADD r10, r0, r9
    LSR r11, r10, #31
    AND r12, r11, 0x01
    AND r13, r8, r12
    ORR r14, r13, r7
    MOV r0, r14
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
