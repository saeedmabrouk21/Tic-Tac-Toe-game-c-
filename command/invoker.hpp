#include <bits/stdc++.h>
#include "Icommand.hpp"
using namespace std;

class invoker
{
private:
    /* data */
public:
    invoker(/* args */);
    ~invoker();
    vector<char> excuteCommand(Icommand *com)
    {
        return com->excute();
    }
};

invoker::invoker(/* args */)
{
}

invoker::~invoker()
{
}
