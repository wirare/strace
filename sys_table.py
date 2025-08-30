# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sys_table.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wirare <wirare@42angouleme.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 20:28:35 by wirare            #+#    #+#              #
#    Updated: 2025/08/30 21:03:30 by wirare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import re
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

syscall_table_maker("x64_table", "resolve_x64_syscall_num")
