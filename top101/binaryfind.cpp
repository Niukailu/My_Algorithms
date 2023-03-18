#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1]) right = mid;
        else left = mid + 1; 
    }
    return left;
}

int tmp[1000010] = {0};
long long merge(vector<int>& data, int left, int mid, int right) {
    long long res = 0;
    int k = 0, lend = mid, rend = right;
    while (lend >= left && rend > mid)
    {
        if(data[lend] > data[rend]) {
            res += (rend - mid);
            tmp[k++] = data[lend--];
        }
        else {
            tmp[k++] = data[rend--];
        }
    }
    while(lend >= left) tmp[k++] = data[lend--];
    while(rend > mid) tmp[k++] = data[rend--];
    for (int i = left; i <= right; i++)
    {
        data[i] = tmp[--k];
    }
    return res;
}
long long merge_sort(vector<int>& data, int begin, int end) {
    if(begin >= end) return 0;
    long long ret = 0;
    int mid = begin + (end - begin) / 2;
    ret += merge_sort(data, begin, mid);
    ret += merge_sort(data, mid + 1, end);
    return ret + merge(data, begin, mid, end);
}
int mod = 1e9 + 7;
int InversePairs(vector<int> data) { //逆序对
    return merge_sort(data, 0, data.size() - 1) % mod;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    int left = 0, right = rotateArray.size() - 1;
    int mid = -1;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if(rotateArray[mid] > rotateArray[right]) left = mid + 1;
        else if(rotateArray[mid] < rotateArray[right]) right = mid;
        else right = right - 1;
    }
    return left;
}

int compare(string version1, string version2) {
    int len1 = version1.length(), len2 = version2.length();
    int i = 0, j = 0;
    int num1 = 0, num2 = 0;
    while (i < len1 || j < len2)
    {
        num1 = 0;
        while(i < len1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            ++i;
        }
        ++i;
        num2 = 0;
        while(j < len2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            ++j;
        }
        ++j;
        if(num1 > num2) return 1;
        else if(num1 < num2) return -1;
    }
    return 0;
}




int main() {



    return 0;
}