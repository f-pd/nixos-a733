#!/usr/bin/env python3
# send lines to the board's UART (the logger keeps reading), print what came back
import sys, time, os
log, wait = sys.argv[1], float(sys.argv[2])
n = sum(1 for _ in open(log, 'rb'))
fd = os.open(os.environ.get('UART_DEV', '/dev/ttyUSB0'), os.O_WRONLY | os.O_NOCTTY)
for c in sys.argv[3:]:
    os.write(fd, c.encode() + b'\r'); time.sleep(wait)
os.close(fd)
sys.stdout.buffer.write(b''.join(list(open(log, 'rb'))[n:]))
