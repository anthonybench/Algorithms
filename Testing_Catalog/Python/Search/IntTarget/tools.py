#==============================
# Printing Tools
# tools.py
#==============================

# print whitespace
def space(n: int):
    for i in range(n):
        print("")

# print border
def border(c: str):
    if c.lower() == 's':
        print("========")
    elif c.lower() == 'm':
        print("================")
    elif c.lower() == 'l':
        print("=====================================================")
    elif c.lower() == 'd':
        print("=====================================================")
        print("=====================================================")

