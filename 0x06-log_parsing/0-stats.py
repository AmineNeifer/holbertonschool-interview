#!/usr/bin/python3

""" function that parse a stdin conating headers"""
import sys
s_codes = {'200': 0, '301': 0, '400': 0, '401': 0,
           '403': 0, '404': 0, '405': 0, '500': 0}
try:
    i = 0
    file_size = 0
    for line in sys.stdin:
        try:
            file_size += int(line.split(" ")[-1].split('\n')[0])
        except ValueError:
            file_size += int(line.split(" ")[-2].split('\n')[0])
        i += 1
        code = line.split(" ")[7]
        if code in s_codes.keys():
            s_codes[code] += 1
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for k in sorted(s_codes.keys()):
                v = s_codes[k]
                if v != 0:
                    print("{}: {}".format(k, v))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(file_size))
    for k in sorted(s_codes.keys()):
        v = s_codes[k]
        if v != 0:
            print("{}: {}".format(k, v))
