import os
import sys

pid = os.fork()

if pid < 0:
    raise Exception("Fork failed")
elif pid == 0:
    os.execl("/bin/ls", "ls", "-l")
    sys.stderr.write("Exec failed\n")
    sys.exit(1)
else:
    os.waitpid(pid, 0)
    print("Child process completed")