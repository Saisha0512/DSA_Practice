class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        for(int i=0;i<score.size();i++)
        {
            int maxi=score[i][k];
            int maxind=i;
            for(int j=i+1;j<score.size();j++)
            {
                if(maxi<score[j][k])
                {
                    maxi=score[j][k];
                    maxind=j;
                }
            }
            if(maxi!=score[i][k])
            {
                swap(score[i],score[maxind]);
            }
        }
        return score;
    }
};