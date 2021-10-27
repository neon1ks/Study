# Бинарный поиск для [li; ri] включительно!
def lbinsearch(li, ri, check, check_param):
    while li < ri:
        mi = (li + ri) // 2
        if check(mi, check_param):
            ri = mi
        else:
            li = mi + 1
    return li


def rbinsearch(li, ri, check, check_param):
    while li < ri:
        mi = (li + ri + 1) // 2
        if check(mi, check_param):
            li = mi
        else:
            ri = mi - 1
    return li


def checck_endownment(m, params):
    n, k = params
    return (k + m) * 3 >= n + m


def check_problem_count(days, params):
    n, k = params
    return (k + (k + days - 1)) * days // 2 >= n


def check_stickers(size, params):
    n, w, h = params
    return (w // size) * (h // size) >= n


# Задача 4
def check_is_ge(index, params):
    seq, x = params
    return seq[index] >= x


def find_first_ge(seq, x):
    ans = lbinsearch(0, len(seq) - 1, check_is_ge, (seq, x))
    if seq[ans] < x:
        return len(seq)
    return ans


# Задача 5
def check_is_gt(index, params):
    seq, x = params
    return seq[index] > x


def find_first(seq, x, check):
    ans = lbinsearch(0, len(seq) - 1, check, (seq, x))
    if not check(ans, (seq, x)):
        return len(seq)
    return ans


def count_x(seq, x):
    index_gt = find_first(seq, x, check_is_gt)
    index_ge = find_first(seq, x, check_is_ge)
    print("index_gt = ", index_gt)
    print("index_ge = ", index_ge)
    return index_gt - index_ge


# Задача 6
def check_month_lyperc(mperc, yperc):
    msum = 1 + mperc / 100
    ysum = 1 + yperc / 100
    return msum ** 12 >= ysum


def f_bin_search(li, ri, eps, check, check_params):
    while li + eps < ri:
        mi = (li + ri) / 2
        if check(mi, check_params):
            ri = mi
        else:
            li = mi
    return li


def check_credit(mpay, params):
    periods, creditsum, mperc = params
    for i in range(periods):
        percpay = creditsum * (mperc / 100)
        creditsum -= mpay - percpay
    return creditsum <= 0


def dist(t, params):
    x, v = params
    minpos = maxpos = x[0] + v[0] * t
    for i in range(1, len(x)):
        nowpos = x[i] + v[i] * t
        minpos = min(minpos, nowpos)
        maxpos = max(maxpos, nowpos)
    val = maxpos - minpos
    return val


def checkasc(t, eps, params):
    return dist(t + eps, params) >= dist(t, params)


a = [1, 2, 3, 4, 5, 5, 5, 5, 5, 6]
res = count_x(a, 5)
print("res =", res)

x_in = 12
eps_in = 0.0001
mperc_res = f_bin_search(0, x_in, eps_in, check_month_lyperc, 4)
print("mperc =", mperc_res)

m_in = 10000000
n_in = 300
monthly_pay = f_bin_search(0, m_in, eps_in, check_credit, (n_in, m_in, mperc_res))
print("monthly_pay =", monthly_pay)
