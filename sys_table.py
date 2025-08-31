# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sys_table.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 20:28:35 by wirare            #+#    #+#              #
#    Updated: 2025/08/31 21:51:12 by ellanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import re
import json
def syscall_table_maker(path, func_name):
    print(f"char* __attribute__((const)) {func_name}(long long syscall_number)")
    print(f"{{\n\tstatic char table[] = {{")
    with open(path) as file:
        line = file.readline()
        while line != "" :
            x = re.search("([0-9]+)\t([A-Za-z_0-9]+)", line)
            if x :
                syscall_number = x.group(1)
                syscall_name = x.group(2)
                print(f'\t\t[{syscall_number}] = "{syscall_name}",')
            line = file.readline()
    print(f"\t}};\n\treturn table[syscall_number];\n}}")

def get_type(decl):
    split_decl = decl.split(' ')
    to_add = ""
    if split_decl[-1] and split_decl[-1][0] == "*":
        to_add = "_PTR"
    if len(split_decl) > 1 : split_decl.pop()
    type = '_'.join(split_decl) + to_add
    type = type.replace("*", "PTR_")
    type = type.replace("__", "_")
    type = type.replace("?", "XXX")
    return type
    

def get_syscall_types_info(path):
    types = set()
    with open(path) as file:
        syscall_info = json.loads(file.read())
        for syscall in syscall_info:
            for i in range(6):
                type = get_type(syscall[f"arg{i}"]).upper()
                types.add(type)
    for t in types:
        print(f"\tSAT_{t},")

def make_arg_str(syscall):
    args = ""
    for i in range(6):
        if syscall[f"arg{i}"] == "" : break
        type = f" .arg{i} = SAT_" + get_type(syscall[f"arg{i}"]).upper() + ","
        args += type
    return args[:-1]

def make_syscall_info_table(path, func_name):
    print(f"t_syscall_info __attribute__((const)) {func_name}(u64 syscall_number)")
    print(f"{{\n\tstatic const t_syscall_info info_table[] = {{")
    with open(path) as file:
        syscall_info = json.loads(file.read())
        for syscall in syscall_info:
            print(f"\t\t[SYS_{syscall['name']}] = MAKE_SYS_INFO_STRUCT('{syscall['name']}',{make_arg_str(syscall)}),")
    print(f"\t}};\n\treturn info_table[syscall_number];\n}}")

def make_printer_list(enum, x):
    enums = enum.split(',')
    if x == 0:
        for e in enums:
            print(f"\t\tDEFINE_PRINTER({e.strip()})")
    else:
        for e in enums:
            print(f"DECLARE_PRINTER({e.strip()})")

make_printer_list("SAT_CONST_STRUCT_TIMESPEC_PTR,\
	SAT_STRUCT_RSEQ_PTR,\
	SAT_STRUCT_IO_URING_PARAMS_PTR,\
	SAT_STRUCT_CLONE_ARGS_PTR,\
	SAT_STRUCT_OPEN_HOW_PTR,\
	SAT_STRUCT_IOVEC_PTR,\
	SAT_STRUCT_MOUNT_ATTR_PTR,\
	SAT_STRUCT_DQBLK_PTR,\
	SAT_CONST_STRUCT_LANDLOCK_RULESET_ATTR_PTR,\
	SAT_STRUCT_FUTEX_WAITV_PTR,\
	SAT_CACHESTAT_RANGE__USER_PTR,\
	SAT_CACHESTAT__USER_PTR,\
	SAT_UNSIGNED_LONG,\
	SAT_STRUCT_SIGEVENT_PTR,", 1)
make_printer_list("SAT_CONST_STRUCT_TIMESPEC_PTR,\
	SAT_STRUCT_RSEQ_PTR,\
	SAT_STRUCT_IO_URING_PARAMS_PTR,\
	SAT_STRUCT_CLONE_ARGS_PTR,\
	SAT_STRUCT_OPEN_HOW_PTR,\
	SAT_STRUCT_IOVEC_PTR,\
	SAT_STRUCT_MOUNT_ATTR_PTR,\
	SAT_STRUCT_DQBLK_PTR,\
	SAT_CONST_STRUCT_LANDLOCK_RULESET_ATTR_PTR,\
	SAT_STRUCT_FUTEX_WAITV_PTR,\
	SAT_CACHESTAT_RANGE__USER_PTR,\
	SAT_CACHESTAT__USER_PTR,\
	SAT_UNSIGNED_LONG,\
	SAT_STRUCT_SIGEVENT_PTR,", 0)
