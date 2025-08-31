# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sys_table.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 20:28:35 by wirare            #+#    #+#              #
#    Updated: 2025/08/31 02:35:53 by wirare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import re
import json
def syscall_table_maker(path, func_name):
    print(f"const char* __attribute__((const)) {func_name}(long long syscall_number)")
    print(f"{{\n\tstatic const char table[] = {{")
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
    split_decl.pop()
    type = '_'.join(split_decl) + to_add
    type = type.replace("*", "PTR_")
    type = type.replace("__", "_")
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

get_syscall_types_info("x64_sys_info")

