# Память родительского и дочернего процесса

import os
import time

foo = "bar"

if os.fork() == 0:
    # дочерний процесс
    foo = "baz"
    print("child:", foo)
else:
    # родительский процесс
    time.sleep(2)
    print("parent:", foo)
    os.wait()
