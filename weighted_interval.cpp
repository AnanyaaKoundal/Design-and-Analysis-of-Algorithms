#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int start, finish, weight;
};
bool jobComparator(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int getMax(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[max])
            max = i;
    }
    return max;
}
void weightedSchedule(Job arr[], int n)
{
    int wtarr[n];
    for (int i = 0; i < n; i++)
    {
        wtarr[i] = arr[i].weight;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].finish <= arr[j].start)
                wtarr[i] += wtarr[j];
        }
    }
    int maxIndex = getMax(wtarr, n);
    vector<int> schedule;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].finish <= arr[maxIndex].start)
            schedule.push_back(i);
    }
    schedule.push_back(maxIndex);
    for (int i = 0; i < schedule.size(); i++)
    {
        cout << schedule[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < schedule.size(); i++)
    {

        for (int j = i + 1; j < schedule.size(); j++)
        {
            if (arr[schedule[i]].finish > arr[schedule[j]].start)
                if (arr[schedule[i]].weight >

                    arr[schedule[j]].weight)

                {
                    vector<int>::iterator it =

                        schedule.begin() + j;

                    schedule.erase(it);
                }
                else
                {
                    vector<int>::iterator it =

                        schedule.begin() + i;

                    schedule.erase(it);
                }
        }
    }
    for (int i = 0; i < schedule.size(); i++)
    {
        cout << schedule[i] << " ";
    }
    cout << "\n";
    cout << "Max weight is: " << arr[maxIndex].weight;
}
int main()
{
    int a;
    cout << "Enter number of jobs: ";
    cin >> a;
    Job arr[a];
    for (int i = 0; i < a; i++)
    {
        cout << "Start time of job " << (i + 1) << ": ";
        cin >> arr[i].start;
        cout << "Finish time of job " << (i + 1) << ": ";
        cin >> arr[i].finish;
        cout << "Weight of job " << (i + 1) << ": ";
        cin >> arr[i].weight;
    }
    sort(arr, arr + a, jobComparator);

    weightedSchedule(arr, a);
}