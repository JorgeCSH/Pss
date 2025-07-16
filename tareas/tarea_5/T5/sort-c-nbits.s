	.file	"sort-c-nbits.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	slli	t3,a1,2
	addi	t3,t3,-4
	add	t3,a0,t3
	bgeu	a0,t3,.L1
	mv	a6,a0
	j	.L9
.L3:
	addi	a6,a6,4
	bleu	t3,a6,.L11
.L9:
	lw	a7,0(a6)
	lw	t1,4(a6)
	or	a5,a7,t1
	beq	a5,zero,.L3
	mv	a4,t1
	mv	a5,a7
	li	a3,0
	li	a2,0
.L6:
	andi	a1,a5,1
	sub	a2,a2,a1
	andi	a1,a4,1
	sub	a3,a3,a1
	srli	a5,a5,1
	srli	a4,a4,1
	or	a1,a5,a4
	bne	a1,zero,.L6
	ble	a2,a3,.L3
	sw	t1,0(a6)
	sw	a7,4(a6)
	mv	a6,a0
	j	.L9
.L11:
	ret
.L1:
	ret
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
