#include <iostream>
#include <vector>
#include <string>

using ulong = unsigned long long;

std::vector<ulong> factor(ulong n)
{
    std::vector<ulong> nums={};

    auto add =[&nums] (ulong number){
        if (std::find(nums.begin(), nums.end(),number)==nums.end()){
            nums.push_back(number);
        }
    };

    while (n % 2 == 0){
        add(2);
        n = n/2;
    }

    for (ulong i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            add(i);
            n = n/i;
        }
    }

    if (n > 2)
        add(n);

    return nums;
}

ulong modPow(ulong a, ulong b, ulong p){
    ulong ans=1;
    for(ulong i=0;i<b;i++){
        ans = (ans*a)%p;
    }
    return ans;
}

bool isPrimitive(ulong primitiveRoot,ulong prime){
    if(primitiveRoot > prime)
        return false;

    ulong phi = prime-1;
    for(auto i: factor(phi)){
        if(modPow(primitiveRoot,phi/i,prime)==1)
            return false;
    }
    return true;
}


ulong getMirror(ulong i,ulong primitiveRoot,ulong prime){
    return modPow(primitiveRoot,i,prime);
}

int main()
{
    //check number is primitive or not
    auto checkArticleNumbers = [](ulong b,ulong p){
        std::string status="";
        if(!isPrimitive(b,p))
            status = "NOT ";
        std::cout << b <<" for "<< p<< " is " << status <<"primitive" << std::endl;
    };

    checkArticleNumbers(2,5);
    checkArticleNumbers(2,7);
    checkArticleNumbers(3,7);
    checkArticleNumbers(2,13);
    checkArticleNumbers(3,13);
    checkArticleNumbers(2,23);
    checkArticleNumbers(3,23);
    checkArticleNumbers(5,23);

    std::cout << "\n\n";


    //print reorder of prime
    auto printReorder = [](ulong b,ulong p){
        std::cout << p<<","<<b << " : ";
        for(ulong i=0;i<p;i++){
            std::cout <<getMirror(i,b,p)<< " ";
        }
        std::cout << std::endl;
    };

    printReorder(2,5);
    printReorder(2,7);
    printReorder(3,7);
    printReorder(2,13);
    printReorder(3,13);
    printReorder(2,23);
    printReorder(3,23);
    printReorder(5,23);

    std::cout << "\n\n";

    return 0;
}
