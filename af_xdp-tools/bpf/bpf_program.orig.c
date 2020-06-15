#include <linux/bpf.h>
#include <bpf/bpf_helper_defs.h>

#define SEC(NAME) __attribute__((section(NAME), used))

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(void *ctx) {  
    char msg[] = "Hello, BPF World!"; 
    bpf_trace_printk(msg, sizeof(msg));  
    return 0;
}

char _license[] SEC("license") = "GPL";
