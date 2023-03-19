#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

bool checkm(string& mother, int j)
{
    for (int i = j; i < mother.size(); ++i)
    {
        if ((mother[i] < 'a' || mother[i] > 'z') &&
            (mother[i] < 'A' || mother[i] > 'Z') &&
            (mother[i] < '0' || mother[i] > '9'))
            return false; 
    }
    return true;
}

bool myfunc(string& son, string& mother, int i, int j)
{
    while (i < son.size() && j < mother.size())
    {
        if (son[i] == '*')
        {
            while (i < son.size() && son[i] == '*')
            {
                ++i;
            }
            string substr;
            int copy_i = i;
            while (copy_i < son.size() &&
                (son[copy_i] >= 'a' && son[copy_i] <= 'z') ||
                (son[copy_i] >= 'A' && son[copy_i] <= 'Z') ||
                (son[copy_i] >= '0' && son[copy_i] <= '9') )
            {
                substr.push_back(son[copy_i]);
                ++copy_i;
            }
            //size_t sub_size = substr.size();
            vector<int> pos;
            for (int z = j; z < mother.size();)
            {
                int p = mother.find(substr, z);
                if (p != string::npos && !substr.empty())
                {
                    pos.push_back(p);
                    z += substr.size();
                }
                else if (p == string::npos && pos.empty())
                {
                    return false;
                }
                else if (p != string::npos && substr.empty())
                {
                    //p = mother.find(son[i], z);
                    //pos.push_back(p);
                    //break;
                    
                    if (i >= son.size())
                    {
                        return checkm(mother, j);
                    }
                    else
                    {
                        if (son[i] != '?')
                        {
                            substr.push_back(son[i]);
                            continue;
                        }
                        else
                        {
                            int copy_j = j;
                            for (; copy_j < mother.size(); ++copy_j)
                            {
                                pos.push_back(copy_j);
                            }
                            break;
                        }
                        
                    }
                     
                }
                else
                {
                    break;
                }
            }

            for (int z = 0; z < pos.size(); ++z)
            {
                if (myfunc(son, mother, i, pos[z]) == true)
                    return true;
            }
            
        }

        else if (son[i] == '?')
        {
            if ((mother[j] < 'a' || mother[j] > 'z') && (mother[j] < 'A' || mother[j] > 'Z') && (mother[j] < '0' || mother[j] > '9') )
                return false;
            ++j;
            ++i;
        }

        else
        {
            if (son[i] == mother[j])
            {
                ++j;
                ++i;
            }
            else
            {
                return false;
            }
        }

    }

    if (i == son.size() && j == mother.size())
        return true;
    else
        return false;

}

int main()
{
    string son;
    string mother;
    getline(cin, son);
    getline(cin, mother);
    int b = 1;
    for (int i = 0; i < son.size(); ++i)
    {
        son[i] = toupper(son[i]);
    }
    for (int i = 0; i < mother.size(); ++i)
    {
        mother[i] = toupper(mother[i]);
        /*if ((mother[i] < 'a' || mother[i] > 'z') && (mother[i] < 'A' || mother[i] > 'Z') && (mother[i] < '0' || mother[i] > '9'))
            b = 0;*/

    }

    if (myfunc(son, mother, 0, 0))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }


    return 0;
}