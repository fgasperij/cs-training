def parse():
    return []

def flip(A):
    if not A:
        return []

    best_l = 0
    best_r = 0
    curr_l = 0
    prev = 1 if A[0] == 0 else -1
    best_sum = prev

    for i, e in enumerate(A):
        if i == 0:
            continue

        val = 1 if v == 0 else -1
        if prev < 0:
            curr_l = i
            prev = val
        else:
            prev += val

        if prev > best_sum:
            best_l = curr_l
            best_r = i
            best_sum = prev

    return [best_l, best_r] if best_sum > 0 else []

A = parse()
flip(A)
