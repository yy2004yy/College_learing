def binary_to_decimal_longest_prefix(binary_forwarding_table):
    decimal_forwarding_table = []
    for entry in binary_forwarding_table:
        binary_prefix, _, output = entry
        if binary_prefix == "Otherwise":
            decimal_entry = (-1, output)
        else:
            decimal_prefix = int(binary_prefix, 2)
            decimal_entry = (decimal_prefix, output)
        decimal_forwarding_table.append(decimal_entry)

    # 寻找最长前缀匹配
    longest_prefix_table = []
    for prefix, output in decimal_forwarding_table:
        longest_prefix = prefix
        for other_prefix, other_output in decimal_forwarding_table:
            if prefix != other_prefix and str(other_prefix).startswith(str(prefix)) and len(str(other_prefix)) > len(str(longest_prefix)):
                longest_prefix = other_prefix
                output = other_output
        longest_prefix_table.append((longest_prefix, output))

    return longest_prefix_table

binary_forwarding_table = [
    ("11100000", "00", "0"),
    ("11100000", "01000000", "1"),
    ("1110000", "", "2"),
    ("11100001", "1", "3"),
    ("Otherwise", "", "3")
]

a=binary_to_decimal_longest_prefix(binary_forwarding_table)
print(a)