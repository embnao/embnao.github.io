	.file	"other3.c"
	.text
	.section	.rodata
.LC2:
	.string	"n:%d\n"
.LC3:
	.string	"c:%d, d:%d\n"
.LC4:
	.string	"yes\n"
.LC5:
	.string	"no\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -16(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movl	$1, -8(%rbp)
	movl	$2, -4(%rbp)
	cvtsi2ss	-8(%rbp), %xmm0
	addss	-16(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$44, -20(%rbp)
	movb	$-1, -19(%rbp)
	movzbl	-19(%rbp), %edx
	movzbl	-20(%rbp), %eax
	addl	%edx, %eax
	movb	%al, -18(%rbp)
	movzbl	-19(%rbp), %edx
	movzbl	-20(%rbp), %eax
	addl	%edx, %eax
	movb	%al, -17(%rbp)
	movsbl	-17(%rbp), %edx
	movzbl	-18(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$-20, -19(%rbp)
	movb	$0, -20(%rbp)
	movsbl	-19(%rbp), %edx
	movzbl	-20(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L2
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1072902963
	.align 4
.LC1:
	.long	1074161254
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
