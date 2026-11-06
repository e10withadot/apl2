	.file "test.two"
	.text
	.globl main
	.type main, @function
main:
	pushq %rbp
	movq %rsp, %rbp
	movl $2, -4(%rbp)
	movl $0, %eax
	popq %rbp
	ret
