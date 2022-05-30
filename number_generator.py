import random

p = random.sample(range(1, 101), 100)
for i in p:
    open(f"numgen.txt", "a+", encoding="utf-8", errors="ignore").write(f"{i} ")