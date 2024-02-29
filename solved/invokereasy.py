a, b = input().split()
a = int(a)
b = int(b)

c, d = input().split()
c = int(c)
d = int(d)

anti_c = c / (c**2 + d**2)
anti_d = -d / (c**2 + d**2)

r = (a*anti_c - b*anti_d)
i = (a*anti_d + b*anti_c)

print(r, i)