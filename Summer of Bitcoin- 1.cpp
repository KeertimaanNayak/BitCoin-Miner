#include<bits/stdc++.h>
using namespace std;

string input = "short mempool - mempool.csv";

int totalBlockWeight = 12000; 

struct TransactionInfo   
{
    int fee;
    int weight;
    string tx_id;
    vector<string> parents;
};

pair<string, TransactionInfo*> initiateTransaction(vector<string>& row)    
{
    vector<string> p;
    auto ans = new TransactionInfo();
    
    ans -> tx_id = row[0];
    ans -> fee = stoi(row[1]);
    ans -> weight = stoi(row[2]);
    
    for (int i = 3; i < row.size(); i++)
        p.push_back(row[i]);
    ans -> parents = p;

    return {row[0], ans};
}

void readinput(string input, unordered_map<string, TransactionInfo*>& ump)    
{   
    ifstream fin(input, ios::in);

    vector<string> row;
    string word;
    string line;
    string temp;
            
    getline(fin, line);
    
    while(getline(fin, line))
    {   
        row.clear();
        stringstream s(line);
        while(getline(s, word, ','))
            row.push_back(word);
        
        pair<string, TransactionInfo*> p = initiateTransaction(row);
        ump[p.first] = p.second;
    }

    fin.close();

    cout<<"Transaction Count :" << ump.size() << "\n";
}

void writeOutput(vector<string>& included_tx_vector, string fn)   
{
    ofstream myfile(fn);
    for(auto s : included_tx_vector)
        myfile << s << "\n";
    myfile.close();
}

int main()
{  
    unordered_map<string, TransactionInfo*> ump;
    readinput(input, ump);
    
    //Here I am using the technique of bitmasking to get the maximum profit.
    int sz=0;
    map<string, int> indexmp;
    map<int, string> idmp;
    for(auto x: ump){
        indexmp[x.first] = sz;
        idmp[sz] = x.first;
        sz++; 
    }

    vector<string> included_tx_vector;
    int totalFee = 0, finalBlockWeight = 0, totalTransactions = 0;
    for(int mask = 0; mask < ( 1 << sz ); mask++)
    {
        bool flag = 0;
        int currBlockWeight = 0, sumfee = 0;
        
        for(int j = 0; j < sz; j++)
        {
            if(mask & ( 1 << j ))
            {
                for(auto x: ump[idmp[j]] -> parents)
                {
                    if(!(mask & (1 << indexmp[x])))
                    {
                        flag=1; break;
                    }
                }
                if(flag == 1)
                    break;

                if(currBlockWeight + (ump[idmp[j]]->weight) > totalBlockWeight)
                {
                    flag = 1; break;
                }

                sumfee += ump[idmp[j]] -> fee;
                currBlockWeight += ump[idmp[j]] -> weight;
            }
        }

        if(flag == 1)
            continue;

        if(totalFee < sumfee)
        {
            totalFee = sumfee;
            finalBlockWeight = currBlockWeight;
            totalTransactions = 0;
            included_tx_vector.clear();

            for(int j = 0; j < sz; j++)
            {
                if(mask & ( 1 << j ))
                {
                    totalTransactions++;
                    included_tx_vector.push_back(idmp[j]);
                }
            }
        }
    }

    cout<<"Total Fees in Current Block : "<< totalFee << "\nTotal Weight : " << finalBlockWeight << "\n";
    cout<<"Transactions in Final Block : " << totalTransactions << "\n";
    writeOutput(included_tx_vector, "output1.txt");

    return 0;
}




