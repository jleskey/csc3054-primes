.section .rodata                                    # constants
primes:                                             # primes: primes array
    .word   2, 3, 5, 7, 11, 13, 17, 19, 23, 29      # ^ int[]
count:                                              # count: number of primes
    .word   10                                      # ^ int

.data
sum:                                                # sum: final sum (TBD)
    .word   0                                       # ^ int

.text
.global main
main:
    li      t0, 0                                   # t0: temporary sum
    la      t1, primes                              # t1: prime list pointer
    lw      t2, count                               # t2: prime list index
loop:
    lw      t3, 0(t1)                               # t3: current prime
    add     t0, t0, t3                              # Update temporary sum.
    addi    t1, t1, 4                               # Go to next prime (+4 B).
    addi    t2, t2, -1                              # Decrement index.
    bnez    t2, loop                                # Loop until index is 0.
store:
    la      t1, sum                                 # t1: sum pointer
    sw      t0, 0(t1)                               # Store sum.
exit:
    li a0, 0                                        # a0: exit code
    li a7, 93                                       # a7: exit syscall
    ecall                                           # Execute syscall.
