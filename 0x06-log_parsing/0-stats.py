#!/usr/bin/env python3

""" function that parse a stdin conating headers"""
import sys
s_codes = {'200': 0, '301': 0, '400': 0, '401': 0,
           '403': 0, '404': 0, '405': 0, '500': 0}
try:
    i = 0
    file_size = 0
    for line in sys.stdin:
        file_size += int(line.split(" ")[-1].split('\n')[0])
        i += 1
        code = line.split(" ")[7]
        s_codes[code] += 1
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for k, v in s_codes.items():
                if v != 0:
                    print("{}: {}".format(k, v))
except (KeyboardInterrupt, SystemExit):
    print("File size: {}".format(file_size))
    for k, v in s_codes.items():
        if v != 0:
            print("{}: {}".format(k, v))
