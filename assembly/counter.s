.data
countup:
    .word   0
countdown:
    .word   10

.text
.global main
main:
    lw      t0, countup
    lw      t1, countdown
loop:
    addi    t0, t0, 1
    addi    t1, t1, -1
    sw      t0, countup
    bnez    t1, loop
exit:
    li      a0, 0
    li      a7, 93
    ecall
