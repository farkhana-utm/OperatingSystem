import os
import time

def main():
    pid = os.fork()

    if pid < 0:
        raise Exception("Fork failed")
    elif pid == 0:
        # Child process
        print(f"Child process {os.getpid()} is running")
        time.sleep(2)
        print(f"Child process {os.getpid()} is exiting")
    else:
        # Parent process
        print(f"Parent process {os.getpid()} is waiting for child process {pid}")
        os.waitpid(pid, 0)
        print(f"Parent process {os.getpid()} resumes execution")

if __name__ == "__main__":
    main()