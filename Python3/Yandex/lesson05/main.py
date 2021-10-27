def make_prefix_sum(nums):
    prefix_sum = [0] * (len(nums) + 1)
    for i in range(1, len(nums) + 1):
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
    return prefix_sum


def rsq(prefix_sum, l_index, r_index):
    return prefix_sum[r_index] - prefix_sum[l_index]


def make_prefix_zeroes(nums):
    prefix_zeroes = [0] * (len(nums) + 1)
    for i in range(1, len(nums) + 1):
        if nums[i - 1] == 0:
            prefix_zeroes[i] = prefix_zeroes[i - 1] + 1
        else:
            prefix_zeroes[i] = prefix_zeroes[i - 1]
    return prefix_zeroes


def count_zeroes(prefix_zeroes, l_index, r_index):
    return prefix_zeroes[r_index] - prefix_zeroes[l_index]


def count_zero_sum_ranges_3(nums):
    cnt_ranges = 0
    for i in range(len(nums)):
        for j in range(i + 1, len(nums) + 1):
            range_sum = 0
            for k in range(i, j):
                range_sum += nums[k]
            if range_sum == 0:
                cnt_ranges += 1
    return cnt_ranges


def count_zero_sum_ranges_2(nums):
    cnt_ranges = 0
    for i in range(len(nums)):
        range_sum = 0
        for j in range(i, len(nums)):
            range_sum += nums[j]
            if range_sum == 0:
                cnt_ranges += 1
    return cnt_ranges


def count_prefix_sums(nums):
    prefix_sum_by_value = {0: 1}
    nowsum = 0
    for now in nums:
        nowsum += now
        if nowsum not in prefix_sum_by_value:
            prefix_sum_by_value[nowsum] = 0
        prefix_sum_by_value[nowsum] += 1
    return prefix_sum_by_value


def count_zero_sum_ranges(prefix_sum_by_value):
    cnt_ranges = 0
    for nowsum in prefix_sum_by_value:
        cntsum = prefix_sum_by_value[nowsum]
        cnt_ranges += cntsum * (cntsum - 1) // 2
    return cnt_ranges


# Дана отсортированная последовательность чисел длиной N и число K
# Необходимо найти количество пар чисел A, B, таких что B - A > K

def cnt_pairs_with_diff_gtk_2(sorted_nums, k):
    cnt_pairs = 0
    for first in range(len(sorted_nums)):
        for last in range(first, len(sorted_nums)):
            if sorted_nums[last] - sorted_nums[first] > k:
                cnt_pairs += 1
    return cnt_pairs


def cnt_pairs_with_diff_gtk(sorted_nums, k):
    cnt_pairs = 0
    last = 0
    for first in range(len(sorted_nums)):
        while last < len(sorted_nums) and sorted_nums[last] - sorted_nums[first] <= k:
            last += 1
        cnt_pairs += len(sorted_nums) - last
    return cnt_pairs


def best_team_sum(players):
    bestsum = 0
    nowsum = 0
    last = 0
    for first in range(len(players)):
        while last < len(players) and (last == first or players[first] + players[first + 1] >= players[last]):
            nowsum += players[last]
            last += 1
        bestsum = max(bestsum, nowsum)
        nowsum -= players[first]
    return bestsum


def merge_bad(nums1, nums2):
    merged = [0] * (len(nums1) + len(nums2))
    first1 = first2 = 0
    inf = max(nums1[-1], nums2[-1]) + 1
    nums1.append(inf)
    nums2.append(inf)
    for k in range(len(nums1) + len(nums2) - 2):
        if nums1[first1] <= nums2[first2]:
            merged[k] = nums1[first1]
            first1 += 1
        else:
            merged[k] = nums2[first2]
            first2 += 1
    nums1.pop()
    nums2.pop()
    return merged


def merge(nums1, nums2):
    merged = [0] * (len(nums1) + len(nums2))
    first1 = first2 = 0
    for k in range(len(nums1) + len(nums2)):
        if first1 != len(nums1) and (first2 == len(nums2) or nums1[first1 < nums2[first2]]):
            merged[k] = nums1[first1]
            first1 += 1
        else:
            merged[k] = nums2[first2]
            first2 += 1
    return merged
