m = int(1000000007)


def fastexpomod(a, p, m):
    r = 1
    a = a % m
    while p > 0:
        if p & 1 == 1:
            r = (r * a) % m
        p = p >> 1
        a = (a * a) % m

    return r


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def main():
    global m
    t = int(input())
    val = 0
    while(t > 0):
        a, b, n = map(int, input().split())
        diff = abs(a - b)
        if diff == 0:
            sum = fastexpomod(a, n, m) + fastexpomod(b, n, m)
            val = sum % m
        else:
            sum = fastexpomod(a, n, diff) + fastexpomod(b, n, diff)
            val = gcd(sum, diff)
        print(val)
        t = t - 1


if __name__ == '__main__':
    main()
