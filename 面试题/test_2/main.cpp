/*
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/

class Solution {
public:
    class Sum 
    {
    public:
        Sum()
        {
            s_count++;
            s_sum += s_count;
        }
        
        static int GetSum()
        {
            return s_sum;
        }
        
        static void ReSetSum()
        {
            s_sum = 0;
            s_count = 0;
        }
    private:
        static int s_count;
        static int s_sum;
    };
    
    int Sum_Solution(int n) {
        Sum::ReSetSum();
        Sum *ps = new Sum[n];
        delete[] ps;
        return Sum::GetSum();
    }
};

int Solution::Sum::s_count = 0;
int Solution::Sum::s_sum = 0;