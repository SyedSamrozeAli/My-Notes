DSA<interval> sorted = sort(arr);
DSA<int> conflicts(arr.length());
for (int i = 0; i < arr.length(); i++)
{
    int c = 0;
    for (int j = 0; j < arr.length(); j++)
    {
        if (i == j)
            continue;
        if (sorted[i].first > sorted[j].first && sorted[i].second <= sorted[j].second)
        {
            c++;
        }
        else if (sorted[i].first < sorted[j].first && sorted[i].second >= second[j].second)
        {
            c++;
        }
    }
    conflicts[sorted[i].index] = c;
}
return conflicts;
