#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    string input;
    while(cin >> n)
    {
        cin >> input;
        int ans = 0, tmp_sum = 0, len = 0;

        //�j�p�g�ϧO 0->start 1-> �p 2->�j
        int flag = 0;
        for(int i = 0; i < input.size(); i++)
        {
            /*start �����D�j�p�g ��flag*/
            if(flag == 0)
            {
                if(input[i] >= 'a' && input[i] <= 'z')
                    flag = 1;
                else
                    flag = 2;
            }

            /*�p�g*/
            if(input[i] >= 'a' && input[i] <= 'z')
            {
                if(flag == 1)
                {
                    int k = 0;
                    for(int j = i; k < n; k++, j++)
                    {
                        if(!(input[j] >= 'a' && input[j] <= 'z'))
                            break;

                    }
                    /*�p�G���\ i = i + n - 1*/
                    /*���� flag = 0*/
                    if(k == n)
                    {
                        len = len + n;
                        i = i + n - 1;
                    }
                    else
                    {
                        flag = 0;
                        if(tmp_sum > ans)
                            ans = tmp_sum;

                        tmp_sum = 0;
                    }
                }
                else
                {
                    i = i - n;
                    flag = 0;
                    if(tmp_sum > ans)
                        ans = tmp_sum;

                    tmp_sum = 0;

                }

            }
            /*�j�g*/
            else if(input[i] >= 'A' && input[i] <= 'Z')
            {
                if(flag == 2)
                {
                    int k = 0;
                    for(int j = i; k < n; k++, j++)
                    {
                        if(!(input[j] >= 'A' && input[j] <= 'Z'))
                            break;

                    }
                    if(k == n)
                    {
                        len = len + n;
                        i = i + n - 1;
                    }
                    else
                    {
                        flag = 0;
                        if(tmp_sum > ans)
                            ans = tmp_sum;

                        tmp_sum = 0;
                    }
                }
                else
                {
                    i = i - n;
                    flag = 0;
                    if(tmp_sum > ans)
                        ans = tmp_sum;
                    tmp_sum = 0;

                }
            }
            if(len == n)
            {
                if(flag == 1)
                {
                    flag = 2;
                    tmp_sum = tmp_sum + len;
                    len = 0;
                }
                else
                {
                    flag = 1;
                    tmp_sum = tmp_sum + len;
                    len = 0;
                }
            }


        }
        cout << ans << endl;
    }
}

