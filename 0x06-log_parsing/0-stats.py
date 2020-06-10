#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics:
For every 10 lines:
  - print the status number with the number of times it
    appears
  - print the sum of the file sizes
"""

if __name__ == "__main__":
    from sys import stdin
    import signal

    status_codes = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }
    sorted_keys = sorted(status_codes.keys())
    i = total_size = 0

    def print_status(status_codes, total_size):
        print('File size: {}'.format(total_size))
        for key in sorted_keys:
            if status_codes[key] == 0:
                continue
            print('{}: {}'.format(key, status_codes[key]))

    try:
        for line in stdin:
            i += 1
            split_line = line.split(" ")
            try:
                status = split_line[-2]
                total_size += int(split_line[-1])

                if status in status_codes:
                    status_codes[status] += 1
            except Exception:
                pass
            if i % 10 == 0:
                print_status(status_codes, total_size)

        else:
            print_status(status_codes, total_size)

    except (KeyboardInterrupt, SystemExit):
        print_status(status_codes, total_size)
        raise
