@<Andi Wang A92122705 Xiuhao Wang A91082832>
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
    ORR r2, r0, r1
    MVN r0, r2
    
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
    
    LSL r1, r1, #3
    ASR r0, r0, r1
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
    
    @r0 = x, r1 = n
    ASR r2, r0, r1
    MOV r3, #1
    LSL r3, r3, #31 
    AND r4, r0, r3
    ASR r5, r4, r1
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
    
    @mask1 = r3
    ORR r3, r1, r2
    LSL r4, r3, #16
    
    @mask2 = r5
    ORR r5, r3, r4
    
    @sum = r6
    AND r6, r0, r5
    ASR r7, r0, #1
    AND r8, r7, r5
    ADD r6, r6, r8
    
    ASR r7, r0, #2
    AND r8, r7, r5
    ADD r6, r6, r8
    
    ASR r7, r0, #3
    AND r8, r7, r5
    ADD r6, r6, r8
    
    ASR r9, r6, #16
    ADD r6, r6, r9
   
    @update mask1
    MOV r7, 0xF
    LSL r8, r7, #8
    ORR r3, r7, r8
    
    @update sum
    AND r7, r6, r3
    ASR r8, r6, #4
    AND r8, r8, r3
    ADD r6, r7, r8
    
    @update r0
    ASR r7, r6, #8
    AND r7, r6, r7
    MOV r8, 0x3F
    AND r0, r7, r8
    
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
    @r2 = mask
    ASR r2, r0, #31
    MVN r3, r0
    AND r4, r2, r3
    MVN r5, r2
    AND r6, r0, r5
    ADD r7, r6, r4
    MVN r8, #0
    ADD r9, r1, r8
    ASR r7, r7, r9
    
    @negate
    NEG r2, r7
    ASR r10, r7, #31
    AND r10, r10, 0x01
    ASR r11, r2, #31
    AND r11, r11, 0x01
    ORR r10, r10, r11
    EOR r0, r10, 0x01
    
    
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

.global isLessOrEqual_ARM
.func isLessOrEqual_ARM, isLessOrEqual_ARM
.type isLessOrEqual_ARM, %function

isLessOrEqual_ARM:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    @r2=x_sign, r5=y_sign
    ASR r3, r0, #31
    AND r2, r3, 0x01
    ASR r4, r1, #31
    AND r5, r4, 0x01
    @r6 = checksign
    EOR r6, r2, r5
    @r7=check1
    AND r7, r6, r2
    
    @!checksign
    NEG r3, r6
    ADD r3, r3, #1
    ASR r4, r6, #31
    AND r4, r4, 0x01
    ASR r3, r3, #31
    AND r3, r3, 0x01
    ORR r3, r3, r4
    EOR r8, r3, 0x01
    
    @get check0
    MVN r9, r1
    ADD r10, r0, r9
    ASR r11, r10, #31
    AND r11, r11, 0x01
    AND r3, r8, r11
    ORR r4, r3, r7
    MOV r0, r4
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
