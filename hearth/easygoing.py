def main():
    t = int(input())
    while t >= 0:
        N, M = list(map(int, input().split()))
        L = list(map(int, input().split()))
        maxValue = 0
        minValue = 0
        L.sort()
        for i in L[N - (N - M):]:
            # print(i)
            maxValue += i
        for j in L[0:N - M]:
            # print(j)
            minValue += j
        print(maxValue - minValue)
        t -= 1


if __name__ == '__main__':
    main()
