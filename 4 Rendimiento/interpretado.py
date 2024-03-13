import time

def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)

n = 20
start = time.time()
result = factorial(n)
end = time.time()
cpu_time_used = end - start

print("El factorial de", n, "es", result)
print("Tiempo de CPU utilizado:", cpu_time_used, "segundos")

