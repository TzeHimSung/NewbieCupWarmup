import os
import random


def generate_random_number(min_length=9, max_length=10):
    length = random.randint(min_length, max_length)
    first_digit = str(random.randint(1, 9))
    other_digits = "".join(random.choices("0123456789", k=length - 1))
    return first_digit + other_digits


if not os.path.exists("data"):
    os.makedirs("data")

for i in range(1, 11):
    file_name = f"./data/{i}.in"
    with open(file_name, "w") as f:
        random_number = generate_random_number()
        f.write(random_number + "\n")
        print(f"{file_name} done.")

print("All done.")
