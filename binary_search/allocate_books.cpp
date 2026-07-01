/*
    Problem :Given an array ‘nums of integer numbers, ‘nums[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students..

    Allocate books in such a way that:

    Each student gets at least one book.
    Each book should be allocated to only one student.
    Book allocation should be in a contiguous manner.
    You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
    If the allocation of books is not possible. return -1

    Example :

                Input Format: n = 4, m = 2, nums[] = {12, 34, 67, 90}
                
                Output: 113

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    int countStudents(const vector<int>& nums,int pages)
    {
        int students = 1, pageCount= 0;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(pageCount + nums[i] <= pages) pageCount += nums[i];
            else 
            {
                students += 1;
                pageCount = nums[i];
            }
        }
        return students;
    }
    int allocate_books(const vector<int>& nums,int students)
    {
        int n = nums.size();
        if(students > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(countStudents(nums,mid) > students) low = mid  + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int students;
    cin >> students;
    MagicalStuff magic;
    int pages = magic.allocate_books(nums,students);
    cout <<"Pages : " << pages; 
}

/*
    Approaches :

        1. Linear Iterative Approach O((sum - max_element + 1) * n) | O(1)
        2. Binary Search O(log (sum - max_element + 1) * n) | O(1)

    Complexity Analysis

    Time :  O(log (sum - max_element + 1) * n)
    Space : O(1)
*/