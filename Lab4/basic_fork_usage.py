import os

pid = os.fork()

if pid < 0:
    raise Exception("Fork failed")
elif pid == 0:
    print("Child process with PID:", os.getpid())
else:
    print("Parent process with PID:", os.getpid(), "child PID:", pid)